/*
Князев Даниил Сергеевич
Лабораторная работа №4
Вариант №3
Задание: Написать программу, которая во вводимом с клавиатуры тексте выберет слова,
заканчивающиеся согласной буквой, и выведет их на экран.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Mas 128

static const char saltLetters[] = "qQwWrRtTpPsSdDfFgGhHkKlLjJzZxXcCvBVbnNmM";

int isSalt(char* word)
{
	unsigned int i = 0;

	for (i = 0; i < strlen(saltLetters); ++i) {
		if (word[strlen(word) - 1] == saltLetters[i]) {
			return 1;
		}
	}

	return 0;
}

int main(int argc, char* argv[])
{
	char word[Mas];
	FILE* fi = NULL;
	FILE* fo = NULL;

	fopen_s(&fi, "input.txt", "r");
	fopen_s(&fo, "output.txt", "w");

	while (!feof(fi)) {
		fscanf_s(fi, "%s\n", word);
		if (isSalt(word)) {
			fprintf_s(fo, "%s\n", word);
		}
	}

	fclose(fi);
	fclose(fo);

	return 0;
}