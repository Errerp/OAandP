#include <stdio.h>

int main()
{
    int N, i,mass, j, num, arr[100];
    int CurrentCounter = 0, BiggestCounter = 0;
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
        for (int i = 0; i < N; i++)
        {
                for (int j = i; j < N; j++)
                {
                    if (arr[i] == arr[j])
                    {
                        CurrentCounter++;
                    }
                }
                if (CurrentCounter > BiggestCounter)
                {
                    BiggestCounter = CurrentCounter;
                    num = arr[i];
                }
                    CurrentCounter = 0;
        }
            printf("Element = %d\n", num);
    return 0;
}