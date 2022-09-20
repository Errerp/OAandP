#include <stdio.h>

int main()
{
	int a, b, c;
	printf("Write first number - ");
	scanf_s("%d", &a);
	printf("\nWrite second number - ");
	scanf_s("%d", &b);
	printf("\nWrite the third number - ");
	scanf_s("%d", &c);
	int d = a;
	if (b > d)
	{
		d = b;
	}
	if (c > d)
	{
		d = c;
	}
	printf("\nThe largest number = %d", d);

	getch();
	return 0;
}