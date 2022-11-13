#include "Arrays.h"

int main()
{
    int i, j, row, col, mt;
    srand(time(NULL));
    printf("Input the size row: ");
    while (scanf_s("%d", &row) != 1 || row % 1!= 0 || row > 100 || row < 1) {
        printf("Error. Try again: ");
    }
    printf("Input the size column: ");
    while (scanf_s("%d", &col) != 1 || col  % 1 != 0 || col > 100 || col < 1) {
        printf("Error. Try again: ");
    }
    int* arr = (int*)malloc(row * col * sizeof(int));
        printf("Select the array input type:\n1)Own\n2)Random\n");
    while (scanf_s("%d", &mt) != 1 || col % 1 != 0 || mt < 1 || mt > 2) {
        printf("Error. Try again: ");
    }
    
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
            workarr(arr, row, col);
            col--;
        printf("\nThe resulting array: \n");
            printarr(arr, row, col);
    return 0;
}