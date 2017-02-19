#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>


int f_help()
{
	printf_s("Лабораторная работа № 1 вариант 14:\n"
		"Вычисление объема куба по известной стороне \'а\'\n");
	return 0;
}

int main(int argc, char** argv)
{
	double a; //а - ребро куба
	setlocale(LC_ALL,"RUS");
	if (argc == 2 && !strcmp(argv[1], "help")) {
		f_help();
		return 1;
	}
	printf_s("Вычисление объема куба.\n"
		"Введите длину ребра (см) куба и нажмите <Enter>\n-> ");
	scanf_s("%lf", &a);
	printf_s("Объем куба: %.2lf куб.см.\n", pow(a, 3)); //Вывод результата
	return 0;
}