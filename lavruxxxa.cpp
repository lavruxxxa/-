#include<iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("введите натурпальные числа(больше нуля, целые)\n");
	int i, k, a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	k = 0;
	if (a < 0 && b < 0)
	{
		printf("я же написал, натуральные числа. начинайте заного\n");
		return(0);
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