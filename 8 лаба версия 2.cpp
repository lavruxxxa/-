// 2. Дан текст.Слова в тексте разделены пробелами и знаками препинания.Получить n наиболее часто встречающихся слов и число их появлений.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	char* s = NULL;
	int size1, i, j, pos1 = 0, pos2, size2 = 0, num = 0, x=0, size = 0;
	do
	{

		do
		{
			system("CLS");
			rewind(stdin);
			printf("введите размерность строки = ");
		} while (!scanf_s("%d", &size1) || size1 <= 0);
		if (!(s = (char*)calloc(size1, sizeof(char))))
		{
			printf("\nНедостаточно свободной памяти \n");
			s = NULL;
		}
	} while (!s);
	printf("Вводите текст - ");
	rewind(stdin);
	gets_s(s, size1);
	system("CLS");
	if (*s == '\0')
	{
		printf("вы ничего не ввели");
		return 0;
	}
	printf("Ваш текст:\n");
	puts(s);
	char** slova = NULL;
	slova = (char**)calloc(size2, sizeof(char*));
	for (i = 0; i < size1; i++)
	{
		if (*(s + i) >= 'A' && *(s + i) <= 'z' || *(s + i) >= 'А' && *(s + i) <= 'я' )
		{
			pos1 = i;
			while (*(s + i) >= 'A' && *(s + i) <= 'z' || *(s + i) >= 'А' && *(s + i) <= 'я' ) i++;
			i--;
		}
		else
		{
			size2++;
			pos2 = i;
			size = pos2 - pos1;
			slova = (char**)realloc(slova, size2 * sizeof(char*));
			*(slova + num) = (char*)calloc(size, sizeof(char));
			for (j = 0; j < size; j++)
			{
				slova[num][j] = *(s + pos1 + j);
			}
			slova[num][size] = '\0';
			puts(slova[num]);
			num++;
			if (*(s + i + 1) >= 'A' && *(s + i + 1) <= 'z' || *(s + i + 1) >= 'А' && *(s + i + 1) <= 'я');
			else i++;
		}
	}
	int* m;
	m = (int*)calloc(num, sizeof(int));
	for (i = 0; i < num; i++)
		m[i] = 1;
	for (int k = 0; k < num; k++)
	for (int i = k + 1; i < num; i++)
	{
		for (int j = 0;;)
		{
			if (slova[k][j] == slova[i][j] || slova[k][j] == slova[i][j] + 32 || slova[k][j] == slova[i][j] - 32)
			{
				j++;
				if (slova[i][j] == '\0' && slova[k][j] == '\0')
				{
					num--;
					for (x = i; x < num; x++)
					{
						slova[x] = slova[x + 1];
					}
					slova = (char**)realloc(slova, num * sizeof(char*));
					m = (int*)realloc(m, num * sizeof(int));
					m[k] += 1;
					break;
				}
			}
			else
			{
				break;
			}
			
		}
	}
	for(i = 0; i < num; i++)
	{ 
		for (j = 0; j < num - 1; j++)
		{
			if (m[j+1] >= m[j])
			{
				int a;
				char* b = (char *)calloc(30,sizeof(char));
				a = m[j];
				m[j] = m[j+1];
				m[j+1] = a;
				b = slova[j];
				slova[j] = slova[j+1];
				slova[j+1] = b;
			}
		}
	}
	int n; 
	printf("\n кол-во уникальных слов - %d\n", num);
	do
	{
		rewind(stdin);
		printf("введите кол-во слов -  ");
	} while (!scanf_s("%d", &n) || n <= 0 || n > num);
	for (i = 0; i < n; i++)
	{
		printf("\n");
		printf("%s\n", slova[i]);
		printf(" %d", *(m + i));
	}
	free(m);
	free(s);
	for (i = 0; i < num-1; i++)
	{
		slova[i] = NULL;
		free(*(slova+i));
	}
	free(slova);
}
/*for (int i = 0; i < num-1; i++)
	{
		for (int j = 0;;)
		{
			if (slova[i][j] == slova[i + 1][j])
			{
				j++;
				if (slova[i][j] == '\n')
				{
					sum++;
					num--;
					for (k = i; k < num; k++)
					{
						slova[k] = slova[k + 1];
					}
					slova = (char**)realloc(slova, num * sizeof(char*));
					m = (int*)realloc(m, num * sizeof(int));
					m[i] = sum;
					break;
				}
			}
			else
			{
				sum = 1;
				break;
			}
		}
	}*/
/*for (j = 0; j < num; j++)
	{
		for (i = j + 1; i < num; i++)
		{
			if (slova[j] == slova[i])
			{
				sum++;
				num--;
				for (k = i; k < num; k++)
				{
					*slova[k] = *slova[k + 1];
				}
				slova = (char**)realloc(slova, num * sizeof(char*));
				m = (int *)realloc(m, num * sizeof(int));
				m[j] = sum;
				i--;
			}
		}
		sum = 1;
	}*/