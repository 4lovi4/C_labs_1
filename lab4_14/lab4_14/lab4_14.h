#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SIZEA 10
#define from1ton(ind, size) for(ind=0; ind < size; ind++)

char man_or_rand(); // Функция выбора ручного или случайного ввода массива
int rand_array(int *a); // Функция случайного ввода массива