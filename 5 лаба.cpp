#include <stdio.h>
#include <locale.h>
#define m 3
#define n 3
int main()
{
	setlocale(LC_ALL, "Rus");
	int a=0, b=0, c=0, i, j, A[m][n];
	printf("заполните матрицу\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			scanf_s("%d", &A[i][j]);

	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (A[i][j] > 0)
			{
				a += 1;
			}
			if (A[i][j] < 0)
			{
				b += 1;
			}
			if (A[i][j] == 0)
			{
				c += 1;
			}
		}
	}
	printf("больше нуля - %d\n", a);
	printf("меньше нуля - %d\n", b);
	printf("равных нулю - %d\n", c);
	return(0);
}