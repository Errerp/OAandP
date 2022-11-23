/*
	В двумерной матрице размером NxM найти столбец
	с наибольшей суммой элементов и удалить его.(удаляет первый если несколько)
*/
#include "arrays.h"
void inputcol(int* m) {
	int x;
	while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
		printf("Error. Try again: ");
		rewind(stdin);
	}
	*m = x;
}
void inputrow(int* n) {
	int x;
	while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
		printf("Error. Try again: ");
		rewind(stdin);
	}
	*n = x;
}
int chooseinput(int* matr, int n, int m) {
	int x;
	while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
		printf("Error. Try again: ");
		rewind(stdin);
	}
	switch (x)
	{
	case 1:
		printf("\nInput array elements: \n");
		input_matr(matr, n, m);
		break;
	case 2:
		rand_matr(matr, n, m);
		break;
	}
	return matr;
}
void main() {
	int  m, n, ** matr;
	srand(time(NULL));
	printf("Input the size row: ");
		inputrow(&n);
	printf("Input the size column: ");
		inputcol(&m);
	matr = memory(n, m);
	printf("Select the array input type:\n1)Own\n2)Random\n");
		chooseinput(matr, n, m);
	printf("\nSource array: \n");
		print_matr(matr, n, m);
			work_in_matr(matr, n, m);
	m--;
	printf("\nThe resulting array: \n");
		print_matr(matr, n, m);
		libertad(n, matr);
	printf("\n");
}
