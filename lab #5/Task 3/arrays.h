#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//выделение памяти под матрицу
int* memory(int n, int m)
{
	int** matr = (int**)malloc(n * sizeof(int*));
	return matr;
}
// печать матрицы
void print_matr(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%5d", *(*(matr + i) + j));
		}
		printf("\n");
	}
}

// ввод элементов матрицы c клавиатуры
void input_matr(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("input element [%d][%d]\n", i + 1, j + 1);
			while (scanf_s("%d", *(matr + i) + j) != 1) {
				printf("input error\n");
				rewind(stdin);
			}
		}
	}
}
// ввод элементов матрицы рандомом
void rand_matr(int** matr, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			*(*(matr + i) + j) = rand() % 6;
		}
	}
}
// работа в матрице
void work_in_matr(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + j < n) {
				printf("%5d ", *(*(matr + i) + j));
			}
		}
		printf("\n");
	}
}
