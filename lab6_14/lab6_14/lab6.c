#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

int sq_vol(double a, double b, double c,
		   double *sq, double *vol);
int main()
{
	double a, b, c,
		sq = 0, vol = 0;
	setlocale(LC_ALL, "RUS");
	printf_s("������������ ������ �6 (������� 14): \n"
		"���������� ������� ���������� ������ � ������� ����������� ���������������.\n");
	printf_s("������ �������� 3-� ������ ���������������: ");
	scanf_s("%lf %lf %lf", &a, &b, &c);
	sq_vol(a, b, c, &sq, &vol);
	printf_s("========================================================\n"
		"��������� ������ �������:\n"
		"\t������� ����������� = %3.2lf ��^2\n"
		"\t����� ��������������� = %3.2lf ��^3\n", sq, vol);
	return 0;
}

int sq_vol(double a, double b, double c,
		   double *sq, double *vol)
{
	*sq = 2 * a * b + 2 * b * c + 2 * a * c;
	*vol = a * b * c;
	return 0;
}