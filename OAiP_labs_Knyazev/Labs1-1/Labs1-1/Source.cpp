/* 
	Князев Даниил Сергеевич
	Лабораторная работа №1
	Вариант 1
	Задание: перевести мили в сажани и перевести в сантиметры.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

#define TRANSLATION_MILES 500;
#define TRANSLATION_SAJANI 213.36;

int main() 
{
	float miles;
	int check = 0;
	printf("Enter miles ");
	check = scanf("%f", &miles);
	if (check == 0)
	{
		printf("Error: 'miles' incorrect input \n");
	}
	else 
	{
		float sajani = miles * TRANSLATION_MILES;
		printf("\n Sajani  %9.2f ", sajani);
		float centimeters = sajani * TRANSLATION_SAJANI;
		printf("\n Centimeters %9.2f \n", centimeters);
	}
	_getch();
	return 0;
}