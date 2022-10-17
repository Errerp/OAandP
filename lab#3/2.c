#include <stdio.h>

int main()
{
    int N, i, k, arr[100], j;
    printf("Input number of array elements\n");
        if (scanf_s("%d", &N) != 1)
	    {
		    printf("Error");
	    }
        else 
        {
            printf("Input k\n");
            if (scanf_s("%d", &k) != 1)
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
                for (i = 0; i < N; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                for (i = N; i > 0; i--)
                {
                    if (i % k == 0)
                    {
                        N++;
                        for (j = N; j > i; j--)
                        {
                            arr[j] = arr[j - 1];
                        }
                        arr[i + 1] = 0;
                    }
                }
                for (i = 0; i < N; i++)
                {
                    printf("%d ", arr[i]);
                }
            }
        }
	return 0;
}
