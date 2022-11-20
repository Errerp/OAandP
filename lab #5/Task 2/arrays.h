#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// печать матрицы
void print_row(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%5d", arr[i]); // arr[i]
    printf("\n");
}
void print_matr(int** matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        print_row(matr[i], m);

}

// ввод элементов матрицы
void input_row(int* arr, int n)
{
    //srand(time(NULL));
    for (int i = 0; i < n; i++)
        *(arr + i) = rand() % 10;
}

void input_matr(int** matr, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
        input_row(*(matr + i), m);
}
// работа в матрице
int** work_in_mat(int* arr, int n, int m)
{
    int i, j, sum, max = 0, num = 0;
   for (j = 0; j < m; j++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += *(arr + i * n + j);
        }
        if (sum > max) {
            max = sum;
            num = j;
        }
    }
    for (j = num; j < m; j++) {
        for (i = 0; i < n; i++)
        {
            *(arr + i * n + j) = *(arr + i * n + j + 1);
        }
    }
    m--;
    arr = (int**)realloc(arr, m * sizeof(int*));
    for (int i = 0; i < n; i++) {
        *(arr + i) = (int*)realloc(arr,m * sizeof(int));
    }
    return arr;
}
