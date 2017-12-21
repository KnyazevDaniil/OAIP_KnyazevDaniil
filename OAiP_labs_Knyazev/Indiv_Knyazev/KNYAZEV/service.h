#pragma once

struct service {
	char *name;
	unsigned code;
	float price;
	char *ival;
};

unsigned service_readfile(char *file_name, struct service *services);