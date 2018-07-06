#include "stdafx.h"
#include "portaudio.h"
#include "AudioHandler.h"
#include <string>
#include <vector>

#define SAMPLE_RATE (8000) // Hz
#define SAMPLE_SILENCE  (0)

PaStream *stream;
PaError err;
PaTestData data;

/* This routine will be called by the PortAudio engine when audio is needed.
It may called at interrupt level on some machines so don't do anything
that could mess up the system like calling malloc() or free().
*/
static int paMainCallback(const void *inputBuffer, void *outputBuffer,
	unsigned long framesPerBuffer,
	const PaStreamCallbackTimeInfo* timeInfo,
	PaStreamCallbackFlags statusFlags,
	void *userData)
{
	PaTestData *data = (PaTestData*)userData;
	SAMPLE *rptr = (SAMPLE*)inputBuffer;
	std::vector<SAMPLE> *wptr = &data->recordedSamples;
	long framesToCalc;
	long i;
	int finished;

	(void)outputBuffer; /* Prevent unused variable warnings. */
	(void)timeInfo;
	(void)statusFlags;
	(void)userData;

	framesToCalc = framesPerBuffer;
	finished = paContinue;

	if (inputBuffer == NULL)
	{
		for (i = 0; i < framesToCalc; i++)
		{
			wptr->push_back(SAMPLE_SILENCE);
		}
	}
	else
	{
		for (i = 0; i < framesToCalc; i++)
		{
			wptr->push_back(*rptr++);
		}
	}
	return finished;
}

void initializePa() {
	err = Pa_Initialize();
	if (err != paNoError) {
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
	}
}

void terminatePa() {
	err = Pa_Terminate();
	if (err != paNoError) {
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
	}
}

void closeStreamPa() {
	err = Pa_CloseStream(stream);
	if (err != paNoError) {
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
	}
}

PaTestData* stopStreamPa() {
	err = Pa_StopStream(stream);
	if (err != paNoError) {
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
	}
	closeStreamPa();
	return &data;
}

void startStreamPa() {
	data.recordedSamples.clear();
	err = Pa_StartStream(stream);
	if (err != paNoError) {
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
	}
}

void openStreamPa() {
	err = Pa_OpenDefaultStream(&stream,
		1,          /* input channels */
		0,          /* stereo output */
		paInt16,  /* 16 bit int output */
		SAMPLE_RATE,
		256,        /* frames per buffer, i.e. the number
					of sample frames that PortAudio will
					request from the callback. Many apps
					may want to use
					paFramesPerBufferUnspecified, which
					tells PortAudio to pick the best,
					possibly changing, buffer size.*/
		paMainCallback, /* this is your callback function */
		&data); /*This is a pointer that will be passed to
				your callback*/
	if (err != paNoError) {
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
	}
}