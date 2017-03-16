// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>

int main()
{
	const int N = 3;
	double A[N][N] = { {1,2,3},{3,5,7},{1,3,4} };
	double b[N] = { 3,0,1 };
	double tmp = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << " | " << b[i];
		std::cout << "\n";
	}
	/*прямой ход*/
	for (int i = 0; i < N; i++)
	{
		tmp = A[i][i];
		b[i] /= tmp;

		for (int j = 0; j < N; j++)
		{
			A[i][j] /= tmp;
		}
		
		for (int k = i + 1; k < N; k++)
		{
			tmp = A[k][i];
			for (int z = 0; z < N; z++)
			{
				A[k][z] -= A[i][z] * tmp;
			}
			b[k] -= b[i] * tmp;
		}
	}

	std::cout << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << " | " << b[i];
		std::cout << "\n";
	}
	std::cout << "\n";
	/*обратный ход*/
	for (int j = N - 1; j > 0; j--)
	{
		for (int i = j - 1; i >= 0; i--)
		{
			b[i] -= b[j] * A[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		std::cout << "x" << i << " = " << b[i] << "\n";
	}
    return 0;
}

