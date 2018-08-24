#pragma once

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <string.h>
using namespace std;

class Mystring{
	char*m;
public:
	Mystring();
	Mystring(const Mystring & b);
	Mystring(const char*h);
	~Mystring();
	friend ostream& operator<<(ostream&, Mystring&);
	friend istream& operator>>(istream&, Mystring&);
	Mystring& operator=(const Mystring&b);
	Mystring& operator=(char* b);	
	Mystring& operator+=(Mystring& a);
	Mystring& operator+=(char* a);
	friend Mystring operator+(Mystring& a,Mystring& b);
	Mystring& operator*=(int a);
	bool operator>(Mystring& a);
	bool operator>=(Mystring& a);
	bool operator<(Mystring& a);
	bool operator<=(Mystring& a);
	bool operator==(Mystring& a);
	bool operator!=(Mystring& a);
	char operator[](int a);
	friend Mystring operator*(Mystring&, int );
	friend bool search(Mystring&, Mystring&);
	char** razdelit();
	int words();
};
bool search(Mystring&a, Mystring& b);
Mystring operator+(Mystring& a,Mystring& b);
Mystring operator*(Mystring& a,  int b);
ostream& operator<<(ostream& out, Mystring& a);
istream& operator>>(istream& in, Mystring& a);

