#include <stdio.h>

int main()
{
    int N, i, mass, k, j, arr[100];
    srand(time(0));
    printf("Input number of array elements\n");
    while (scanf_s("%d", &N) != 1)
    {
        printf("Input error. Try again: ");
        rewind(stdin);
    }
    printf("Select the array input type\n1-Random\n2-Own\n");
    while (scanf_s("%d", &mass) != 1)
    {
        printf("Input error. Try again: ");
        rewind(stdin);
    }
    switch (mass)
    {
    case 1:
        for (i = 0; i < N; i++) {
            arr[i] = rand() % 200 - 100;
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 2:
        printf("Input array elements\n");
        for (i = 0; i < N; i++)
        {
            while (scanf_s("%d", &arr[i]) != 1)
            {
                printf("Input error. Try again: ");
                rewind(stdin);
            }
        }
        break;
    }
    printf("Input k\n");
    while (scanf_s("%d", &k) != 1)
    {
        printf("Input error. Try again: ");
        rewind(stdin);
    }
            for (i = N; i > 0; i--){
                    if (i % k == 0){
                        N++;
                        for (j = N; j > i; j--){
                            arr[j] = arr[j - 1];
                        }
                        arr[i + 1] = 0;
                    }
            }
                for (i = 0; i < N; i++){
                    printf("%d ", arr[i]);
                }
	return 0;
}
