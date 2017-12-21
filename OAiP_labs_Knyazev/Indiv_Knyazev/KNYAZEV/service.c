#define _CRT_SECURE_NO_WARNINGS
#include "service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char delim[] = ",\t\n\r";

static int service_readnext(FILE *file, struct service *s)
{
	char line[2048];

	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), file);
	if (line[0] == 0)
		return 0;

	s->name = _strdup(strtok(line, delim));
	sscanf(strtok(NULL, delim), "%u", &s->code);
	sscanf(strtok(NULL, delim), "%f", &s->price);
	s->ival = _strdup(strtok(NULL, delim));

	return 1;
}

unsigned service_readfile(char *file_name, struct service *services)
{
	unsigned filled;
	FILE *file = fopen(file_name, "r");
	if (!file)
		return 0;

	for (filled = 0; !feof(file); ) {
		filled += service_readnext(file, &services[filled]);
	}

	return filled;
}