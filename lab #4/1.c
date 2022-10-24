#include <stdio.h>
int N, mass;
int prov(){
    while (scanf_s("%d", &N) != 1) {
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
    

int main(){
    int i,j, arr[100][100], col, row,count = 0, num = 0;
    srand(time(0));
    printf("Input the size row - ");
    prov();
    row = N;
    printf("Input the size column - ");
    prov();
    col = N;
    printf("Select the array input type\n1-Random\n2-Own\n");
    provmass();
    switch (mass)
    {
    case 1:
        for (i = 1; i <= row; i++){
            for(j = 1; j <= col; j++){
                arr[i][j] = rand() % 200 - 100;
            }
        }
        printf("\n");
        break;
    case 2:
        printf("Input array elements - \n");
        for (i = 1; i <= row; i++){
            for (j = 1; j <= col; j++){
                prov();
                arr[i][j] = N;
            }
            printf("\n");
        }
        break;
    }
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (j = 1; j <= col; j++){
        for (i = 1; i <= row; i++){
            if (arr[i][j] == 0) {
                count++;
            }
        }
    }
    printf("The number of columns having 0 - %d \n", count);
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            if (arr[i][j] == arr[i][j + 1]){
                num = i;
            }
        }
    }
    printf("The row number - %d", num);
    return 0;
}