#include <stdio.h>

int main()
{
	int x, y, z;
	printf("Number of the car - ");
	for (int i = 0; i < 10; i++)
		for (int k = 1; k < 10; k++)
		{
			if (i + k == 15)
			{
				
				x = k * 1000 + i * 100 + i * 10 + k;
				y = i * 1000 + i * 100 + k * 10 + k;
				z = i * 1000 + k * 100 + i * 10 + k;
				if (x % 7 == 0 && x % 11 == 0 && x % 2 == 0)
				{
					printf("%d", x);
				}
				if (y % 7 == 0 && y % 11 == 0 && y % 2 == 0)
				{
					printf("%d", y);
				}
				if (z % 7 == 0 && z % 11 == 0 && z % 2 == 0)
				{
					printf("%d", z);
				}
				
				
				 
			}
		}


	getch();
	return 0;
}