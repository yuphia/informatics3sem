#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct 
    {
        char** pointerToBuffer;
        size_t size;
    } Text;

errorType initBuffer (Text* text);
errorType readFileToBuffer (char* fileName, Text* text);
errorType freeBuffer (Text* text);
errorType writeBufferToFile (Text* text, char* writingFile);