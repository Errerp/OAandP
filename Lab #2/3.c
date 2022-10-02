#include <stdio.h>

int main()
{
	int x = 0;
	int y = 1;
	int fib, N;
	printf("Input number -");
	scanf_s("%d", &N);
	for(int i = 1; i <= N ; i++)
	{
		if (i == x + y)
		{
			fib = i;
			x = y;
			y = i;
		}
	}
	if (N == fib)
	{
		printf("True");
	}
	else
	{
		printf("False");
	}

	getch();
	return 0;
}