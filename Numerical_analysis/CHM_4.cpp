// homework_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
#include "locale"
using namespace std;
int str = 0;//Количество строк

double** addstr(double** a, int n, int s)
{
	int n1 = n;
	double **mas = new double*[s + 1];
	mas[0] = new double[n];
	for (int i = 1; i <= s + 1; i++)
	{
		mas[i] = new double[n - i + 1];
	}
	for (int i = 0; i <= s; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			mas[i][j] = a[i][j];

		}
		if (i > 1)
			n1--;
	}
	return mas;
}

double fact(int z)
{
	if (z == 0)
		return 1;
	else
		return z*fact(z - 1);
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	double** num; //массив
	int n = 0; //кол-во элементов
	cout << "Введите кол-во элементов: ";
	cin >> n;
	num = new double*[2];
	num[str++] = new double[n];
	num[str] = new double[n];
	str = 1;
	cout << "Введите первое значение: ";
	cin >> num[0][0];
	num[1][0] = pow(num[0][0], 2.) - log(num[0][0]);
	for (int i = 1; i < n; i++)
	{
		num[0][i] = num[0][i - 1] + 0.1;
		num[1][i] = pow(num[0][i], 2.) - log(num[0][i]);
	}

	do {
		num = addstr(num, n, str);
		str++;//добавление столбца 
		for (int i = 1; i <= n - str + 1; i++)//добавление элементов в новый столбец 
		{
			num[str][i - 1] = num[str - 1][i] - num[str - 1][i - 1];
		}
	} while (abs(num[str][0]) - abs(num[str][n - str + 1]) > 0);

	cout << str - 1 << endl;
	cout << " X\t\t    Y\n";
	int str1 = str;
	for (int i = 0; i <= n; i++) // выводим столбцы -> строки
	{
		for (int j = 0; j <= str1; j++)
		{
			if (i<n - 1)
				cout << num[j][i] << "\t\t";
		}
		if (i>n - str - 1)
			str1--;
		if (i == n - 1)
			cout << num[0][n - 1] << "\t\t" << num[1][n - 1];
		cout << endl;
	}
	cout << "==============================[ Diff ]===============================" << endl;

	//дифференцируем по Ньютону

	double df = 0;
	double h = 0.1;

	for (int i = 1; i<str - 2; i++)
	{
		df += (pow(-1, double(i - 1))*num[i + 1][0]) / double(i);
	}
	df /= h;
	cout << "Производная через полином Ньютона \t" << df << endl;
	double dfr = (2 * num[0][0] - (1 / num[0][0]));
	cout << "Производная от x^2-ln(x) \t\t" << dfr << endl;
	cout << "Разница между производным \t\t" << df - dfr << endl;
	getchar();
	getchar();

	return 0;
}
