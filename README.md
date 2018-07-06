# ie-activex-voicerec
Supports only 8kHz 16bit PCM and a default recording device.

There's a 2 methods javascript API:
  - void startRecording()
  - string stopRecording()

startRecording() - starts sampling an audio data to a memory buffer, returns nothing.

stopRecording() - stops sampling an audio data, generate a virtual wav file and converts it to base64 encoding; 

JS Example (see testBase64.html):
``` html
<button onClick="startRecording()" id="startButton" >Start Recording</button>
<button onClick="stopRecording()" id="stopButton" >Stop Recording</button>
<OBJECT width=0 height=0 CLASSID="clsid:75943fab-f874-4a9d-a482-654034ae1928" id="voicerec"></OBJECT>
<SCRIPT>
	obj = document.getElementById('voicerec');
	document.getElementById('stopButton').disabled = true;
	function startRecording() {
		var result = obj.startRecording()
		console.log("Recording started. Speak now!");
		document.getElementById('startButton').disabled = true;
		document.getElementById('stopButton').disabled = false;
	}
	function stopRecording() {
		var base64string = obj.stopRecording();
		blob = new Blob([base64string], {type: 'text/plain;charset=utf-8'});
		saveAs(blob, "voicerec_8000_16pcm.txt");
		document.getElementById('stopButton').disabled = true;
		document.getElementById('startButton').disabled = false;
	}
</SCRIPT>
```

----

Uses the portaudio lib for an audio sampling and the libsndfile for a raw to wav conversion.

http://www.portaudio.com/

http://www.mega-nerd.com/libsndfile/
