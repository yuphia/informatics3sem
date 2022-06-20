#include "bufferWork.h"

errorType initBuffer (Text* text)
{
    text->pointerToBuffer = (char**)calloc (1, sizeof (char**));
    *(text->pointerToBuffer) = (char*)calloc (text->size, sizeof (char));

    if (text->size != 0 && *(text->pointerToBuffer) == NULL)
    {
        printf ("Buff init fail");
        return BUFF_INIT_FAIL;
    }
    if (text->pointerToBuffer == NULL)
        return BUFF_POINTER_INIT_FAIL;

    return NO_ERROR;
}

errorType freeBuffer (Text* text)
{
    free (*(text->pointerToBuffer));
    free (text->pointerToBuffer);

    return NO_ERROR;
}

errorType readFileToBuffer (char* fileName, Text* text)
{
    if (fileName == nullptr)
    {
        printf ("nullfilepointer");
        return NULL_FILE_POINTER;
    }
    else if (text == nullptr || *(text->pointerToBuffer) == nullptr)
    {
        printf ("nullbuffpointer");
        return NULL_BUFF_POINTER; 
    }

    FILE* readFile = fopen (fileName, "r"); 
    if (readFile == NULL)
        return CANT_OPEN_FILE;

    int check = 0;
    fread (*(text->pointerToBuffer), sizeof(char), text->size, readFile);

    fclose (readFile);

    return NO_ERROR;  
}

errorType writeBufferToFile (Text* text, char* writingFile)
{
    FILE* writingFileStream = fopen (writingFile, "w");

    fwrite (*(text->pointerToBuffer), sizeof(char), text->size, writingFileStream);

    fclose (writingFileStream);

    return NO_ERROR;
}




