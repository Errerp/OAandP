#include "Arrays.h"

int main()
{
    int i, j, row, col, mt;
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    printf("���-�� �����: ");
    while (scanf_s("%d", &row) != 1 || row % 1!= 0 || row > 100 || row < 1) {
        printf("������. �������� �����: ");
    }
    printf("���-�� ��������: ");
    while (scanf_s("%d", &col) != 1 || col  % 1 != 0 || col > 100 || col < 1) {
        printf("������. �������� �����: ");
    }
    int* arr = (int*)malloc(row * col * sizeof(int));
        printf("�������� ������ ����� �������:\n1)�������\n2)��������\n");
    while (scanf_s("%d", &mt) != 1 || col % 1 != 0 || mt < 1 || mt > 2) {
        printf("������. �������� �����: ");
    }
    
    switch (mt)
    {
        case 1:
            printf("\n������� �������� �������: \n");
            inputarr(arr, row, col);
            break;
        case 2:
            randarr(arr, row, col);
            break;
    }
        printf("\n�������� ������: \n");
            printarr(arr, row, col);
            workarr(arr, row, col);
            col--;
        printf("\n�������� ������: \n");
            printarr(arr, row, col);
    return 0;
}