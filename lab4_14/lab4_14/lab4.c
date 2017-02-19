#include "lab4_14.h"

int main(int argc, char **argv)
{
	int arr[SIZEA],
		temp,i,j,k,
		co = 0, // ������� �� min � �� max ��������� ������� 
		sum = 0; // ����� �� min � �� max ��������� �������
	char yn; // ������ ������ ����� �������
	
	//������ ��� ������ 2:
	int sum_in, // ����� ������������ � ������ ��������� �������
		stack[SIZEA]; // ������, ���� �������� ����� ���������� �������� ��������� �������, 
					  // ����� �� ����� �������, � ������ ���� �� ����� ����� ��������� �����	
		int pset_size; //���������� ���� ��������� ����������� ������� + ������ ������������
	// ������ �������:
	// ����� ������� �������������� ��������� ������� min � max

	setlocale(LC_ALL, "RUS");
	printf_s("������� �������������� ��� ����� max � min �������� ������� �� 10 �����.\n");
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
	printf_s("������: \n");
	from1ton(i, SIZEA)
		printf_s("%d ", arr[i]);
	printf_s("\n");
	//����������� ������ ������ ������� �� �����������:
	from1ton(i, (SIZEA - 1)) {
		k = i;
		for(j = i + 1; j < SIZEA; j++) 
			if(arr[j] < arr[k]) 
				k = j;
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
	//������ ������������
	printf_s("��������������� ������: \n");
	from1ton(i, SIZEA) {
		printf_s("%d ", arr[i]);
		if((arr[i] != arr[0]) && (arr[i] != arr[SIZEA - 1])) {
			co++;
			sum += arr[i];
		}
	}
	printf_s("\n");
	//������� � ������� ������� ������������ ������� ��� max � min
	printf_s("������� ��. �������������� = %.2f\n", (float)sum / co);
	
	// ������ �������: 
	// ����� �� �������� ������� �������� ����� ������� = ��������� �����
	
	printf_s("������ ����� ����� ��� ������ ��������� �������, ������������ ����� ������ ����� �����:\n ");
	scanf_s("%d", &sum_in);
	printf_s("�� ����� �����: %d\n", sum_in);
	sum = 0;
	from1ton(i, SIZEA){
		sum += arr[i];
	}
	
	if (sum_in > sum) {
		printf_s("C���� ���� �������� ������� ������ ��������� �����\n");
		return 1;
	}
	
	pset_size = (int)pow(2.0, SIZEA);
	
	for(i = 0; i < pset_size; i++) { // ����� ���� ����������� ��������� ������� � �� ����� = ���������� �����
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
		//printf_s("����� %d = %d\n", j, sum);
		if(sum == sum_in) {
			printf_s("��������� ����� %d = ����� ���������: ", sum_in);
			for(co = 0; co < k; co++) 
				printf_s("%d ", stack[co]);
			printf_s("\n");
		}
	}
	return 0;
}
