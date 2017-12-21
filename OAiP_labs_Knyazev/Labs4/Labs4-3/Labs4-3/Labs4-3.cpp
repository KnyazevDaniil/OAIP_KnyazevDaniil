/*
Князев Даниил Сергеевич
Лабораторная работа №4
Вариант №3
Задание: Написать программу, которая во вводимом с клавиатуры тексте выберет слова,
заканчивающиеся согласной буквой, и выведет их на экран.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char salt_letters[] = "qQwWrRtTpPsSdDfFgGhHkKlLzZxXcCvVbBnNmM";
int is_salt(char* word)
{
	unsigned int i = 0;

	for (i = 0; i < strlen(salt_letters); ++i)
	{
		if (word[strlen(word) - 1] == salt_letters[i]) 
		{
			return 1;
		}
	}

	return 0;
}

int main(int argc, char* argv[])
{
	char word[128];
	FILE* fi = NULL;
	FILE* fo = NULL;
	fopen(&fi, "input.txt", "r");
	fopen(&fo, "output.txt", "w");
	while (!feof(fi)) 
	{
		fscanf(fi, "%s\n", word);
		if (is_salt(word)) 
		{
			fprintf(fo, "%s\n", word);
		}
	}
	fclose(fi);
	fclose(fo);
	return 0;
}