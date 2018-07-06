(********************************* LICENSE **********************************
 *  Copyright (C) 2001 David Moss                                           *
 *                                                                          *
 *  This program  is free software;  you can redistribute  it and/or modify *
 *  it under  the  terms of  the GNU General  Public License  as  published *
 *  by  the Free Software  Foundation;  either version  2.1 of the License, * 
 *  or (at your option) any later version.                                  *
 *                                                                          *
 *  This  program  is  distributed  in  the hope that it  will  be  useful, *
 *  but  WITHOUT  ANY  WARRANTY;  without  even  the  implied  warranty  of *
 *  MERCHANTABILITY   or   FITNESS  FOR  A  PARTICULAR  PURPOSE.  See   the *
 *  GNU General Public License for more details.                            *
 *                                                                          *
 *  You  should  have  received a copy of the  GNU General  Public  License *
 *  along  with  this  program;   if  not,  write  to  the   Free  Software *
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.               *
 *                                                                          *
 ****************************************************************************)

program EncB64;

{$IFDEF MSWINDOWS}
{$APPTYPE CONSOLE}
{$ENDIF}

var input  : Array[0..2] of byte;
var mid    : Array[0..5] of byte;
var values : Array[0..3] of byte;
var output : Array[0..3] of char;
var b      : byte;
var i      : integer;
var fileop : File of byte;
var fileex : File of char;
var pad    : integer;
var s      : string;
var c      : char;
var l      : integer;

{$IFDEF LINUX}
const CRLF : String = #10;
{$ELSE}
const CRLF : String = #13#10;
{$ENDIF}

begin
    pad := 0;
    l := 0;

    if System.ParamCount < 1 then begin
        System.Writeln( 'ERROR (1): No target filename to decode' + CRLF
                      + 'Usage: EndB64 inputfile [termination]' + CRLF + CRLF
                      + '    Where "inputfile" is the document to be encoded in base64' + CRLF
                      + '    and "termination" is the file termination for the output');
        System.ExitCode := 1;
        Exit;
    end
    else if System.ParamCount > 2 then begin
        System.Writeln( 'ERROR (2): Too many arguments' + CRLF
                      + 'Usage: EncB64 inputfile [termination]' + CRLF + CRLF
                      + '    Where "inputfile" is the document to be encoded in base64' + CRLF
                      + '    and "termination" is the file termination for the output');
        System.ExitCode := 2;
        Exit;
    end;

    System.Assign(fileop, System.ParamStr(1));
    {$I-}
    System.Reset(fileop);
    {$I+}

    if System.IOResult <> 0 then begin
        System.Writeln( 'ERROR (3): File Not found:' + CRLF + System.ParamStr(1));
        System.ExitCode := 3;
        Exit;
    end;

    if System.ParamCount > 1 then begin
        s := System.ParamStr(2);

        if s = '.' then begin { Should this throw an error? }
            s := '.b64';
        end
        else if s[1] <> '.' then begin
            s := '.' + s;
        end;
    end
    else begin
        s := '.b64';
    end;

    System.Assign(fileex, System.ParamStr(1) + s);
    {$I-}
    System.Rewrite(fileex);
    {$I+}

    if System.IOResult <> 0 then begin
        System.Writeln( 'ERROR (4): Output File could not be created:' + CRLF
                      + System.ParamStr(1) + s);
        System.ExitCode := 4;
        Exit;
    end;

    while not System.Eof(fileop) do begin
        { read 3 bytes from input file }
        i := 0;
        while (i < 3) and (not System.Eof(fileop)) do begin
            System.Read(fileop, b);
            input[i] := b;
            i := i + 1
        end;

        { Don't know if this is correct, but it seems to work }
        if i = 1 then begin { Couldn't get full array from file before end }
            input[1] := $00;
            input[2] := $00;
            pad := 2;
        end
        else if i = 2 then begin
            input[2] := $00;
            pad := 1;
        end;

        { [XXXXXXXX, XXXXXXXX, XXXXXXXX] }
        { [XXXXXX-XX, XXXX-XXXX, XX-XXXXXX] }
        mid[0] := input[0] shr 2;           { from XXXXXXXX to 00XXXXXX }
        mid[1] := (input[0] shl 4) and $30; { from XXXXXXXX to XXXX0000 to 00XX0000 }
        mid[2] := input[1] shr 4;           { from XXXXXXXX to 0000XXXX }
        mid[3] := (input[1] shl 2) and $3c; { from XXXXXXXX to XXXXXX00 to 00XXXX00 }
        mid[4] := input[2] shr 6;           { from XXXXXXXX to 000000XX }
        mid[5] := input[2] and $3f;         { from XXXXXXXX to 00XXXXXX }

        { [00XXXXXX, 00XXXXXX, 00XXXXXX, 00XXXXXX] }
        values[0] := mid[0];
        values[1] := mid[1] or mid[2];
        values[2] := mid[3] or mid[4];
        values[3] := mid[5];


        { switch bytes to get char values }
        for i := 0 to 3 do begin
            case values[i] of
                 0..25 : output[i] := char(byte('A') + values[i]);
                26..51 : output[i] := char(byte('a') + (values[i] - 26));
                52..61 : output[i] := char(byte('0') + (values[i] - 52));
                62     : output[i] := '+';
                63     : output[i] := '/';
            end;
        end;

        { write output }
        for i := 0 to 3 do begin
            l := l + 1;

            if l > 76 then begin
                { The base64 standard defines a line break here as \r\n }
                c := #13;
                System.Write(fileex, c);
                c := #10;
                System.Write(fileex, c);
                l := 1;
            end;

            System.Write(fileex, output[i]);
        end;
    end;

    { close input file }
    System.Close(fileop);

    { add padding to output }
    { BUG ALERT: if the lenhth of the line is 0 or 1 then the
                 padding will only eat the \r\n.
                 It will be fixed... eventually.
    }
    if pad > 0 then begin
        System.Seek(fileex, System.filePos(fileex) - pad);

        for i := 1 to pad do begin
            c := '=';
            System.Write(fileex, c);
        end;
    end;

    { close output file and exit }
    System.Close(fileex);
end.
