#pragma once

#include <time.h>

struct operation {
	char *telephone;
	unsigned code;
	time_t use_time;
	int duration;
};

unsigned operation_readfile(char *file_name, struct operation *ops);