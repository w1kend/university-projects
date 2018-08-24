#include "stdafx.h"
#include "DateTime.h"
#include <locale>
#include <iostream>
#include <math.h>
using namespace std;


	DateTime::DateTime()
	{
		Day = 10;
		Year = 2016;
	}
	DateTime::DateTime(int d, int y)
	{
		Day = d;
		Year = y;
	}
	DateTime::DateTime(const DateTime& a)
	{
		Day = a.Day;
		Year = a.Year;
	}
	DateTime::~DateTime()
	{}
	int DateTime::validate()//корректность данных
	{
		if (LeapYear(Year))
		{
			if (Day < 1 || Day>366 || Year<0)
				return false;
			return true;

		}
		else {
			if (Day < 1 || Day>365 || Year <0)
				return false;
			return true;
		}

	}
	int  DateTime::get_Day()
	{
		int a[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
		int b[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 }
		;
		if (LeapYear(Year))
		{
			if (validate())
			{
				for (int i = 1; i < 13; i++)
				{
					if (Day <= a[i])
						return Day - a[i - 1];
				}
			}
		}
		else {
			if (validate())
			{
				for (int i = 1; i < 13; i++)
				{
					if (Day <= b[i])
						return Day - b[i - 1];
				}
			}



		}
	}
	int  DateTime::get_Month()
	{
		int a[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
		int b[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
		if (LeapYear(Year))
		{


			if (validate())
			{
				for (int i = 1; i < 13; i++)
				{
					if (Day <= a[i])
						return i;
				}
			}
		}
		else {
			if (validate())
			{
				for (int i = 1; i < 13; i++)
				{
					if (Day <= b[i])
						return i;
				}
			}

		}
	}//Месяц

	int  DateTime::get_Year()
	{
		return Year;
	}//Год

	int  DateTime::get_DayofWeek()
	{
		if (Year >= 1583)
		{
			int a = (14 - get_Month()) / 12;
			int b = Year - a;
			int c = get_Month() + 12 * a - 2;
			return (7000 + (get_Day() + b + b / 4 - b / 100 + b / 400 + (31 * c) / 12)) % 7;
		}
		else
			return 0;
	}//День недели
	bool  DateTime::LeapYear(int q)
	{
		if (q >= 4 && (q % 4 == 0))
			if (q >= 100 && q % 100 == 0)
			{
				if (q >= 400 && q % 400 == 0)
					return true;
				else return false;
			}
			else return true;
		else return false;
	}

	void DateTime::AddDay(int q)
	{
		Day += q;
		if (Day > 365)
		{
			if (LeapYear(Year) && Day > 366)
			{
				Year++; Day = 366 - Day;
			}
			else if (!LeapYear(Year) && Day > 365)
			{
				Year++; Day = 365 - Day;
			}
		}
		else if (Day <= 0)
			if (LeapYear(Year))
			{
				Year--; Day = 365 + Day;

			}
			else if (!LeapYear(Year))
			{
				Year--;
				if (LeapYear(Year))
				{
					Day = 366 + Day;
				}
				else Day = 365 + Day;
			}

	}

	void  DateTime::AddMonths(int q)
	{
		if (validate())
		{
			int y1[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			int y2[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			int a = get_Month();
			int m = 0;
			int d1 = 0, d2 = get_Day();
			
			a = get_Month();
			while (q != 0)
			{
				if (LeapYear(Year))
				{
					d1 = get_Day();
					while (get_Day() != y1[a])
						Day++;
					a++;
					while (d1 > y1[a])
						d1--;
					Day += d1;
				}
				else
				{
					d1 = get_Day();
					while (get_Day() != y2[a])
						Day++;
					a++;
					while (d1 > y2[a])
						d1--;
					Day += d1;

				}

				q--;
			}
		}
		else cout << "error" << endl;
	}


	void DateTime::AddYears(int q)
	{
		if (validate())
		{
			if (q > 0)
			{
				if (LeapYear(Year) > LeapYear(Year + q))
				{
					Year += q; Day -= 1;
				}
				else if (LeapYear(Year + q) > LeapYear(Year))
				{
					Year += q; Day += 1;
				}
				else Year += q;
			}
			else  if (q < 0)
			{
				if (LeapYear(Year) > LeapYear(Year + q))
				{
					Year += q; Day -= 1;
				}
				else if (LeapYear(Year + q) > LeapYear(Year))
				{
					Year += q; Day += 1;
				}
				else Year += q;

			}
		}
		else cout << "error" << endl;
	}


	DateTime DateTime::get_Now()
	{
		if (validate())
		{
			Day = 1; Year = 2010;
		}
		return *this;
	}
	DateTime&  DateTime::Parser(char*b)
	{
		int d = 0, y = 0, m = 0;
		int i = 0, i1 = 0;
		char a[12];

		while (*(b + i) == ' ' || *(b + i) == '\n' || *(b + i) == '\t')
			i++;
		while (*(b + i) != ' ' && *(b + i) != '\n' && *(b + i) != '\t')
		{
			d = d * 10 + (*(b + i) - 48); i++;
		}
		while (*(b + i) == ' ' || *(b + i) == '\n' || *(b + i) == '\t')
		{
			i++;
		}
		while (*(b + i) != ' ' && *(b + i) != '\n' && *(b + i) != '\t')
		{
			*(a + i1) = *(b + i);
			i++; i1++;
		}
		*(a + i1) = '\0';
		while (*(b + i) == ' ' || *(b + i) == '\n' || *(b + i) == '\t')
		{
			i++;
		}

		char* m1[13] = { { "1" }, { "Января" }, { "Февраля" }, { "Марта" }, { "Апреля" }, { "Мая" }, { "Июня" }, { "Июля" }, { "Августа" }, { "Сентября" }, { "Октября" }, { "Ноября" }, { "Декабря" } };
		for (m = 1; strcmp(a, *(m1 + m)) != 0; m++)
			;
		m--;
		while (*(b + i) != ' ' && *(b + i) != '\n' && *(b + i) != '\t' && *(b + i) != '\0')
		{
			y = y * 10 + (*(b + i) - 48); i++;
		}
		int y1[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int y2[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int d1 = 0;

		if (LeapYear(y))
		{
			for (int i = 1; i <= m; i++)
				d1 += *(y1 + i);
		}
		else
		{
			for (int i = 1; i <= m; i++)
				d1 += *(y2 + i);
		}
		d1 += d;
		Day = d1;
		Year = y;
		if (!validate())
		{
			Day = 1; Year = 2010;
		}
		return *this;

	}
	char*  DateTime::ToString()
	{
		int d = get_Day(); int a = 0;
		while (d != 0)
		{
			d = d / 10; a++;
		}
		d = get_Day();
		int c = get_Month();
		int dow[] = { 6, 7, 5, 6, 3, 4, 4, 7, 8, 7, 6, 7 };
		char*b = new char[a + dow[c - 1] + 6];
		int i = a;
		while (d != 0)
		{
			*(b + a - 1) = d % 10 + '0'; d = d / 10; a--;
		}
		*(b + i) = ' '; i++;
		char* m[12] = { { "Января" }, { "Февраля" }, { "Марта" }, { "Апреля" }, { "Мая" }, { "Июня" }, { "Июля" }, { "Августа" }, { "Сентября" }, { "Октября" }, { "Ноября" }, { "Декабря" } };
		int g = 0;
		while (*(*(m + c - 1) + g) != '\0')
		{
			*(b + i) = *(*(m + c - 1) + g); i++; g++;
		}
		*(b + i) = ' ';
		int y = Year, s = 0;
		while (y != 0)
		{
			y = y / 10; s++;
		}
		y = Year;
		*(b + i + s + 1) = '\0';
		while (y != 0)
		{
			*(b + i + s) = y % 10 + '0'; y = y / 10; s--;
		}
		return b;

	}
	unsigned long DateTime::ToUInt64()
	{
		unsigned long w = 0;
		for (int i = 1; i < Year; i++)
			if (LeapYear(i))
				w += 366;
			else w += 366;

			w += Day;
			return w;
	}

	DateTime DateTime::operator+(const DateTime& a)
	{
		int d, y;
		d = Day + a.Day;
		if (LeapYear(Year))
		{
			if (d > 366)
			{
				y = Year + a.Year + d / 366;
				d = d % 366;
			}
			else y = Year + a.Year;
			DateTime w(d, y);
			return w;
		}
		if (!LeapYear(Year))
		{
			if (d > 365)
			{
				y = Year + a.Year + d / 365;
				d = d % 365;
			}
			else y = Year + a.Year;
			DateTime w(d, y);
			return w;
		}

	}
	DateTime DateTime::operator-(const DateTime &a)
	{
		int d, y;
		d = Day - a.Day;
		if (LeapYear(Year))
		{
			if (d < 0)
			{
				y = Year - a.Year - 1;
				d = 366 + d;
			}
			else y = Year - a.Year;
			DateTime w(d, y);
			return w;
		}
		if (!LeapYear(Year))
		{
			if (d < 0)
			{
				y = Year - a.Year - 1;
				d = 365 - d;
			}
			else y = Year - a.Year;
			DateTime w(d, y);
			return w;
		}
	}
	DateTime DateTime::operator+=(DateTime& a)
	{
		if (this != &a)

		{
			AddDay(a.Day);
			AddYears(a.Year);
		}
		return *this;
	}
	DateTime DateTime::operator-=(DateTime& a)
	{
		if (this != &a)
		{
			AddDay(-a.Day);
			AddYears(-a.Year);

		}

		return *this;
	}
	DateTime& DateTime::operator=(const DateTime& a)
	{
		if (this != &a)
		{
			Day = a.Day;
			Year = a.Year;
		}
		return *this;
	}
	bool DateTime::operator==(DateTime& a)
	{
		if (Day == a.Day && Year == a.Year)
			return true;
		return false;

	}
	bool DateTime::operator!=(DateTime& a)
	{
		if (Day == a.Day && Year == a.Year)
			return false;
		return true;
	}
	bool DateTime::operator<(DateTime& a)
	{
		if (Day < a.Day || Year< a.Year)
			return true;
		return false;

	}
	bool DateTime::operator>(DateTime& a)
	{
		if (Day > a.Day || Year> a.Year)
			return true;
		return false;

	}
	int DateTime::DateTimeCmp(const DateTime& a)
	{
		if (Day == a.Day && Year == a.Year)
			return true;
		return false;
	}





ostream& operator<<(ostream& out, DateTime& a)
{
	out << a.Day << ":" << a.Year << endl;
	out << a.get_Day() << "." << a.get_Month() << "." << a.Year << endl;
	return out;
}
istream& operator>>(istream& in, DateTime& a)
{
	cout << "Введите день,год" << endl;
	in >> a.Day >> a.Year;
	return in;
}
