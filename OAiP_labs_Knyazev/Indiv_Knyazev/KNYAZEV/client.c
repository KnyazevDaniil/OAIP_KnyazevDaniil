#define _CRT_SECURE_NO_WARNINGS
#include "client.h"

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define HT_SIZE 1000

static const char delim[] = ",\t\n\r";

static unsigned hash(const char *key)
{
	unsigned hash, i;
	for (hash = i = 0; i < strlen(key); ++i) {
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);

	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

static void client_readnext(FILE *file, struct client **htable, unsigned htable_size)
{
	char line[2048];
	struct client *c;

	struct tm tm_begin;
	struct tm tm_end;

	c = malloc(sizeof(*c));

	memset(line, 0, sizeof(line));
	fgets(line, sizeof(line), file);

	if (line[0] == 0)
		return;

	memset(&tm_begin, 0, sizeof(tm_begin));
	memset(&tm_end, 0, sizeof(tm_end));

	c->full_name = _strdup(strtok(line, delim));
	c->telephone = _strdup(strtok(NULL, delim));

	sscanf(strtok(NULL, delim), "%d.%d.%d",
		&tm_begin.tm_mday, &tm_begin.tm_mon, &tm_begin.tm_year);
	tm_begin.tm_mon -= 1;
	tm_begin.tm_year -= 1900;

	sscanf(strtok(NULL, delim), "%d.%d.%d",
		&tm_end.tm_mday, &tm_end.tm_mon, &tm_end.tm_year);
	tm_end.tm_mon -= 1;
	tm_end.tm_year -= 1900;

	sscanf(strtok(NULL, delim), "%u", &c->debt);
	sscanf(strtok(NULL, delim), "%u", &c->credit);

	c->begin = mktime(&tm_begin);
	c->end = mktime(&tm_end);

	htable[hash(c->telephone) % htable_size] = c;
}

void client_readfile(char *file_name, struct client **htable, unsigned htable_size)
{
	FILE *file = fopen(file_name, "r");

	while (!feof(file)) {
		client_readnext(file, htable, htable_size);
	}

	fclose(file);
}

struct client *client_find(const char *key, struct client **htable, unsigned htable_size)
{
	return htable[hash(key) % htable_size];
}

void client_add(const char *key, struct client *c, struct client **htable, unsigned htable_size)
{
	htable[hash(key) % htable_size] = c;
}