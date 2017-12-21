/*
Князев Даниил Сергеевич
Лабораторная работа №3
Вариант №3
Задание: Написать программу, которая во вводимом с клавиатуры тексте выберет слова,
заканчивающиеся согласной буквой, и выведет их на экран.
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale>
#include <windows.h>
#define N 256
#define DELIM " \n\t,.;:?!"

#define MaxLength 1000

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i;
	char D[] = "аАуУеЕоОяЯиИюЮ";
	char str[N], *p;
	puts("Введите слова:");
	fgets(str, N, stdin);
	for (p = strtok(str, DELIM); p; p = strtok(NULL, DELIM)) 
	{
		for (i = 0; D[i]; i++) 
		{
			if (*p == D[i]) 
			{
				puts(p);
				break;
			}
		}
	}
	_getch();
}