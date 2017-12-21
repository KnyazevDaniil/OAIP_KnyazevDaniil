/*
Князев Даниил Сергеевич
Индивидуальная работа
Вариант №13
Задание: Перечислить даты начала и окончаниядоговоров, заключенных на текущей неделе(от момента запуска программы), использовавших 3 указанные услуги.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "client.h"
#include "service.h"
#include "operation.h"
#include "param.h"

#define HT_SIZE 1000
#define SECONDS_IN_WEEK 604800

static struct client	*clients[HT_SIZE] = { 0 };
static struct client	*out[HT_SIZE] = { 0 };
static struct service	services[HT_SIZE] = { 0 };
static struct operation operations[HT_SIZE] = { 0 };

static char *params[HT_SIZE] = { 0 };

static unsigned services_num = 0;
static unsigned operations_num = 0;
static unsigned params_num = 0;

int main(int argc, char *argv[])
{
	struct tm *t;
	struct client *c;
	unsigned i, j, k;
	int flag = 0;
	FILE *file;

	setlocale(LC_CTYPE, "");

	client_readfile("clients.txt", clients, HT_SIZE);
	services_num = service_readfile("services.txt", services);
	operations_num = operation_readfile("operations.txt", operations);
	params_num = param_readfile("Param.ini", params);

	for (k = 0; k < operations_num; ++k) {
		for (i = 0; i < services_num; ++i) {
			for (j = 0; j < params_num; ++j) {
				if (!params[j] || strcmp(services[i].name, params[j]))
					continue;

				if (operations[k].code != services[i].code)
					continue;

				/* Добавляем в хэш-таблицу */
				c = client_find(operations[k].telephone, clients, HT_SIZE);
				client_add(c->telephone, c, out, HT_SIZE);
			}
		}
	}

	flag = 0;
	file = fopen("Report.txt", "w");
	for (j = 0; j < HT_SIZE; ++j) {
		if (out[j] == NULL)
			continue;

		if (time(NULL) - out[j]->begin <= SECONDS_IN_WEEK) {
			t = localtime(&out[j]->begin);
			fprintf(file, "%02d.%02d.%d, ",
				t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
			t = localtime(&out[j]->end);
			fprintf(file, "%02d.%02d.%d\n",
				t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
			flag = 1;
		}
	}

	if (flag == 0)
		fprintf(file, "%s\n", "Нет данных");

	fclose(file);
	return 0;
}