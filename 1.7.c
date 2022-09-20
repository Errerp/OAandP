#include <stdio.h>

int main()
{
	float pi = 3.14;
	float rad = 0;
	printf("Write the radius \n");
	scanf_s("%f", &rad);
	float length = 2 * pi * rad;						
	float area = pi * rad * rad;						
	printf("Circumference length = %.2f \n", length);
	printf("Area of the circle = %.2f \n", area);

	getch();
	return 0;
}