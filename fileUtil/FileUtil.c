#include "FileUtil.h"

#define BUF_SIZE 1024

bool isFileExists(const char *filename)
{
	return access(filename, F_OK) != -1;
}

unsigned int getFileSize(const char *filename)
{
	struct stat stat_buf;
	stat(filename, &stat_buf);
	unsigned int len = (unsigned int) stat_buf.st_size;
	return len;
}

int loadIntoBuffer(const char *filename, char** out, unsigned int len)
{
	FILE *file;
	file = fopen(filename, "r");
	if (file == NULL)
	{
		return 0;
	}

	int total = 0;
	size_t rc = 0;
	while ((rc = fread(*out + total, 4, BUF_SIZE, file)) != 0)
	{
		total += rc;
	}

	fclose(file);
	return 1;
}

void printBufferWithHex(const unsigned char *buf, unsigned int len)
{
	if (len <= 0)
	{
		return;
	}

	for (int i = 0; i < len; i++)
	{
		if (i % 0x10 == 0)
		{
			printf("\n0x%p ", buf + i);
		}
		printf("%02X ", *(buf + i));
	}
	printf("\n");
}