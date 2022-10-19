#include <stdio.h>

int main()
{
    int N, i,mass, large = 0, arr[100], C, proizv = 1, max = 0;
    srand(time(0));
    printf("Input number of array elements\n");
    if (scanf_s("%d", &N) != 1)
    {
        printf("Input error");
        return 0;
    }
    printf("Select the array input type\n1-Random\n2-Own\n");
    scanf_s("%d", &mass);
    switch (mass)
    {
    case 1:
        for (i = 0; i < N; i++) {
            arr[i] = rand() % 100;
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 2:
        printf("Input array elements\n");
        for (i = 0; i < N; i++)
        {
            if (scanf_s("%d", &arr[i]) != 1)
            {
                printf("Input error");
                return 0;
            }
        }
        break;
    default:
        printf("Input error");
        return 0;
    }
        printf("Input C\n");
        if (scanf_s("%d", &C) != 1)
        {
            printf("Input error");
            return 0;
        }
            for (i = 0; i < N; i++)
            {
                if (arr[i] > C)
                {
                    large++;
                }
            }
            printf("Number of array elements, large C = %d\n", large);
            for (i = 1; i < N; i++)
            {
                if (arr[i] > arr[max])
                {
                    max = i;
                }
            }
            for (i = max + 1; i < N; i++)
            {
                proizv *= arr[i];
            }
            printf("Composition = %d", proizv);
    return 0;
}
