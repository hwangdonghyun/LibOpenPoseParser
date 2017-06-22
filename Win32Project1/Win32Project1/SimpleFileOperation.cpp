#include <stdlib.h>
#include <stdio.h>
#include "SimpleFileOperation.h"

char* openAndReadFile(char* fileName)
{
	FILE* file;
	char* data = NULL;

	file = fopen(fileName, "r+");

	if (file == NULL)
	{
		fprintf(stderr, "File is not opend\n");
		exit(-1);
	}

	data = (char*)calloc(65000, sizeof(char));
	int offset = 0;

	while (feof(file) == 0)
		data[offset++] = fgetc(file);

	fclose(file);

	return data;
}

void safeFree(void * data)
{
	if (data != NULL)
		free(data);
}

