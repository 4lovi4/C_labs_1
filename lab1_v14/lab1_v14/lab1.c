#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>


int f_help()
{
	printf_s("������������ ������ � 1 ������� 14:\n"
		"���������� ������ ���� �� ��������� ������� \'�\'\n");
	return 0;
}

int main(int argc, char** argv)
{
	double a; //� - ����� ����
	setlocale(LC_ALL,"RUS");
	if (argc == 2 && !strcmp(argv[1], "help")) {
		f_help();
		return 1;
	}
	printf_s("���������� ������ ����.\n"
		"������� ����� ����� (��) ���� � ������� <Enter>\n-> ");
	scanf_s("%lf", &a);
	printf_s("����� ����: %.2lf ���.��.\n", pow(a, 3)); //����� ����������
	return 0;
}