#pragma once

#include "stdafx.h"
#include <locale>
#include "Windows.h"
#include "iostream"
#include <math.h>
#include <cstring>
using namespace std;

class DateTime
{
	int Day;
	int Year;
public:
	DateTime();
	DateTime(int d, int y);
	DateTime(const DateTime& a);
	~DateTime();
	int validate();
	int  get_Day();
	int  get_Month();
	int  get_Year();
	int  get_DayofWeek();
	bool  LeapYear(int q);
	void AddDay(int q);
	void  AddMonths(int q);
	void AddYears(int q);
	DateTime get_Now();
	DateTime&  Parser(char*b);
	char*  ToString();
	unsigned long ToUInt64();
	DateTime operator+(const DateTime& a);
	DateTime operator-(const DateTime &a);
	DateTime operator+=(DateTime& a);
	DateTime operator-=(DateTime& a);
	DateTime& operator=(const DateTime& a);
	bool operator==(DateTime& a);
	bool operator!=(DateTime& a);
	bool operator<(DateTime& a);
	bool operator>(DateTime& a);
	int DateTimeCmp(const DateTime& a);
	friend ostream& operator<<(ostream& out, DateTime& a);
	friend istream& operator>>(istream& in, DateTime& a);
};



ostream& operator<<(ostream& out, DateTime& a);
istream& operator>>(istream& in, DateTime& a);
