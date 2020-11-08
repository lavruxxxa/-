﻿#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");                         // русификация
	int** A= nullptr;
	int d, s, b = 0, i, j, n;
	
	do
	{
		system("CLS");
		printf("\nвведите размерность квадратной матрицы\n");
		rewind(stdin);
		i = scanf_s("%d", &n);
		d = n * n;
		s = n;
		if (i<1)
		{
			fflush(stdin);  // чистка буффера клавиатуры при ошибке ввода
			continue;       // повтор цикла
		}		 
		if (!(A = (int **)malloc(sizeof(int*)*n)))
		printf("\nНедостаточно свободной памяти \nУуменьшите число строк матрицы");
		for (i = 0; i<n; i++) // цикл выбора указателя на строку матрицы
		if (!(*(A + i) = (int *)malloc(sizeof(int)*s))) // выделение памяти под строку матрицы
		{                                               // с проверкой выделена ли память
			printf("\nНедостаточно свободной памяти \nУуменьшите число ст-цов матрицы");
			for (j = 0; j<i; j++) free(A[j]); free(A); // освобождение памяти при ошибке
			A = nullptr;         // сброс указателя для повтора операции выделения памяти
			break;         // выход из цикла по i (выбора указателя на строку матрицы)
		}
	} while (!A); 
	printf("\nВвод массива (матрицы)\n");
	for (i = 0; i < n; i++)                            // цикл по строкам матрицы
		for (j = 0; j < n; j++)                        // цикл по элементам столбца матрицы
		{
			printf("A[ %d ][ %d ] = ", i, j);
			rewind(stdin);                             // чистка входного буфера
			                                         
			if (!(scanf_s("%d", &A[i][j]))) j--;       // проверка введено ли число
		}
	printf("ваша матрица");
	for (i = 0; i < n; i++)                            // вывод матрицы
	{
		printf("\nстрока %d - ", i + 1);

		for (j = 0; j < n; j++)
		{
			printf(" %d ", A[i][j]);
		}
	}
	printf("\n\n");
	for (i = 0; i < n; i++)                            // проверка на симметричность
	{
		for (j = 0; j < n; j++)
		{
			if ( A[i][j] == A[j][i] )
			{
				b += 1;
			}
		}
	}
	if (b == d)
	{
		printf("ваша матрица симметрична относительно главной диагонали");
	}
	else 
	{
		printf("ваша матрица не симметрична относительно главной диагонали");
	}
	return 0;
}