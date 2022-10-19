#include <stdio.h>

int main()
{
    int N, i,mass, k, arr[100], j;
    srand(time(0));
    printf("Input number of array elements\n");
    if (scanf_s("%d", &N) != 1)
    {
        printf("Input error");
        return 0;
    }
    printf("Select the array input type\n1-Random\n2-Own\n");
    scanf_s("%d", &mass);
    switch (mass){
    case 1:
        for (i = 0; i < N; i++) {
            arr[i] = rand() % 100;
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 2:
        printf("Input array elements\n");
        for (i = 0; i < N; i++){
            if (scanf_s("%d", &arr[i]) != 1){
                printf("Input error");
                return 0;
            }
        }
        break;
    default:
        printf("Input error");
        return 0;
    }
    printf("Input k\n");
            if (scanf_s("%d", &k) != 1){
                printf("Input error");
                return 0;
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
