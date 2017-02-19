#include "lab4_14.h"

char man_or_rand()
{
	char ch = 'r';
	char yn_str[16];
	char rand_str[10][8] = {"y", "Y", "yes", "YES", "Yes",
					"да", "ДА", "д", "Д", " Да"};
	char man_str[10][8] = {"n", "N", "No", "NO", "no",
							"да", "ДА", "Да", "д", "Д"};
	int i;
	printf_s("Хотите ввести данные массива самостоятельно или доверите это rand()'у? y/n\n");
	memset(yn_str, 0, sizeof(yn_str));
	scanf_s("%s", yn_str, 16);
	printf_s("yn_str = %s\n", yn_str);
	for(i = 0; i < 10; i++) {
		if(!strcmp(yn_str, rand_str[i]))
			;
		else if(!strcmp(yn_str, man_str[i]))
			ch = 'm';
	}

	return(ch);
}

int rand_array(int *a)
{
	int i;
	srand((unsigned)time(NULL));
	for(i = 0; i < SIZEA; i++)
		a[i] = (double)rand() / (RAND_MAX + 1) * 99;
	return 0;
}

