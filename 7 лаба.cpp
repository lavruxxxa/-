//12. Дана строка из нескольких слов.Слова отделяются друг от друга пробелами или запятыми.
//Вывести все слова, длина которых больше заданного числа.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	char* s=nullptr;
	int  a = 0, k, n, i, j;
	do  //выделение памяти
	{
		system("CLS");
		do
		{
			system("CLS");
			rewind(stdin);
			printf("введите размерность строки = ");
		} while (!scanf_s("%d", &n) || n <= 0);
		if (!(s = (char*)calloc(n, sizeof(char))))
		{
			printf("\nНедостаточно свободной памяти \n");
			s = nullptr;
		}
	} while (!s);
	printf("Вводите слова - "); // ввод слов
	rewind(stdin);
	gets_s(s, n);
	printf("ваш текст - ");
	puts(s);
	printf("введите кол-во симолов ");  // ввод кол-ва символов, больше которого надо искать слова
	scanf_s("%d", &k);
	for (i = 0; i < n; i++)
	{
		if (*(s + i) != ' ' && *(s + i) != ',')
		{
			a += 1;
		}
		else
		{

			if (a >= k)
			{
				for (j = 0; j < a; j++)
				{
					printf("%c", *(s + i - a + j));
				}
				printf("\n\n");
			}
			a = 0;
		}
	}
	free(s);
}
