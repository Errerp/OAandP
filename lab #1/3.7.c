#include <stdio.h>
#include <math.h>

int main()
{
	int x1, x2, x3, y1, y2, y3;
		printf("Input the coordinates of the first point A - \n");
		scanf_s("%d%d", &x1, &y1);
		printf("Input the coordinates of the second point B - \n");
		scanf_s("%d%d", &x2, &y2);
		printf("Input the coordinates of the third point C - \n");
		scanf_s("%d%d", &x3, &y3);
	float A = sqrt(x1 * x1 + y1 * y1);
	float B = sqrt(x2 * x2 + y2 * y2);
	float C = sqrt(x3 * x3 + y3 * y3);
		if (A <= B && A <= C)
			{
				printf("The closest point to the ordinate axis - A (%d;%d)\n", x1, y1);
			}
		if (B <= A && B <= C)
			{
				printf("The closest point to the ordinate axis - B (%d;%d)\n", x2, y2);
			}
		if (C <= B && C <= A)
			{
				printf("The closest point to the ordinate axis - C (%d;%d)", x3, y3);
			}
			
	getch();
	return 0;
}