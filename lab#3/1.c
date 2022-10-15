#include <stdio.h>

int main()
{
    int N, i, large = 0, arr[100], C, proizv = 1, max = 0;
    printf("Input number of array elements\n");
    if (scanf_s("%d", &N) != 1)
    {
        printf("Error");
    }
    else
    {
        printf("Input array elements\n");
        for (i = 0; i < N; i++)
        {
            if (scanf_s("%d", &arr[i]) != 1)
            {
                printf("Error");
                return 0;
            }
        }
        printf("Input C\n");
        if (scanf_s("%d", &C) != 1)
        {
            printf("Error");
        }
        else {
            for (i = 0; i < N; i++)
            {
                if (arr[i] > C) large++;

            }
            printf("Number of array elements, large C = %d\n", large);

            for (i = 1; i < N; i++)
            {
                if (fabs(arr[i]) > fabs(arr[max]))
                {
                    max = i;
                }
            }
            for (i = max + 2; i < N; i++)
            {
                proizv *= arr[i];
            }
            printf("Composition = %d", proizv);
        }
    }
    return 0;
}