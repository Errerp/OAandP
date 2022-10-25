#include <stdio.h>

int x, mass;
int prov() {
    while (scanf_s("%d", &x) != 1) {
        printf("Input error. Try again: ");
        rewind(stdin);
    }
}
int provmass() {
    while (scanf_s("%d", &mass) != 1 || mass < 1 || mass > 2)
    {
        printf("Input error. Try again: ");
        rewind(stdin);
    }
}

int main() {
    int i, j, arr[100][100], col, N, row, min, k;
    srand(time(NULL));
    printf("Input the size  N x N - ");
    prov();
    N = x;
    printf("Select the array input type\n1-Random\n2-Own\n");
    provmass();
    switch (mass)
    {
    case 1:
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                arr[i][j] = rand() % 200 - 100;
            }
        }
        printf("\n");
        break;
    case 2:
        printf("Input array elements - \n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                prov();
                arr[i][j] = x;
            }
            printf("\n");
        }
        break;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    min = arr[0][0];
    for (int i = N / 2 + 1, k = 0; i < N; i++, k++) {
        for (int j = N / 2 - k; j <= N / 2 + k; j++)
            if (arr[i][j] < min && arr[i][j] % 2 == 0) {
                min = arr[i][j];
            }
    }
    
    printf(" min = %d", min);
    return 0;
}