#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, i, a;
	for (i = 0; ; )
	{
		printf_s("введите натуральное число ");
		scanf_s("%d", &n);
		if (n > 0)
		{
			break;
		}
		else
		{
			printf("число не натуральное, попробуйте еще раз\n");
		}
	}
	a = n / 50;
	printf_s("50 - %d\n", a);
	n = n % 50;
	a = n / 20;
	printf_s("20 - %d\n", a);
	n = n % 20;
	a = n / 15;
	printf_s("15 - %d\n", a);
	n = n % 15;
	a = n / 10;
	printf_s("10 - %d\n", a);
	n = n % 10;
	a = n / 5;
	printf_s("5 - %d\n", a);
	n = n % 5;
	a = n / 3;
	printf_s("3 - %d\n", a);
	n = n % 3;
	a = n / 2;
	printf_s("2 - %d\n", a);
	n = n % 2;
	printf_s("1 - %d\n", n);
	return(0);
}