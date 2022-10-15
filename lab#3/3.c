#include <stdio.h>

int main()
{
    int N, i, j, num, arr[100];
    int CurrentCounter = 0, BiggestCounter = 0;
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
   
    }
    return 0;
}