/*
   Князев Даниил Сергеевич
   Лабораторная работа №2
   Вариант 1
   Задание: Написать программу, которая вычисляет, сколько раз введенное с клавиатуры
число встречается в массиве. Массив и его длина вводятся пользователем.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a[100];
	int n;
	printf("Введите массив N:");
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
		scanf("%i", &a[i]);
	printf("Введите образец для сравнения ->");
	int givenNumber;
	scanf("%i", &givenNumber);
	int elements;
	elements = 0;
	for (i = 0; i < n; i++)
		if (a[i] == givenNumber) elements++;
	if (elements)
		printf("Число %d встречается в массиве %d раз", givenNumber, elements);
	else printf("Повторите ввод!");
	printf("\nДля завершения работы нажмите <Enter>");
	_getch();
	return 0;
}