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

program DecB64;

{$IFDEF MSWINDOWS}
{$APPTYPE CONSOLE}
{$ENDIF}

var input  : Array[0..3] of char;
var values : Array[0..3] of byte;
var mid    : Array[0..5] of byte;
var output : Array[0..2] of byte;
var c      : char;
var i      : integer;
var l      : longint;
var fileop : File of char;
var fileex : File of byte;
var pad    : integer;
var s      : String;

{$IFDEF LINUX}
const CRLF = #10;
{$ELSE}
const CRLF = #13#10;
{$ENDIF}

begin
    pad := 0;

    if System.ParamCount < 1 then begin
        System.Writeln( 'ERROR (1): No target filename to decode' + CRLF
                      + 'Usage: DecB64 inputfile [termination]' + CRLF + CRLF
                      + '    Where "inputfile" is a document encoded in base64' + CRLF
                      + '    and "termination" is the file termination for the output');
        System.ExitCode := 1;
        Exit;
    end
    else if System.ParamCount > 2 then begin
        System.Writeln( 'ERROR (2): Too many command line arguments' + CRLF
                      + 'Usage: DecB64 inputfile [termination]' + CRLF + CRLF
                      + '    Where "inputfile" is a document encoded in base64'+ CRLF
                      + '    and "termination" is the file termination for the output');
        System.ExitCode := 2;
        Exit;
    end;

    System.Assign(fileop, System.ParamStr(1));
    {$I-}
    System.Reset(fileop);
    {$I+}

    if System.IOResult <> 0 then begin
        System.Writeln( 'ERROR (3): File Not found:'#10
                      + System.ParamStr(1));
        System.ExitCode := 3;
        Exit;
    end;

    if System.ParamCount > 1 then begin
        s := System.ParamStr(2);

        if s = '.' then begin { Should this be an error? }
            s := '.out';
        end
        else if s[1] <> '.' then begin
            s := '.' + s;
        end;
    end
    else begin
        s := '.out';
    end;

    System.Assign(fileex, System.ParamStr(1) + s);
    {$I-}
    System.Rewrite(fileex);
    {$I+}

    if System.IOResult <> 0 then begin
        System.Writeln( 'ERROR (4): Output File could not be created:'#10
                      + System.ParamStr(1) + s);
        System.ExitCode := 4;
        Exit;
    end;

    while not System.Eof(fileop) do begin
        { read 3 valid chars from input file }
        i := 0;
        while (i < 4) and (not System.Eof(fileop)) do begin
            System.Read(fileop, c);

            case c of
                'A'..'Z', 'a'..'z', '0'..'9', '+', '/' : begin
                    input[i] := c;
                    i := i + 1;
                end;
                '=': begin
                    { EOStream has been reached. get number of padding chars }
                    pad := pad + 1;
                end;
            end;
        end;

        { switch chars to get byte values }
        for i := 0 to 3 do begin
            case input[i] of
                'A'..'Z': values[i] := byte(input[i]) - byte('A');
                'a'..'z': values[i] := (byte(input[i]) - byte('a')) + 26;
                '0'..'9': values[i] := (byte(input[i]) - byte('0')) + 52;
                '+'     : values[i] := 62;
                '/'     : values[i] := 63;
            end;
        end;

        { cut values and store cuttings on mid  }
        { [00010101 00010010 00111000 00101011] }
        { [010101-01 0010-1110 00-101011]       }
        mid[0] := values[0] shl 2; { convert 00XXXXXX to XXXXXX00 }
        mid[1] := values[1] shr 4; { convert 00XXXXXX to 000000XX }
        mid[2] := values[1] shl 4; { convert 00XXXXXX to XXXX0000 }
        mid[3] := values[2] shr 2; { convert 00XXXXXX to 0000XXXX }
        mid[4] := values[2] shl 6; { convert 00XXXXXX to XX000000 }
        mid[5] := values[3];       { nothing 00XXXXXX to 00XXXXXX }

        { and mid0,1 mid2,3 mid 4,5 into output }
        output[0] := mid[0] or mid[1];
        output[1] := mid[2] or mid[3];
        output[2] := mid[4] or mid[5];

        { write output }
        for i := 0 to 2 do begin
            System.Write(fileex, output[i]);
        end;
    end;

    { close input file }
    System.Close(fileop);

    { take off extra char padding '=' }
    { Don't know if this is right, but it works for me. }
    if pad > 0 then begin
       l := System.FileSize(fileex);  { # of bytes in file         }
       System.Seek(fileex, l - pad);  { Get relevant file position }
       System.Truncate(fileex);       { Cut the file here.         }
    end;

    { close output file and exit }
    System.Close(fileex);
end.
