// matrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "ctime"
#include <omp.h>

using namespace std;
int main()
{
	int n = 1000;
	int **a, **b, **c, **bt;
	a = new int*[1000];
	b = new int*[1000];
	c = new int*[1000];
	bt = new int*[1000];
	for (int i = 0; i < n; i++)
	{

		a[i] = new int[1000];
		b[i] = new int[1000];
		c[i] = new int[1000];
		bt[i] = new int[1000];

	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{

			a[i][j] = rand() % 10;
			b[i][j] = rand() % 10;
			c[i][j] = 0;

		}
	///транспонирование b
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			bt[i][j] = b[j][i];


//ОБЫЧНЫЙ АЛГОРИТМ УМНОЖЕНИЯ МАТРИЦ
	int stime = clock();
	for (int i = 0; i < n; ++i)

		for (int j = 0; j < n; ++j)
		{

			c[i][j] = 0;
			for (int k = 0; k < n; ++k)
				c[i][j] = a[i][k] * b[k][j];

		}
	printf("\nBasic algorithm: %f", (clock() - stime) / 1000.0);

	stime = clock();
//ОБЫЧНЫЙ АЛГОРИТМ УМНОЖЕНИЯ + Parallel num_threads(4)
#pragma omp parallel num_threads(4) 
#pragma omp for	
	for (int i = 0; i < n; ++i)
	
		for (int j = 0; j < n; ++j) 
		{

			c[i][j] = 0;
			for (int k = 0; k < n; ++k)
				c[i][j] = a[i][k] * b[k][j];

		}
	printf("\nBasic algorithm (Parallel): %f", (clock() - stime) / 1000.0);

// С ТРАНСПОНИРОВАННОЙ МАТРИЦЕЙ Б
	stime = clock();
	for (int i = 0; i < n; ++i)

		for (int j = 0; j < n; ++j)
		{

			c[i][j] = 0;

			for (int k = 0; k < n; ++k)
				c[i][j] = a[i][k] * b[j][k];

		}

	printf("\n2 Transponse B matrix: %f", (clock() - stime) / 1000.0);

//С ТРАНСПОНИРОВАННОЙ МАТРИЦЕЙ + Parallel num_threads(4)
	stime = clock();
#pragma omp parallel num_threads(4) 
#pragma omp for
	for (int i = 0; i < n; ++i)

		for (int j = 0; j < n; ++j)
		{

			c[i][j] = 0;

			for (int k = 0; k < n; ++k)
				c[i][j] = a[i][k] * b[j][k];

		}

	printf("\n2 Transponse B matrix + parallel: %f", (clock() - stime) / 1000.0);
	getchar();
    return 0;
}

