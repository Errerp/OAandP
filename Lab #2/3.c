#include <stdio.h>

int main()
{
	int x = 0;
	int fib = 1;
	int N;
	printf("Input number -");
	scanf_s("%d", &N);
	for(int i = 1; i <= N ; i++)
	{
		if (i == x + fib)
		{
			x = fib;
			fib = i;
		}
	}
	if (N == fib || N == 0)
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
