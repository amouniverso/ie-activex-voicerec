#pragma once
#include <string>
#include <sndfile.hh>
#include <vector>

#define SIGNED_SIZEOF(x)	((int64_t) (sizeof (x)))

typedef struct {
	sf_count_t offset, length;
	unsigned char data[2 * 8000 * 60]; // 2bit 8000Hz = 60 sec buffer
} VIO_DATA;

VIO_DATA* convertRawToWav(PaTestData* paData);
std::string convertWavToBase64(unsigned char const* ptr, unsigned int len);
