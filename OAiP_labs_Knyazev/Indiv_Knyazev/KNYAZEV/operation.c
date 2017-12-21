#define _CRT_SECURE_NO_WARNINGS
#include "operation.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

static const char delim[] = ",\t\n\r";

static int operation_readnext(FILE *file, struct operation *o)
{
	char line[2048];
	char *duration;
	struct tm date;

	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), file);
	if (line[0] == 0)
		return 0;

	o->telephone = _strdup(strtok(line, delim));
	sscanf(strtok(NULL, delim), "%u", &o->code);

	memset(&date, 0, sizeof(date));
	sscanf(strtok(NULL, delim), "%d.%d.%d %d:%d:%d",
		&date.tm_mday, &date.tm_mon, &date.tm_year,
		&date.tm_hour, &date.tm_min, &date.tm_sec);

	date.tm_mon -= 1;
	date.tm_year -= 1900;

	o->use_time = mktime(&date);
	duration = strtok(NULL, delim);

	if (strstr(duration, "#"))
		o->duration = -1;
	else
		sscanf(duration, "%d", &o->duration);

	return 1;
}

unsigned operation_readfile(char *file_name, struct operation *ops)
{
	unsigned filled;
	FILE *file = fopen(file_name, "r");

	for (filled = 0; !feof(file); ) {
		filled += operation_readnext(file, &ops[filled]);
	}

	return filled;
}