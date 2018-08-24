// CHM4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
#include "clocale"
#include "iomanip"
using namespace std; 

double e = 0.00001, a = 0, b = 1, c = 2;
double round(double n, double s, double c = 1)
{
	int ttt = 1;
	if (n<0)
	{
		ttt = -1;
	}
	n = abs(n);
	double cel = floor(n);
	double r = n*pow(10, s + c);
	double mas[100];
	for (double i = s + c; i>0; i--)
	{
		mas[int(i)] = int(r) % 10;
		r /= 10;
	}

	for (double i = s + c; i>s; i--)
	{
		if (mas[int(i)] >= 5)
		{
			int t = 1;
			mas[int(i - t)] += 1;
			while (mas[int(i - t)]>9)
			{
				mas[int(i - t)] = 0;
				mas[int(i - t - 1)] += 1;
				t++;
			}
		}
	}

	for (int t = 1; t <= s; t++)
	{
		cel += mas[t] / pow(10., t);
	}
	return cel*ttt;
}
double F(double x)
{
	return (4 * (1 - x*x) - exp(x));
}

double DF(double x)
{
	return (-8 * x - exp(x));
}

void newton()
{
	double x0, x1;
	int i = 0;
//	if (F(a)*DF(a) < 0)
	//	x0 = a;
//	else if (F(b)*DF(b) < 0)
		x0 = b;
	x1 = x0;
	double dff = DF(x0);
	cout << "DF(x0): " << dff << endl;
	do{
		x0 = x1;
		x1 = x0 - (F(x0) / dff);
		cout << i << " итерация:  ";
		cout << setprecision(10) <<"x: " << round(x1,10) << "\t F(x0): " << round(F(x0),10) << endl;
		i++;
	} while (fabs(x1 - x0) > e);

}
void sekushih()
{
	double x0, x1, dff;
	x0 = b;
	int i = 0;
	dff = (F(b) - F(b - 0.0001)) / 0.0001;
	do {
		x0 = x1;
		x1 = x1 - F(x1)*(x1-x0)/(F(x1)-F(x0));
		cout << i << " итерация:  ";
		cout << setprecision(10) << "x: " << round(x1, 10) << "\t F(x0): " << round(F(x0), 10) << endl;
		i++;
	} while (fabs(x1 - x0) > e);


}
int main()
{
	
	setlocale(LC_ALL, "Russian");
	newton();

	getchar();
	getchar();
}

