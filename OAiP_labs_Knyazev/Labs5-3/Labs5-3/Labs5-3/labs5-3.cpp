/*
������ ������ ���������
������������ ������ �5.
������� �3
�������. �������� ���������, ������� ���������� � ���������� � ���� ���������
�������� ��������� �������� �������. � �������� ����������� ����� ���������
������������ ������ ���������. � ��������� �����������:
�) ���������� ������������� ������� �������� ������ �����������;
�) ����� ��������� � �������� ��������� ���������� ��������;
�) ����� �� ����� ����������� ������� ��������;
�) ������������ ������� �������� �� ��������� ���� (��������), ��������
����������� �� �����������.

3. ��������: �������, ���, ��������, ��� ��������, �������, �����, ����� ����������� �����, ������ �����, �����-������, �������.
*/

#define _CRT_SECURE_NO_WARNINGS 
#define MaximumArray 100
#include <string>
#include <windows.h>

struct Date
{
	int day;
	int month;
	int year;
};

struct Dir
{
	char name[MaximumArray];
	char surname[MaximumArray];
	char dadname[MaximumArray];
};

struct Mov
{
	char name[MaximumArray];
	char address[MaximumArray];
	int med�ard;
	int phone;
	Date dt;
	Dir director;
};

int find_diagnosis(Mov*, int);
int find_patient_surname(Mov*, int);
int find_patient_name(Mov*, int);
int find_patient_dadname(Mov*, int);
int find_year_of_birth(Mov*, int);
int find_med_card(Mov*, int);
int find_phone(Mov*, int);
int find_address(Mov*, int);
void sort_med_card(Mov*, int);
void sort_phone(Mov*, int);
void sort_year_of_birth(Mov*, int);
void new_patient(Mov*, int);
void conclusion_patients(Mov*, int);



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Mov Movie[MaximumArray];
	int n, command = 0, command_to_find = 0, command_to_find2 = 0, len = 0, k = 0, day = 0, v = 0;
	int month = 0, year = 0, price = 0, proffit = 0, command_to_sort = 0;
	char s[MaximumArray] = "", object_of_finding[101], vs[100];
	bool find = false;

	printf_s("������� ���������� ���������: ");
	scanf_s("%d", &n);
	new_patient(Movie, n);
	conclusion_patients(Movie, n);
	while (command != 4) {
		printf_s("\n�������� �������:\n1.����� ����� �������� '1'\n2.��� ���������� ��������� ������� '2'\n3����� ���������� ���� ��������� '3'\n4.��� ������ ������� '4'\n�������: ");
		scanf_s("%d", &command);

		switch (command) {
		case 1: {
			printf("\n������� �������.\n������ �������� ���� ������:\n����� �� �������� '1'\n����� �� ��� '2'\n����� �� ���� �������� '3'\n����� �� ������ ���. ����� '4'\n����� �� ������ �������� '5'\n����� �� ������ '6'\n�������: ");
			scanf_s("%d", &command_to_find);

			switch (command_to_find) {
			case 1: {
				if (find_diagnosis(Movie, n)) {
					find = true;
				}
				break;
			}
			case 2: {
				printf_s("\n������� �������.\n����� ������� �������� '1'\n����� ��� �������� '2'\n����� �������� �������� '3'\n �������: ");
				scanf_s("%d", &command_to_find2);

				switch (command_to_find2) {
				case 1: {
					if (find_patient_surname(Movie, n)) {
						find = true;
					}
					break;
				}
				case 2: {
					if (find_patient_name(Movie, n)) {
						find = true;
					}
					break;
				}
				case 3: {
					if (find_patient_dadname(Movie, n)) {
						find = true;
					}
					break;
				}
				default: {printf_s("\n������������ �������!\n"); }
				}

				break;
			}
			case 3: {
				if (find_year_of_birth(Movie, n)) {
					find = true;
				}
				break;
			}
			case 4: {
				if (find_med_card(Movie, n)) {
					find = true;
				}
				break;
			}
			case 5: {
				if (find_phone(Movie, n)) {
					find = true;
				}
				break;
			}
			case 6: {
				if (find_address(Movie, n)) {
					find = true;
				}
				break;
			}
			default: {printf("Wrong command!"); }
			}
			if (find == false)
			{
				printf_s("\n====================================\n");
				printf("No results!");
				printf_s("\n====================================\n");
			}
			find = false;
			break;
		}
		case 2: {
			printf_s("\n������� �������.\n����������� �� ������ ���. ����� '1'\n����������� �� ������ �������� '2'\n����������� �� ���� �������� '3'\n �������: ");
			scanf_s("%d", &command_to_sort);
			switch (command_to_sort)
			{
			case 1: {sort_med_card(Movie, n); break; }
			case 2: {sort_phone(Movie, n); break; }
			case 3: {sort_year_of_birth(Movie, n); break; }
			}
			break;
		}
		case 3: {
			conclusion_patients(Movie, n);
			break;
		}
		case 4: {
			printf_s("\n������� �������. ����������!\n\n");
			return 0;
			break;
		}
		default: printf("\n������������ �������!\n");
		}
	}
	return 0;
}

