#include <stdio.h>
#include <locale.h>
#define kl 9
int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, i, R[kl], m2[kl], k;
	printf("заполните массив целыми числами\n");
	for (i = 0; i < kl; i++)
	{
		scanf_s("%d", &R[i]);
	}
	for (i = 0; i < kl; i++)
	{
		if (R[i] > 0 && R[i] % 2 == 1)
		{
			m2[i] = R[i];
		}
	}
	for (i = 0; i < kl; i++)
	{
		for (k = 0; k < kl; k++)
		{
			if (m2[k + 1] > m2[k])
			{
				a = m2[k];
				m2[k] = m2[k + 1];
				m2[k + 1] = a;
			}
		}
	}
	for (i = 0; i < kl; i++)
	{
		if (m2[0] == R[i])
		{
			b = i;
		}
	}
	printf_s("индекс - %d", b);
	return(0);
}
