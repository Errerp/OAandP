#include "Arrays.h"

int main()
{
    int i, j, row, col, mt;
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    printf("Êîë-âî ñòðîê: ");
    while (scanf_s("%d", &row) != 1 || row % 1!= 0 || row > 100 || row < 1) {
        printf("Îøèáêà. Ïðîáóéòå ñíîâà: ");
    }
    printf("Êîë-âî ñòîëáöîâ: ");
    while (scanf_s("%d", &col) != 1 || col  % 1 != 0 || col > 100 || col < 1) {
        printf("Îøèáêà. Ïðîáóéòå ñíîâà: ");
    }
    int* arr = (int*)malloc(row * col * sizeof(int));
        printf("Âûáåðèòå ñïîñáî ââîäà ìàòðèöû:\n1)Âðó÷íóþ\n2)Ðàíäîìîì\n");
    while (scanf_s("%d", &mt) != 1 || col % 1 != 0 || mt < 1 || mt > 2) {
        printf("Îøèáêà. Ïðîáóéòå ñíîâà: ");
    }
    
    switch (mt)
    {
        case 1:
            printf("\nÂâåäèòå ýëåìåíòû ìàññèâà: \n");
            inputarr(arr, row, col);
            break;
        case 2:
            randarr(arr, row, col);
            break;
    }
        printf("\nÈñõîäíûé ìàññèâ: \n");
            printarr(arr, row, col);
            workarr(arr, row, col);
            col--;
        printf("\nÈòîãîâûé ìàññèâ: \n");
            printarr(arr, row, col);
    return 0;
}
