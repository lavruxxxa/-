#include<stdio.h.>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
vvod:
	printf("введите натуральные числа(больше нуля, целые)\n");
	int i, k=0, a, b;
	rewind(stdin);
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	if (a < 0 || b < 0)
	{
		printf("Числа не натуральные, попробуйте еще раз\n"); 
		goto vvod;
	}
	if (a > b)
	{
		for (i = 1; i <= b; i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				k = k + 1;
			}
		}
	}
	else
	{
		for (i = 1; i <= a; i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				k = k + 1;
			}
		}
	}
	if (k >= 2)
	{
		printf("Числа имеют хотя бы 2 общих множителя");
	}
	else
	{
		printf("Числа не имеют хотя бы 2 общих множителя");
	}
	return(0);
}