#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	double num, max, min, sum = 0;
	int count, i;
	
	setlocale(LC_ALL, "RUS");

	puts("Обработка последовательности дробных чисел");
	printf_s("Введите количество чисел последовательности -> ");
	scanf_s("%d", &count);
	puts("Вводите последовательность. После каждого числа нажимайте <Enter>");
	
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

	printf_s("Среднее арифметическое: %.3lf\n" 
		"Минимальное число: %.3lf\n"
		"Максимальное число: %.3lf\n",
		(sum / count), min, max);
	puts("Для завершения нажмите <Enter>"); //Завершаем программу с кодом 0 по нажатию на Enter
	if(_getch() == 13)
		return 0;
}