#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SIZEA 10
#define from1ton(ind, size) for(ind=0; ind < size; ind++)

int main(int argc, char **argv)
{
	int i, j,
	arr[SIZEA][SIZEA],
	sum, max_sum, i_max;
	int *barr[SIZEA], *p;
	
	struct sum_ind    // В структуре запоминаем сумму конкретной строки и её изначальный номер
	{
		int s;
		int index;
	} si[SIZEA], swap_si;
	
	setlocale(LC_ALL, "RUS");
	printf_s("В результирующем массиве сохранить указатели на строки заданного массива,\n"
		"отсортированные по убыванию суммы элементов: \n\n");
	srand((unsigned)time(NULL));
	from1ton(i, SIZEA) {
		sum = 0;
		from1ton(j, SIZEA) {
			arr[i][j] = (double)rand() / (RAND_MAX + 1) * 99;
			sum += arr[i][j];
			printf_s("%3d", arr[i][j]);
		}
		si[i].s = sum;
		si[i].index = i;
		printf("\n");
	}
	printf_s("=======================================================\n");
	
	from1ton(i, (SIZEA - 1)) {			// Сортируем по убыванию массив структур суммы-индекса
		i_max = i;
		for (j = i + 1; j < SIZEA; j++)
			if(si[j].s > si[i_max].s) 
				i_max = j;
		swap_si = si[i];
		si[i] = si[i_max];
		si[i_max] = swap_si;
	}
	printf_s("Проверка вывода результирующего массива указателей: \n\n");
	from1ton(i, SIZEA) {
		barr[i] = &arr[si[i].index][0];
		p = barr[i];
		for (j = 0; j < SIZEA; j++){
			printf_s("%3d", *p);
			p++;
		}
		printf_s(" Сумма элементов = %d\n", si[i].s);
	}
	return 0;
}