int find_diagnosis(Mov *Movie, int n)
{
	char object_of_finding[MaximumArray], s[MaximumArray];
	int len, k = 0;
	bool find = false;
	printf_s("\n������� ������� ��������: ");
	fgets(s, MaximumArray, stdin);
	fgets(object_of_finding, MaximumArray, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].name[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("\n====================================");
			printf_s("\n�������: %s\n���� ��������: %d.%d.%d \n����� ��������: %s�������: %s���: %s��������: %s����� ���. �����: %d \n����� ��������: %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].address, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].med�ard, Movie[i].phone);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int find_patient_surname(Mov *Movie, int n)
{
	char object_of_finding[MaximumArray], s[MaximumArray];
	int len, k = 0;
	bool find = false;
	printf_s("\n������� ������� ��������: ");
	fgets(s, MaximumArray, stdin);
	fgets(object_of_finding, MaximumArray, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].director.surname[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("====================================");
			printf_s("\n�������: %s\n���� ��������: %d.%d.%d \n����� ��������: %s�������: %s���: %s��������: %s����� ��� �����: %d \n����� ��������: %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].address, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].med�ard, Movie[i].phone);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int find_patient_name(Mov *Movie, int n)
{
	char object_of_finding[MaximumArray], s[MaximumArray];
	int len, k = 0;
	bool find = false;
	printf_s("\n������� ��� ��������: ");
	fgets(s, MaximumArray, stdin);
	fgets(object_of_finding, MaximumArray, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].director.name[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("\n====================================");
			printf_s("\n�������: %s\n ���� ��������: %d.%d.%d \n����� ��������: %s�������: %s���: %s��������: %s����� ���. �����: %d \n����� ��������: %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].address, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].med�ard, Movie[i].phone);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int find_patient_dadname(Mov *Movie, int n)
{
	char object_of_finding[MaximumArray], s[MaximumArray];
	int len, k = 0;
	bool find = false;
	printf_s("\n������ �������� ��������: ");
	fgets(s, MaximumArray, stdin);
	fgets(object_of_finding, MaximumArray, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].director.dadname[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("\n====================================");
			printf_s("\n�������: %s\n���� ��������: %d.%d.%d \n����� ��������: %s�������: %s���: %s��������: %s����� ���. �����: %d \n����� ��������: %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].address, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].med�ard, Movie[i].phone);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int find_year_of_birth(Mov *Movie, int n)
{
	int day, month, year;
	bool find = false;
	printf_s("\n���� ��������: ");
	scanf_s("%d %d %d", &day, &month, &year);
	for (int i = 0; i < n; i++)
	{
		if (Movie[i].dt.day == day && Movie[i].dt.month == month && Movie[i].dt.year)
		{
			printf_s("\n====================================");
			printf_s("\n�������: %s\n���� ��������: %d.%d.%d \n����� ��������: %s�������: %s���: %s��������: %s����� ���. �����: %d \n����� ��������: %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].address, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].med�ard, Movie[i].phone);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int find_med_card(Mov *Movie, int n)
{
	int med_card;
	bool find = false;
	printf_s("\n����� ���. �����: ");
	scanf_s("%d", &med_card);
	for (int i = 0; i < n; i++)
	{
		if (Movie[i].med�ard == med_card)
		{
			printf_s("\n====================================");
			printf_s("\n�������: %s\n���� ��������: %d.%d.%d \n����� ��������: %s�������: %s���: %s��������: %s����� ���. �����: %d \n����� ��������: %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].address, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].med�ard, Movie[i].phone);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int find_phone(Mov * Movie, int n)
{
	int phone;
	bool find = false;
	printf_s("\n����� �������� ��������: ");
	scanf_s("%d", &phone);
	for (int i = 0; i < n; i++)
	{
		if (Movie[i].phone == phone)
		{
			printf_s("\n====================================");
			printf_s("\n�������: %s\n���� ��������: %d.%d.%d \n����� ��������: %s�������: %s���: %s��������: %s����� ���. �����: %d \n����� ��������: %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].address, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].med�ard, Movie[i].phone);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int find_address(Mov *Movie, int n)
{
	char object_of_finding[MaximumArray], s[MaximumArray];
	int len, k = 0;
	bool find = false;
	printf_s("\n������� ����� ��������: ");
	fgets(s, MaximumArray, stdin);
	fgets(object_of_finding, MaximumArray, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].address[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("\n====================================");
			printf_s("\n�������: %s\n���� ��������: %d.%d.%d \n����� ��������: %s�������: %s���: %s��������: %s����� ���. �����: %d \n����� ��������: %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].address, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].med�ard, Movie[i].phone);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
void sort_med_card(Mov *Movie, int n)
{
	char vs[MaximumArray];
	int v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].med�ard > Movie[j + 1].med�ard)
			{
				v = Movie[j].med�ard;
				Movie[j].med�ard = Movie[j + 1].med�ard;
				Movie[j + 1].med�ard = v;

				v = Movie[j].phone;
				Movie[j].phone = Movie[j + 1].phone;
				Movie[j + 1].phone = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].name);
				strcpy_s(Movie[j].name, Movie[j + 1].name);
				strcpy_s(Movie[j + 1].name, vs);

				strcpy_s(vs, Movie[j].address);
				strcpy_s(Movie[j].address, Movie[j + 1].address);
				strcpy_s(Movie[j + 1].address, vs);

				strcpy_s(vs, Movie[j].director.name);
				strcpy_s(Movie[j].director.name, Movie[j + 1].director.name);
				strcpy_s(Movie[j + 1].director.name, vs);

				strcpy_s(vs, Movie[j].director.surname);
				strcpy_s(Movie[j].director.surname, Movie[j + 1].director.surname);
				strcpy_s(Movie[j + 1].director.surname, vs);

				strcpy_s(vs, Movie[j].director.dadname);
				strcpy_s(Movie[j].director.dadname, Movie[j + 1].director.dadname);
				strcpy_s(Movie[j + 1].director.dadname, vs);
			}
		}
}
void sort_phone(Mov *Movie, int n)
{
	int v;
	char vs[MaximumArray];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].phone > Movie[j + 1].phone)
			{
				v = Movie[j].med�ard;
				Movie[j].med�ard = Movie[j + 1].med�ard;
				Movie[j + 1].med�ard = v;

				v = Movie[j].phone;
				Movie[j].phone = Movie[j + 1].phone;
				Movie[j + 1].phone = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].name);
				strcpy_s(Movie[j].name, Movie[j + 1].name);
				strcpy_s(Movie[j + 1].name, vs);

				strcpy_s(vs, Movie[j].address);
				strcpy_s(Movie[j].address, Movie[j + 1].address);
				strcpy_s(Movie[j + 1].address, vs);

				strcpy_s(vs, Movie[j].director.name);
				strcpy_s(Movie[j].director.name, Movie[j + 1].director.name);
				strcpy_s(Movie[j + 1].director.name, vs);

				strcpy_s(vs, Movie[j].director.surname);
				strcpy_s(Movie[j].director.surname, Movie[j + 1].director.surname);
				strcpy_s(Movie[j + 1].director.surname, vs);

				strcpy_s(vs, Movie[j].director.dadname);
				strcpy_s(Movie[j].director.dadname, Movie[j + 1].director.dadname);
				strcpy_s(Movie[j + 1].director.dadname, vs);
			}
		}
}
void sort_year_of_birth(Mov *Movie, int n)
{
	int v;
	char vs[MaximumArray];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].dt.year > Movie[j + 1].dt.year)
			{
				v = Movie[j].med�ard;
				Movie[j].med�ard = Movie[j + 1].med�ard;
				Movie[j + 1].med�ard = v;

				v = Movie[j].phone;
				Movie[j].phone = Movie[j + 1].phone;
				Movie[j + 1].phone = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].name);
				strcpy_s(Movie[j].name, Movie[j + 1].name);
				strcpy_s(Movie[j + 1].name, vs);

				strcpy_s(vs, Movie[j].address);
				strcpy_s(Movie[j].address, Movie[j + 1].address);
				strcpy_s(Movie[j + 1].address, vs);

				strcpy_s(vs, Movie[j].director.name);
				strcpy_s(Movie[j].director.name, Movie[j + 1].director.name);
				strcpy_s(Movie[j + 1].director.name, vs);

				strcpy_s(vs, Movie[j].director.surname);
				strcpy_s(Movie[j].director.surname, Movie[j + 1].director.surname);
				strcpy_s(Movie[j + 1].director.surname, vs);

				strcpy_s(vs, Movie[j].director.dadname);
				strcpy_s(Movie[j].director.dadname, Movie[j + 1].director.dadname);
				strcpy_s(Movie[j + 1].director.dadname, vs);
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].dt.month > Movie[j + 1].dt.month)
			{
				v = Movie[j].med�ard;
				Movie[j].med�ard = Movie[j + 1].med�ard;
				Movie[j + 1].med�ard = v;

				v = Movie[j].phone;
				Movie[j].phone = Movie[j + 1].phone;
				Movie[j + 1].phone = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].address);
				strcpy_s(Movie[j].address, Movie[j + 1].address);
				strcpy_s(Movie[j + 1].address, vs);
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].dt.day > Movie[j + 1].dt.day)
			{
				v = Movie[j].med�ard;
				Movie[j].med�ard = Movie[j + 1].med�ard;
				Movie[j + 1].med�ard = v;

				v = Movie[j].phone;
				Movie[j].phone = Movie[j + 1].phone;
				Movie[j + 1].phone = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].address);
				strcpy_s(Movie[j].address, Movie[j + 1].address);
				strcpy_s(Movie[j + 1].address, vs);
			}
		}
}
void new_patient(Mov *Movie, int n)
{
	for (int i = 0; i < n; i++)
	{
		char s[MaximumArray];
		int len;
		printf_s("\n[ %d������� ]\n", i + 1);
		printf_s("\n������� �������: ");
		fgets(s, MaximumArray, stdin);
		fgets(Movie[i].name, MaximumArray, stdin);
		len = strlen(Movie[i].name);
		Movie[i].name[len - 1] = '\0';
		printf("\n������� ����� ��������: ");
		fgets(Movie[i].address, MaximumArray, stdin);
		printf("\n������� ������� ��������: ");
		fgets(Movie[i].director.surname, MaximumArray, stdin);
		printf("\n�������� ��� ��������: ");
		fgets(Movie[i].director.name, MaximumArray, stdin);
		printf("\n������� �������� ��������: ");
		fgets(Movie[i].director.dadname, MaximumArray, stdin);
		printf("\n������� ���� �������� ��������: ");
		scanf_s("%d %d %d", &Movie[i].dt.day, &Movie[i].dt.month, &Movie[i].dt.year);
		printf("\n������� ����� ���. ����� ��������: ");
		scanf_s("%d", &Movie[i].med�ard);
		printf("\n������� ����� �������� ��������: ");
		scanf_s("%d", &Movie[i].phone);
	}
}
void conclusion_patients(Mov* Movie, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n====================================");
		printf_s("\n[ %d ������� ]\n", i + 1);
		printf_s("\n�������: %s\n���� ��������: %d.%d.%d \n����� ��������: %s�������: %s���: %s��������: %s����� ���. �����: %d \n����� ��������: %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].address, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].med�ard, Movie[i].phone);
		printf("\n====================================\n");
	}
}