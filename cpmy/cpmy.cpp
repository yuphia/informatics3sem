#include <stdio.h>
#include <stdlib.h>

#include "bufferWork.h"

size_t getFileSize (char* fileName);

int main (int argc, char* argv[])
{
    if (argc != 3)
    {
        printf ("Wrong input format. Please use as follows: cpmy txt1 txt2\n");
        return 1;
    }

    char* readingFile = argv[1];
    char* writingFile = argv[2];

    Text text = {nullptr, getFileSize (readingFile)};
    initBuffer (&text);

    readFileToBuffer (readingFile, &text);

    //printf ("%s", *(text.pointerToBuffer));
    writeBufferToFile (&text, writingFile);

    freeBuffer (&text);
    return 0;
}

size_t getFileSize (char* fileName)
{
    size_t fileSize = 0;

    FILE* file = fopen (fileName, "r");

    fseek (file, 0L, SEEK_END);
    fileSize = ftell (file);
    fseek (file, 0L, SEEK_SET);

    fclose (file);

    return fileSize;
}