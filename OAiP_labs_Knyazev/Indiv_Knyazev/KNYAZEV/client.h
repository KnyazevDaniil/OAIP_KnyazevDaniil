#pragma once

#include <time.h>
#include <stdio.h>

#define HT_SIZE 1000

struct client {
	char *full_name;
	char *telephone;
	time_t begin;
	time_t end;
	unsigned debt;
	unsigned credit;

};

void client_readfile(char *file_name, struct client **htable, unsigned htable_size);
struct client *client_find(const char *key, struct client **htable, unsigned htable_size);
void client_add(const char *key, struct client *c, struct client **htable, unsigned htable_size);
