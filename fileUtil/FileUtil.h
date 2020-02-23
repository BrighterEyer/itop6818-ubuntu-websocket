#ifndef CBASIC_FILEUTIL_H
#define CBASIC_FILEUTIL_H

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isFileExists(const char *filename);

unsigned int getFileSize(const char *filename);

int loadIntoBuffer(const char *filename, char** out, unsigned int len);

void printBufferWithHex(const unsigned char *buf, unsigned int len);

#endif //CBASIC_FILEUTIL_H
