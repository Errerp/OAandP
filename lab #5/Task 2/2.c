/*
    В двумерной матрице размером NxM найти столбец 
    с наибольшей суммой элементов и удалить его.
*/
#include "Arrays.h"

void inputrow(int* row) {
    int x;
    while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    *row = x;
}
void inputcol(int* col) {
    int x;
    while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    *col = x;
}

int** memory(int row, int col)
{
    int** arr;
    arr = (int**)calloc(col, sizeof(int*));
    for (int j = 0; j < row; j++)
    {
        arr[j] = (int*)calloc(col, sizeof(int)); //*(arr + i)
    }
    return arr;
}

void chooseinput(int* mt) {
    int x;
    while (scanf_s("%d", &x) != 1 || x > 100 || x < 1 || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    *mt = x;
}

int main()
{
    int row, col = 0, mt, *arr;
    srand(time(NULL));
    printf("Input the size row: ");
        inputrow(&row);
    printf("Input the size column: ");
        inputcol(&col);
        arr = memory(row,col);
    printf("Select the array input type:\n1)Own\n2)Random\n");
        chooseinput(&mt);
    switch (mt)
    {
        case 1:
            printf("\nInput array elements: \n");
            inputarr(arr, row, col);
            break;
        case 2:
            randarr(arr, row, col);
            break;
    }
        printf("\nSource array: \n");
            printarr(arr, row, col);
            workarr(arr, row,col);
            col--;
    printf("\nThe resulting array: \n");
            printarr(arr, row, col);
   return 0;
}
