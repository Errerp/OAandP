#include "arrays.h"

void input_size(int* n) {
	int x;
	while (scanf_s("%d", &x) != 1 || x < 1 || getchar() != '\n') {
		printf("������. ���������� �����: ");
		rewind(stdin);
	}
	*n = x;
}
//��������� ������ ��� �������
int* memory(int n, int m)
{
	int** matr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		*(matr + i) = (int*)calloc(m, sizeof(int));
	return matr;
}
void* libertad(int n, int** matr) {
	for (int i = 0; i < n; i++)
		free(*(matr + i));
	free(matr);
}
int chooseinput(int* matr, int n, int m) {
	int x;
	while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
		printf("������. ���������� �����: ");
		rewind(stdin);
	}
	switch (x)
	{
	case 1:
		input_matr(matr, n, m);
		break;
	case 2:
		rand_matr(matr, n, m);
		break;
	}
	return matr;
}
// ������ �������
void print_matr(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%5d", *(*(matr + i) + j));
		}
		printf("\n");
	}
}

// ���� ��������� ������� c ����������
void input_matr(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("������� ������� [%d][%d]\n", i + 1, j + 1);
			while (scanf_s("%d", *(matr + i) + j) != 1) {
				printf("������. ���������� �����:\n");
				rewind(stdin);
			}
		}
	}
}
// ���� ��������� ������� ��������
void rand_matr(int** matr, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			*(*(matr + i) + j) = rand() % 6;
		}
	}
}
// ������ � �������
void work_in_matr(int** matr, int n, int m)
{
	int max = 0, colmax = 0;
	for (int j = 0; j < m; j++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += *(*(matr + i) + j);
			if (sum > max) {
				max = sum;
				colmax = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {

		for (int j = colmax; j < m - 1; j++) {
			*(*(matr + i) + j) = *(*(matr + i) + j + 1);
		}
		*(matr + i) = realloc(*(matr + i), (m - 1) * sizeof(int));
	}
}