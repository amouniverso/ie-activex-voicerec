#include "stdafx.h"
#include <stdio.h>
#include "AudioHandler.h"
#include <string>
#include <vector>
#include "AudioFormatEncoder.h"
#include "Base64.h"

/*==============================================================================
*/

static sf_count_t
vfget_filelen(void *user_data)
{
	VIO_DATA *vf = (VIO_DATA *)user_data;

	return vf->length;
} /* vfget_filelen */

static sf_count_t
vfseek(sf_count_t offset, int whence, void *user_data)
{
	VIO_DATA *vf = (VIO_DATA *)user_data;

	switch (whence)
	{
	case SEEK_SET:
		vf->offset = offset;
		break;

	case SEEK_CUR:
		vf->offset = vf->offset + offset;
		break;

	case SEEK_END:
		vf->offset = vf->length + offset;
		break;
	default:
		break;
	};

	return vf->offset;
} /* vfseek */

static sf_count_t
vfread(void *ptr, sf_count_t count, void *user_data)
{
	VIO_DATA *vf = (VIO_DATA *)user_data;

	/*
	**	This will brack badly for files over 2Gig in length, but
	**	is sufficient for testing.
	*/
	if (vf->offset + count > vf->length)
		count = vf->length - vf->offset;

	memcpy(ptr, vf->data + vf->offset, count);
	vf->offset += count;

	return count;
} /* vfread */

static sf_count_t
vfwrite(const void *ptr, sf_count_t count, void *user_data)
{
	VIO_DATA *vf = (VIO_DATA *)user_data;

	/*
	**	This will break badly for files over 2Gig in length, but
	**	is sufficient for testing.
	*/
	if (vf->offset >= SIGNED_SIZEOF(vf->data))
		return 0;

	if (vf->offset + count > SIGNED_SIZEOF(vf->data))
		count = sizeof(vf->data) - vf->offset;

	memcpy(vf->data + vf->offset, ptr, (size_t)count);
	vf->offset += count;

	if (vf->offset > vf->length)
		vf->length = vf->offset;

	return count;
} /* vfwrite */

static sf_count_t
vftell(void *user_data)
{
	VIO_DATA *vf = (VIO_DATA *)user_data;

	return vf->offset;
} /* vftell */


  /*==============================================================================
  */

VIO_DATA* convertRawToWav(PaTestData* paData) {
	static VIO_DATA vio_data;

	SF_VIRTUAL_IO vio;
	SNDFILE * file;
	SF_INFO sfinfo;

	/* Set up pointers to the locally defined functions. */
	vio.get_filelen = vfget_filelen;
	vio.seek = vfseek;
	vio.read = vfread;
	vio.write = vfwrite;
	vio.tell = vftell;

	/* Set virtual file offset and length to zero. */
	vio_data.offset = 0;
	vio_data.length = 0;

	memset(&sfinfo, 0, sizeof(sfinfo));
	sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
	sfinfo.channels = 1;
	sfinfo.samplerate = 8000;

	if ((file = sf_open_virtual(&vio, SFM_WRITE, &sfinfo, &vio_data)) == NULL)
	{
		printf("\n\nLine %d : sf_open_write failed with error : ", __LINE__);
		fflush(stdout);
		puts(sf_strerror(NULL));
		exit(1);
	};

	if (vfget_filelen(&vio_data) < 0)
	{
		printf("\n\nLine %d : vfget_filelen returned negative length.\n\n", __LINE__);
		exit(1);
	};

	std::vector<SAMPLE> v = paData->recordedSamples;
	sf_write_short(file, &v[0], v.size());
	sf_close(file);

	puts("ok");
	return &vio_data;
}

std::string convertWavToBase64(unsigned char const* ptr, unsigned int len) {
	return base64_encode(ptr, len);
}