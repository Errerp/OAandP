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
                    printf("%d%c", arr[i], ' ');
                }
                printf("\n");
                i = 0;
                while (i < N)
                {
                    if (arr[i] % k == 1)
                    {
                        for (j = N; j > i; j--)
                        {
                            arr[j] = arr[j - 1];
                        }
                            N++;
                            arr[i + 1] = 0;
                    }
                    i++;
                }
                for (i = 0; i < N; i++)
                {
                    printf("%d%c", arr[i], ' ');
                }
            }
        }
	return 0;
}