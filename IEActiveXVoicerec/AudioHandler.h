#pragma once
#include <string>
#include <vector>

typedef short SAMPLE;

typedef struct
{
	int					frameIndex;  /* Index into sample array. */
	int					maxFrameIndex;
	std::vector<SAMPLE>	recordedSamples;
} PaTestData;

void initializePa();
void terminatePa();
PaTestData* stopStreamPa();
void startStreamPa();
void openStreamPa();
void closeStreamPa();
