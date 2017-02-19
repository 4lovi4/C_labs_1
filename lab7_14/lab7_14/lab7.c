#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <io.h>
#include <stdlib.h>

#define BSIZE 100

void swap_el(int *a, int *b);

int main(int argc, char** argv)
{
	int result[BSIZE], 
		i, n, imax, imin;
	char fname1[80] = ".\\1.txt",
	fname2[80] = ".\\2.txt",
	buf[100];
	FILE *fi;
	errno_t o_ret;
	size_t rb;
	setlocale(LC_ALL,"RUS");
	printf_s("������������ ������ � 7 ������� 14:\n"
		"������ � �������.\n");
	printf_s("������ = %d \n", ' ');
	o_ret = fopen_s(&fi, fname1, "r+t");
	if(o_ret) {
		printf_s("������ �������� �����\n");
		exit(1);
	}
	
	// ���������� ���������� ���������� ����� � ������ ��� ��������� � ������
	memset(result, 0, BSIZE);
	n = 0;
	i = 0;
	memset(buf, 0, sizeof(buf) / sizeof(char));
	while (!feof(fi))
	{
		rb = fread(&buf[i], sizeof(char), 1, fi);
		if(buf[i] == 32) {
			buf[i] = '\0';
			result[n] = atoi(buf);
			n++;
			i = 0;
			memset(buf, 0, sizeof(buf) / sizeof(char));
		}
		else if (rb == 0) {
			buf[i] = '\0';
			result[n] = atoi(buf);
			break;
		}
		else 
			i++;
		//printf_s("��������� %u ����\n", rb);
	}
	//
	// ����� ��� ����������� �������� ������
	
	printf_s("����������� �� ����� ������ ������� �� %d ���������: \n", n + 1);
	for(i = 0; i < n + 1; i++) {
		printf_s("%d ", result[i]);
	}
	printf_s("\n");
	
	// ������� ������� � �������� �������
	imax = 0;
	for(i = imax + 1; i < (n + 1); i++) {
		if( result[i] > result[imax])
			imax = i;
	}
	//
	imin = 0;
	for(i = imin + 1; i < (n + 1); i++) {
		if( result[i] < result[imin])
			imin = i;
	}
	
	// �������� ������� max � min �������� � ������� ������� ���� ����: 
	
	swap_el(&result[imax], &result[imin]);

	fclose(fi);

	o_ret = fopen_s(&fi, fname2, "w+t");
	if(o_ret) {
		printf_s("������ �������� �����\n");
		exit(1);
	}

	printf_s("������ ����� ������ ������� min � max:\n"
		"(����� ����� ������� � ���� %s) \n", fname2);
	for(i = 0; i < n + 1; i++){
		fprintf_s(fi, "%d ", result[i]);
		printf_s("%d ", result[i]);
	}
	printf_s("\n");
	
	fclose(fi);
	
	return 0;
}

void swap_el(int *a, int *b)
{
	*a = *a + *b;
	*b = *a  - *b;
	*a = *a - *b;
 }