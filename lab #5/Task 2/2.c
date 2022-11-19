/*
    В двумерной матрице размером NxM найти столбец 
    с наибольшей суммой элементов и удалить его.
*/
#include "arrays.h"

void inputn(int* n) {
    int x;
    while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    *n = x;
}
void inputm(int* m) {
    int x;
    while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    *m = x;
}

int** memory(int n, int m)
{
    int** arr;
    arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++){
        *(arr + i) = (int*)malloc(sizeof(int) * m);
    }
    return arr;
}

int main()
{
    int n, m = 0, mt, *arr;
    srand(time(NULL));
    printf("Input the size row: ");
        inputn(&n);
    printf("Input the size column: ");
        inputm(&m);
        arr = memory(n,m);
    input_matr(arr, n, m);
        printf("\nSource array: \n");
            print_matr(arr, n, m);
            arr = work_in_mat(arr, n, m);
            m--;
    printf("\nThe resulting array: \n");
            print_matr(arr, n, m);
   return 0;
}
