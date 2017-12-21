#define _CRT_SECURE_NO_WARNINGS
#include "param.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char delim[] = ",\t\n\r";

static int param_readnext(FILE *file, char **p)
{
	char line[2048];

	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), file);
	if (line[0] == 0)
		return 0;

	*p = _strdup(strtok(line, delim));
	return 1;
}

unsigned param_readfile(char *file_name, char **params)
{
	unsigned filled;
	FILE *file = fopen(file_name, "r");
	if (!file)
		return 0;

	for (filled = 0; !feof(file); ) {
		filled += param_readnext(file, &params[filled]);
	}

	return filled;
}