#define _CRT_RAND_S
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	unsigned int ab[2], i, res; //ab[2] - ������ ����������
	
	setlocale(LC_ALL, "RUS"); //��������� ������ RUS ��� ����������� ��������� � �������
	
	for (i=0; i < 2; i++) { //���������� ���������� ���������������� ������� �� 1-�� �� 9-�� � ������� rand_s()
	if(rand_s(&ab[i]) == 0)
		ab[i] = (unsigned int) ((double)ab[i] / ( (double) UINT_MAX + 1 ) * 9.0) + 1;
	else
		perror("rand_s");
	}
	
	printf_s("������� ����� %ux%u\n", ab[0], ab[1]);
	puts("������� �����, ������� <Enter>");
	printf_s("-> ");
	
	scanf_s("%u", &res);
	
	if (res != ab[0] * ab[1]) { //����� ����������
		printf_s("�� ��������. %ux%u = %u\n", ab[0], ab[1], ab[0] * ab[1]);
	}
	else
		puts("���������!");

	return 0;
}