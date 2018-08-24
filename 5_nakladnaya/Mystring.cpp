#pragma once

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <Windows.h>
#include "Mystring.h"
using namespace std;




	Mystring::Mystring()
	{
		m = new char[2];
		m[0] = ' \0';

	}
	Mystring::Mystring(const Mystring & b)
	{
		int i = 0;
		m = new char[strlen(b.m) + 1];
		for (; *(b.m + i) != '\0'; i++)
			*(m + i) = *(b.m + i);
		*(m + i) = '\0';
	}
	Mystring::Mystring(const char*h)
	{
		int i = 0;
		m = new char[strlen(h) + 1];
		for (; *(h + i) != '\0'; i++)
			*(m + i) = *(h + i);
		*(m + i) = '\0'; 
	}

	Mystring::~Mystring()
	{
		delete[] m;
	}
	Mystring& Mystring::operator=(const Mystring&b)
	{
		if (this != &b)
		{
			int i = 0;
			delete[]m;
			m = new char[strlen(b.m) + 1];
			for (; *(b.m + i) != '\0'; i++)
				*(m + i) = *(b.m + i);
			*(m + i) = '\0';
			
		}
		return *this;
	}
	Mystring& Mystring::operator=(char* b)
	{

		int i = 0;
		delete[]m;
		m = new char[strlen(b) + 1];
		for (; *(b + i) != '\0'; i++)
			*(m + i) = *(b + i);
		*(m + i) = '\0';
		return *this;
	}	
	Mystring& Mystring::operator+=(Mystring& a)
	{
		char* buf;
		buf = new char[strlen(m) + strlen(a.m) + 1];
		int i = 0;
		for (; i<strlen(m); i++)
			*(buf + i) = *(m + i);
		for (int g = 0; g<strlen(a.m); i++, g++)
			*(buf + i) = *(a.m + g);
		*(buf + i) = '\0';
		m = buf;
		return *this;
	}
	Mystring& Mystring::operator+=(char* a)
	{
		char* buf;
		buf = new char[strlen(m) + strlen(a) + 1];
		int i = 0;
		for (; i<strlen(m); i++)
			*(buf + i) = *(m + i);
		for (int g = 0; g<strlen(a); i++, g++)
			*(buf + i) = *(a + g);
		*(buf + i) = '\0';
		m = buf;
		return *this;
	}
	Mystring& Mystring::operator*=(int a)
	{
		char* x;
		x = new char[1];
		strcpy_s(x, strlen(m) + 1, m);
		for (int i = 1; i<a; i++)
			strcat_s(m, strlen(m) + strlen(x) + 1, x);
		return *this;
	}
	bool Mystring::operator>(Mystring& a)
	{
		if (strcmp(m, a.m)>0)
			return true;
		return false;
	}
	bool Mystring::operator>=(Mystring& a)
	{
		if (strcmp(m, a.m) >= 0)
			return true;
		return false;
	}
	bool Mystring::operator<(Mystring& a)
	{
		if (strcmp(m, a.m)<0)
			return true;
		return false;
	}
	bool Mystring::operator<=(Mystring& a)
	{
		if (strcmp(m, a.m) <= 0)
			return true;
		return false;
	}
	bool Mystring::operator==(Mystring& a)
	{
		if (strcmp(m, a.m) == 0)
			return true;
		return false;
	}
	bool Mystring::operator!=(Mystring& a)
	{
		if (strcmp(m, a.m) != 0)
			return true;
		return false;
	}
	char Mystring::operator[](int a)
	{
		return *(m + a);
	}
	char** Mystring::razdelit()
	{

		char**c;
		int s = 0, i = 0, k = 0;
		while (*(m + i) != '\0')
		{
			while (*(m + i) == ' ' || *(m + i) == '\t'|| *(m + i) == '\n')
				i++;
		
			if (*(m + i) !='\0')
			{
				while (*(m + i) != ' '&& *(m + i) != '\t' &&  *(m + i) != '\n' &&*(m + i) != '\0')
					i++;
				s++;
			}
		}
		c = new char* [s ];
		i = 0;

		while (*(m + i) != '\0')
		{
			char b[100];
			int g = 0;
			while (*(m + i) == ' ' || *(m + i) == '\t' || *(m + i) == '\n')
				i++;
			if (*(m + i) != '\0')
			{
				while (*(m + i) != ' '&& *(m + i) != '\t' &&  *(m + i) != '\n' &&*(m + i) != '\0')
				{
					*(b + g) = *(m + i); i++; g++;
				}
				*(b + g) = '\0';
			}
			*(c + k) = new char[g+1];
			g = 0;
			for (; *(b + g) != '\0'; g++)
			{
				*(*(c + k) + g) = *(b + g);
			}
			*(*(c + k) + g) = '\0';
			k++;
			i++;
		}
		return c;
	}
	int Mystring::words()
	{
		int i = 0, s = 0;
		while (*(m + i) != '\0')
		{
			while (*(m + i) == ' ' || *(m + i) == '\t' || *(m + i) == '\n')
				i++;
			for (i; *(m + i) != ' '&& *(m + i) != '\t' && *(m + i) != '\n' &&*(m + i) != '\0'; i++)
			{
			}
			if (*(m + i) != '\0')
			{
				while (*(m + i) == ' ' || *(m + i) == '\t' || *(m + i) == '\n')
					i++;
				s++;
			}
		}
		return s + 1;
	}
bool search(Mystring&a, Mystring& b)
{
	int i = 0, g = 0, e = 0, v = 0;
	for (i = 0; i < strlen(a.m) - strlen(b.m); i++)
		if (*(a.m + i) == *(b.m + 0))
		{
			e = 1;
			for (g = i; (*(a.m + g) == *(b.m + v)) && (*(b.m + v) != '\0'); g++, v++)
			{
			}
			if (strlen(b.m) < v)
				e = 0;
		}
	if (e)
		return true;
	return false;
}
Mystring operator+(Mystring& a, Mystring& b)
{
	Mystring tmp = a;
	tmp += b;
	return tmp;
}
Mystring operator*(Mystring& a, int b)
{
	Mystring tmp=a;
	for ( int i = 1; i < b;i++)
	tmp += a;
	return tmp;
}

ostream& operator<<(ostream& out, Mystring& a)
{
	out << a.m;
	return out;
}

istream& operator>>(istream& in, Mystring& a)
{
	char buf[256];

	in.getline(buf, 256);
	delete[]a.m;
	a.m = new char[strlen(buf) + 1];
	int i = 0;
	for (; i<strlen(buf); i++)
		*(a.m + i) = *(buf + i);
	*(a.m + i) = '\0';
	return in;
}


