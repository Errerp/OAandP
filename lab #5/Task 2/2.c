#include "Arrays.h"

int main()
{
    int i, j, row, col, mt;
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    printf("Кол-во строк: ");
    while (scanf_s("%d", &row) != 1 || row % 1!= 0 || row > 100 || row < 1) {
        printf("Ошибка. Пробуйте снова: ");
    }
    printf("Кол-во столбцов: ");
    while (scanf_s("%d", &col) != 1 || col  % 1 != 0 || col > 100 || col < 1) {
        printf("Ошибка. Пробуйте снова: ");
    }
    int* arr = (int*)malloc(row * col * sizeof(int));
        printf("Выберите спосбо ввода матрицы:\n1)Вручную\n2)Рандомом\n");
    while (scanf_s("%d", &mt) != 1 || col % 1 != 0 || mt < 1 || mt > 2) {
        printf("Ошибка. Пробуйте снова: ");
    }
    
    switch (mt)
    {
        case 1:
            printf("\nВведите элементы массива: \n");
            inputarr(arr, row, col);
            break;
        case 2:
            randarr(arr, row, col);
            break;
    }
        printf("\nИсходный массив: \n");
            printarr(arr, row, col);
            workarr(arr, row, col);
            col--;
        printf("\nИтоговый массив: \n");
            printarr(arr, row, col);
    return 0;
}