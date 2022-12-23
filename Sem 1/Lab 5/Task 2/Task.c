/*
	В двумерной матрице размером NxM найти столбец
	с наибольшей суммой элементов и удалить его.(удаляет первый если несколько)
*/
#include "arrays.h"

void main() {
	setlocale(LC_ALL, "Russian");
	int  m, n, ** matr;
	srand(time(NULL));
	printf("Введите кол-во строк: ");
		input_size(&n);
	printf("Введите кол-во столбцов: ");
		input_size(&m);
	matr = memory(n, m);
	printf("Выберите тип ввода\n1) Клавиатура\n2) Рандом\n");
		chooseinput(matr, n, m);
	printf("\n\nНачальная матрица:\n\n");
		print_matr(matr, n, m);
			work_in_matr(matr, n, m);
	m--;
	printf("\n\nИтоговая матрица:\n\n");
		print_matr(matr, n, m);
		libertad(n, matr);
	return 0;
}
