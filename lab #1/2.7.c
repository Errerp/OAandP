#include <stdio.h>

int main()
{
	int a, b, c;
	printf("Input 3 numbers - ");
	scanf_s("%d%d%d", &a, &b, &c);

	int d = a;
	if (b > d)
	{
		d = b;
	}
	if (c > d)
	{
		d = c;
	}
	printf("The largest number = %d", d);

	getch();
	return 0;
}