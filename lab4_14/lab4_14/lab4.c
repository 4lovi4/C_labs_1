#include "lab4_14.h"

int main(int argc, char **argv)
{
	int arr[SIZEA],
		temp,i,j,k,
		co = 0, // счетчик не min и не max элементов массива 
		sum = 0; // сумма не min и не max элементов массива
	char yn; // маркер метода ввода массива
	
	//Только для задачи 2:
	int sum_in, // Число сравниваемое с суммой элементов массива
		stack[SIZEA]; // Массив, куда временно будут помещаться элементы основного массива, 
					  // чтобы их потом вывести, в случае если их сумма равна заданному числу	
		int pset_size; //Колличесво всех возможных подмножеств массива + пустое подмножество
	// Первое задание:
	// Найти среднее арифметическое элементов массива min и max

	setlocale(LC_ALL, "RUS");
	printf_s("Среднее арифметическое без учета max и min значений массива из 10 чисел.\n");
	yn = man_or_rand();
	printf_s("man_or_rand = %c\n", yn);	
	switch(yn) {
		case 'r': 
			rand_array(arr);
			break;
		case 'm':
			from1ton(i, SIZEA)
				scanf_s("%d", &arr[i]);
			break;
	}
	printf_s("Массив: \n");
	from1ton(i, SIZEA)
		printf_s("%d ", arr[i]);
	printf_s("\n");
	//Отсортируем массив прямым методом по возрастанию:
	from1ton(i, (SIZEA - 1)) {
		k = i;
		for(j = i + 1; j < SIZEA; j++) 
			if(arr[j] < arr[k]) 
				k = j;
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
	//Массив отсортирован
	printf_s("Отсортированный Массив: \n");
	from1ton(i, SIZEA) {
		printf_s("%d ", arr[i]);
		if((arr[i] != arr[0]) && (arr[i] != arr[SIZEA - 1])) {
			co++;
			sum += arr[i];
		}
	}
	printf_s("\n");
	//Считаем и выводим среднее арифмитеское массива без max и min
	printf_s("Искомое ср. арифметическое = %.2f\n", (float)sum / co);
	
	// Второе задание: 
	// Найти на заданном массиве элементы сумма которых = заданноиу числу
	
	printf_s("Ввести целое число для поиска элементов массива, составляющих сумму равную этому числу:\n ");
	scanf_s("%d", &sum_in);
	printf_s("Вы ввели число: %d\n", sum_in);
	sum = 0;
	from1ton(i, SIZEA){
		sum += arr[i];
	}
	
	if (sum_in > sum) {
		printf_s("Cумма всех лементов массива меньше заданного числа\n");
		return 1;
	}
	
	pset_size = (int)pow(2.0, SIZEA);
	
	for(i = 0; i < pset_size; i++) { // Поиск всех подмножеств элементов массива и их суммы = введенному числу
		k = 0;
		sum = 0;
		memset(stack,0,SIZEA);
		for(j = 0; j < SIZEA; j++) {
			if(i & (1 << j)) {
				//printf_s("%d ", arr[j]);
				sum += arr[j];
				stack[k] = arr[j];
				k++;
			}
		}
		//printf_s("Сумма %d = %d\n", j, sum);
		if(sum == sum_in) {
			printf_s("Заданному числу %d = сумма элементов: ", sum_in);
			for(co = 0; co < k; co++) 
				printf_s("%d ", stack[co]);
			printf_s("\n");
		}
	}
	return 0;
}
