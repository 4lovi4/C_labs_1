#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	double num, max, min, sum = 0;
	int count, i;
	
	setlocale(LC_ALL, "RUS");

	puts("��������� ������������������ ������� �����");
	printf_s("������� ���������� ����� ������������������ -> ");
	scanf_s("%d", &count);
	puts("������� ������������������. ����� ������� ����� ��������� <Enter>");
	
	for(i = 0; i < count; i++) {
		printf_s("-> ");
		scanf_s("%lf", &num);
		sum += num;
		if (i == 0) {
			max = num;
			min = num;
		}
		else {
			if (num >= max)
				max = num;
			if (num <= min)
				min = num;
		}
	}

	printf_s("������� ��������������: %.3lf\n" 
		"����������� �����: %.3lf\n"
		"������������ �����: %.3lf\n",
		(sum / count), min, max);
	puts("��� ���������� ������� <Enter>"); //��������� ��������� � ����� 0 �� ������� �� Enter
	if(_getch() == 13)
		return 0;
}