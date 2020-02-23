#include "FileUtil.h"

int main(int argc, char **argv)
{
    char *filename = "D:\\CTest\\main.c";
    unsigned int len = 0;
    char* pBuf;

    if(!isFileExists(filename))
    {
        fprintf(stderr, "file %s not exists.", filename);
        return -1;
    }

    if((len=getFileSize(filename)) == 0)
    {
        fprintf(stderr, "file %s is empty.", filename);
        return 0;
    }

    pBuf = (char *) calloc(1, len+1);
    if (pBuf == NULL)
    {
        fprintf(stderr, "alloc memory failed.");
        return -1;
    }

    if(!loadIntoBuffer(filename, &pBuf, len))
    {
        fprintf(stderr, "load file %s into memory failed.", filename);
        return -1;
    }

    printBufferWithHex(pBuf, len);

    free(pBuf);

    return 0;
}