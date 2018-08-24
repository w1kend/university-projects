#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string.h>
using namespace std;

struct player
{
	char *fullname;// ��� ����� ������
	char *status;//������ ������ (��������, ���������� � �.�.)
	int year;// ��� ��������
	int comm;//���������� ������, � ������� �����
	char **teamlist;// ������ ������
	int *teamplays[100];// ��� �� �������
	int *teamgoals[100];//����� �� ������� 

};

player *ps[100];
int n = 0;
void strcpy(char* a, char* b)
{
	while (*a++ = *b++);
}
void fout()
{
	ofstream fout("B.txt");
	for (int a = 0; a < n;a++)
	{
		fout << "���: ";
		fout << (*(ps + a))->fullname;
		fout << "\n������ ������: ";
		fout << (*(ps + a))->status;
		fout << "\n��� ��������: ";
		fout << (*(ps + a))->year;
		fout << "\n���������� ������, � ������� �����: ";
		fout << ((*(ps + a))->comm);
		fout << "\n������ ������: ";
		for (int i = 0; i < (*(ps + a))->comm; i++)
		{
			fout << (*((*(ps + a))->teamlist + i));
			fout << "\t";
		}
		fout << "\n���������� ��� :";
		for (int i = 0; i < (*(ps + a))->comm; i++)
		{
			fout << *(*((*(ps + a))->teamplays + i)) << "\t";
		}
		fout << "\n���������� ������� �����: ";
		for (int i = 0; i < (*(ps + a))->comm; i++)
		{
			fout << *(*((*(ps + a))->teamgoals + i)) << "\t";
		}
		fout << endl;
	}
}


void print(int a)
{
	if (a >= 0 && a < n)
	{
		cout << "���: ";
		cout << (*(ps + a))->fullname;
		cout << "\n������ ������: ";
		cout << (*(ps + a))->status;
		cout << "\n��� ��������: ";
		cout << (*(ps + a))->year;
		cout << "\n���������� ������, � ������� �����: ";
		cout << ((*(ps + a))->comm);
		cout << "\n������ ������: ";
		for (int i = 0; i < (*(ps + a))->comm; i++)
		{
			cout << (*((*(ps + a))->teamlist + i));
			cout << "\t";
		}
		cout << "\n���������� ��� :";
		for (int i = 0; i < (*(ps + a))->comm; i++)
		{
			cout << *(*((*(ps + a))->teamplays + i)) << "\t";
		}
		cout << "\n���������� ������� �����: ";
		for (int i = 0; i < (*(ps + a))->comm; i++)
		{
			cout << *(*((*(ps + a))->teamgoals + i)) << "\t";
		}
		cout << endl;
	}
	else
	{
		cout << "������" << endl;
	}

}
/////////////////////////////////////////////////////////////////���������� ������////////////////////////////////////////////////////////
void add_player()
{
	(*(ps + n)) = new player;
	//char fname[100];
	char stat[100];
	int year1, comm1;
	int plays, goals;
	setlocale(LC_ALL, "Russian");
	cout << "������� ��� ������ (����� ������):";
	cout << endl;
	//cin.getline(fname, 100);
	//(*(ps + n))->fullname = new char[strlen(fname) + 1];
	//strcpy((*(ps + n))->fullname, fname);
	char f[20];
	char i[20];
	char o[20];
   char pr[2];
   pr[0] = ' '; pr[1] = '\0';
	cin >> f >> i >> o;
	int ii = 0;
	if (f[ii] != '\0')
		ii++;
	else { f[ii] = ' '; f[ii + 1] = '\0'; }
	(*(ps + n))->fullname = new char[strlen(f) + strlen(i) + strlen(o) + 1];
	strcpy((*(ps + n))->fullname,f);
	strcat_s((*(ps + n))->fullname, strlen(f) + strlen(pr)+1, pr); 
	strcat_s((*(ps + n))->fullname, strlen(f) + strlen(i) + strlen(pr) + 1, i);
	strcat_s((*(ps + n))->fullname, strlen(f) + strlen(i) + strlen(pr) + strlen(pr) + 1, pr);
	strcat_s((*(ps + n))->fullname, strlen(f) + strlen(i) + strlen(pr) + strlen(pr) + 1+ strlen(o), o);
	cout << "������� ������ ������: ";
	cin >> stat;
	(*(ps + n))->status = new char[strlen(stat) + 1];
	strcpy((*(ps + n))->status, stat);

	cout << "������� ��� �������� ������: ";
	cin >> year1;
	(*(ps + n))->year = year1;

	cout << "������� ���������� ������, � ������� �� �����: ";
	cin >> comm1;
	(*(ps + n))->comm = comm1;
	(*(ps + n))->teamlist = new char*[comm1];
	*((*(ps + n))->teamplays) = new int;
	*((*(ps + n))->teamgoals) = new int;
	for (int i = 0; i < comm1; i++)//��������� �������\����\���� 
	{

		char tlist[100];

		*((*(ps + n))->teamplays + i) = new int;
		*((*(ps + n))->teamgoals + i) = new int;
		cout << "������� �������� " << i + 1 << "-� �������: ";
		cin >> tlist;
		cout << "������� ���������� ���, ��������� �� ��� �������: ";
		cin >> plays;
		if (plays > 0) //���� ���� �������� ����
		{
			cout << "������� ���������� ������� ����� �� ��� �������: ";
			cin >> goals;
			*(*((*(ps + n))->teamgoals + i)) = goals;
		}
		else *(*((*(ps + n))->teamgoals + i)) = 0;//���� ���
		(*((*(ps + n))->teamlist + i)) = new char[strlen(tlist) + 1];
		strcpy((*((*(ps + n))->teamlist + i)), tlist);

		*(*((*(ps + n))->teamplays + i)) = plays;

	}n++;
}

//////////////////////////////////////////////////////////� ����� ����������////////////////////////////////////////////////////////////////////////////
void add_from_file()
{
	ifstream fin("A.txt");
	char *a=new char;
	int b = 0; int y; int c;
	char a2[100]; char qq[100];
	while (!fin.eof())
	{		//////���////
			(*(ps + n)) = new player;
			char f[20];
			char i[20];
			char o[20];
			char pr[2];
			pr[0] = ' '; pr[1] = '\0';
			fin >> f >> i >> o;
			int ii = 0;
			if (f[ii] != '\0')
				ii++;
			else { f[ii] = ' '; f[ii + 1] = '\0'; }
			(*(ps + n))->fullname = new char[strlen(f) + strlen(i) + strlen(o) + 1];
			strcpy((*(ps + n))->fullname, f);
			strcat_s((*(ps + n))->fullname, strlen(f) + strlen(pr) + 1, pr);
			strcat_s((*(ps + n))->fullname, strlen(f) + strlen(i) + strlen(pr) + 1, i);
			strcat_s((*(ps + n))->fullname, strlen(f) + strlen(i) + strlen(pr) + strlen(pr) + 1, pr);
			strcat_s((*(ps + n))->fullname, strlen(f) + strlen(i) + strlen(pr) + strlen(pr) + 1 + strlen(o), o);


			///////������////////

			fin >> a2;
			(*(ps + n))->status = new char[strlen(a2) + 1];
			strcpy((*(ps + n))->status, a2);
			//////���///////

			fin >> y;
			(*(ps + n))->year = y;


			////////����� ������/////////

			fin >> c;
			(*(ps + n))->comm = c;

			//////////�������� ������/////////

			(*(ps + n))->teamlist = new char*[(*(ps + n))->comm + 1];
			*((*(ps + n))->teamplays) = new int;
			*((*(ps + n))->teamgoals) = new int;

			for (int g = 0; g < (*(ps + n))->comm; g++)
			{

				fin >> qq;
				(*((*(ps + n))->teamlist + g)) = new char[strlen(qq) + 1];
				strcpy((*((*(ps + n))->teamlist + g)), qq);
			}
			////////���� �� �������//////////////////

			for (int g = 0; g < (*(ps + n))->comm; g++)
			{

				int a1;
				fin >> a1;
				*((*(ps + n))->teamplays + g) = new int;
				*(*((*(ps + n))->teamplays + g)) = a1;

			}

			/////////���� �� ����////////////
			for (int g = 0; g < (*(ps + n))->comm; g++)
			{

				int a3;
				fin >> a3;
				*((*(ps + n))->teamgoals + g) = new int;
				*(*((*(ps + n))->teamgoals + g)) = a3;
			}


			n++;
		} 
	fin.close();
}

//////////////////////////////////////////////////////////////�������� ������////////////////////////////////////////////////////
void del_player(int a)
{	
	if (a >= 0 && a < n)
	{
		delete[](*(ps + a))->fullname; //���
		delete[](*(ps + a))->status; //������
		for (int i = 0; i < (*(ps + a))->comm; i++)
		{
			delete[] * ((*(ps + a))->teamlist + i);
		}
		delete[](*(ps + a))->teamlist; //������ ������
		for (int i = 0; i < (*(ps + a))->comm; i++)
		{
			delete[] * ((*(ps + a))->teamplays + i);
		}
		//��� �� �������
		for (int i = 0; i < (*(ps + a))->comm; i++)
		{
			delete[](*((*(ps + a))->teamgoals + i));
		}
		//delete[](*(ps + a))->teamgoals; //���� �� �������
		delete[](*(ps + a));
		for (int i = a; i < n; i++)
		{
			*(ps + i) = *(ps + i + 1);
		}
		n--;
		cout << endl;
		cout << "�������� ������ �������" << endl;
	}
	else cout << "������" << endl;
	
}
////////////////////////////////////////���������� �� ���� �������� ��� �� �������//////////////////////////////////////////////////////////////////////////
void sort() //sortirovka
{
	int a;
	cout << endl;
	cout << "�������� ��� ����������: " << endl << "1 - �� ���� ��������." << endl << "2 - �� �������." << endl;
	cin >> a;

	if (a == 1)
	{

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if ((*(ps + i))->year >(*(ps + j))->year)
				{
					player *tmp;
					tmp = *(ps + i);
					*(ps + i) = *(ps + j);
					*(ps + j) = tmp;
				}
	}
	else if (a == 2)
	{
		for (int i = 0; i < n - 1; i++)
		{
			char *q1;
			char f1[100];
			q1 = (*(ps + i))->fullname;
			while (q1 != '\0')
			{
				while (*q1 == ' ' || *q1 == '\n' || *q1 == '\t')// do bykv idem
					q1++;


				//int g = 0;
				for (int g = 0; *q1 != ' '; g++)// �������� ������� � ������
				{
					f1[g] = *q1;
					q1++;

				}
				//f1[g] = '\0';
				break;
			}
			for (int j = i; j < n; j++)
			{

				char *q2;
				char f2[100];
				q2 = (*(ps + j))->fullname;
				while (q2 != '\0')
				{
					while (*q2 == ' ' || *q2 == '\n' || *q2 == '\t')// do bykv idem
						q2++;
					//int g = 0;
					for (int g = 0; *q2 != ' '; g++)// ������� � ������
					{
						f2[g] = *q2;
						q2++;

					}
					//f2[g] = '\0';
					break;
				}
				if (strcmp(f1, f2) > 0)
				{
					player *tmp;
					tmp = *(ps + i);
					*(ps + i) = *(ps + j);
					*(ps + j) = tmp;
				}

			}


		}

	}

	for (int i = 0; i < n; i++)
		print(i);
}

/////////////////////////////////////////////////////////���� � ������� ������ ����� �������//////////////////////////////////////////////////////////
void max_players_inteam()
{
	int team = 0;
	int max = 0, m = 0;
	for (int i = 0; i < n - 1; i++)//���������
		for (int k = 0; k < (*(ps + i))->comm; k++)// ���������� ��� ������� �������������� ������
		{
			m = 0;
			for (int j = i+1; j < n ; j++)//���������� ��������� ������� � �������������
				for (int k1 = 0; k1 < (*(ps + j))->comm; k1++)//������� ��������� ������� � ����. �������� ����. ������ ��
					if ( strcmp( *((*(ps + i))->teamlist + k), *((*(ps + j))->teamlist + k1) ) == 0 )
						m++;

			if (m > max)
				max = m;

		}
	cout << endl;
	cout << "������ ����� ������� � �������� :" << endl;;
	for (int i = 0; i < n -1; i++)
		for (int k = 0; k < (*(ps + i))->comm; k++)
		{
			m = 0;
			for (int j = i+1; j < n ; j++)
				for (int k1 = 0; k1 < (*(ps + j))->comm; k1++)
					if ( strcmp(*((*(ps + i))->teamlist + k), *((*(ps + j))->teamlist + k1)) == 0)
						m++;

			if (m == max)
			{

				cout << team + 1 << ") " << *((*(ps + i))->teamlist + k) << endl;
				team++;
			}
		}



}
//////////////////////////////////////////////////////������� ������ �� ������� ����� �� �����������////////////////////////////////////////////////////////////////
void topteam()
{
	char *teams[100];
	int goals[100];
	int i = 0;
	// ������ ����� ������ ������  � ����� ����� � �����. ������
	*(teams + i) = new char[strlen(*((*(ps + i))->teamlist + 0)) + 1];
	strcpy(*(teams + i), *((*(ps + i))->teamlist + 0));
	i++;
	//������ ������ ������ ��� ����������
	for (int g = 0; g < n ; g++)
		for (int k = 0; k < (*(ps + g))->comm; k++)
		{
			int bol = 0;
			for (int j = 0; j < i; j++)
				if (strcmp ( *(teams + j) ,*((*(ps + g))->teamlist + k) ) == 0  )
					bol = 1;
			if (bol == 0)
			{
				*(teams + i) = new char[strlen(*((*(ps + g))->teamlist + k)) + 1];
				strcpy(*(teams + i), *((*(ps + g))->teamlist + k));
				i++;
			}
		}
	// �������� ����� ����� � ������ ���� ����� ����� ����������
	for (int g = 0; g < i; g++)
	{
		*(goals + g) = 0;
	}

	//������� ����� ���������� ����� � ������ �������
	for (int g = 0; g < n ; g++)
		for (int k = 0; k < (*(ps + g))->comm; k++)
		{
			for (int j = 0; j < i; j++)
				if (strcmp( *(teams + j) , *((*(ps + g))->teamlist + k) ) == 0 )
					goals[j] = goals[j] + *(*((*(ps + g))->teamgoals + k));


		}

	//����������
	for (int g = 0; g < i - 1; g++)
		for (int j = g; j < i; j++)
			if (*(goals + g) > *(goals + j))
			{
				int temp;
				char *temp1;

				temp = *(goals + g);
				*(goals + g) = *(goals + j);
				*(goals + j) = temp;

				temp1 = *(teams + g);
				*(teams + g) = *(teams + j);
				*(teams + j) = temp1;



			}
	cout << endl;
	cout << "�������� �������\t" << "���������� �����" << endl;
	for (int g = 0; g < i; g++)
		cout << *(teams + g) << "\t\t\t" << *(goals + g) << endl;

}
///////////////////////////////////////////������� ������� � ������� ����� ����� ����� ������ ���������//////////////////////////////////////////////
void del_player_goals(int a)
{
	for (int i = 0; i < n; i++)
	{
		int goals1 = 0;
		for (int j = 0; j < (*(ps + i))->comm; j++)
			goals1+= *(*((*(ps + i))->teamgoals + j));
		if (goals1 < a)
		{
			del_player(i);
			i--;
		}

	}



}
///////////////////////////////////////////������� �� ����� ������� � ����� ��� ������ �� �������� �������////////////////////////////////////////////////////
void print_by_team(char *a)
{
	cout << endl;
	cout << "������� ������" << "\t" << "���������� ���" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (*(ps + i))->comm; j++)
			if (strcmp(a, *((*(ps + i))->teamlist + j)) == 0)
			{

				char *q1;
				q1 = new char[strlen((*(ps + i))->fullname) + 1];
				strcpy(q1, (*(ps + i))->fullname);
				int g = 0;
				while (*q1 != '\0')
				{
					while (*q1 == ' ' || *q1 == '\n' || *q1 == '\t')// do bykv idem
						q1++;

					for (g; *(q1+g)!= ' '; g++)// �������� ������� � ������
					{
					}
					*(q1 + g) = '\0';
					break;
				}
				cout << q1 << "\t\t\t" << *(*((*(ps + i))->teamplays + j)) << endl;
				delete[] q1;
			}
	
}

/////////////////////////////////////////////////////////////����� � ����� �������������/////////////////////////////////////////////////////
void search_seem_f()
{
	for (int i = 0; i < n-1; i++)
		for (int k = 0; k < (*(ps + i))->comm; k++)
			for (int j = i+1; j < n; j++)
				for (int k1 = 0; k1 < (*(ps + i))->comm; k1++)
				{
					if (strcmp(*((*(ps + i))->teamlist + k), *((*(ps + j))->teamlist + k1)) != 0)
					{
						char *q1;
						char *q2;
						q1 = new char[strlen((*(ps + i))->fullname) + 1];
						strcpy(q1, (*(ps + i))->fullname);
						int g = 0;
						while (*q1 != '\0')
						{
							while (*q1 == ' ' || *q1 == '\n' || *q1 == '\t')// do bykv idem
								q1++;

							for (g; *(q1 + g) != ' '; g++)// �������� ������� � ������
							{
							}
							*(q1 + g) = '\0';
							break;

						}
						q2 = new char[strlen((*(ps + j))->fullname) + 1];
						strcpy(q2, (*(ps + j))->fullname);
						g = 0;
						while (*q2 != '\0')
						{
							while (*q2 == ' ' || *q2 == '\n' || *q2 == '\t')// do bykv idem
								q2++;

							for (g; *(q2 + g) != ' '; g++)// �������� ������� � ������
							{
							}
							*(q2 + g) = '\0';
							break;

						}

						if (strcmp(q1, q2) == 0)
						{
							cout << "�������: ";
							cout << q1<<"\t";
							cout << "��������: ";
							for (int q = 0; q < (*(ps + i))->comm;q++)
							{
								cout << *((*(ps + i))->teamlist + q) << " ";

							}
							cout << endl;

							cout << "�������: ";
							cout << q2<<"\t";
							cout << "��������: ";
							for (int q = 0; q < (*(ps + j))->comm; q++)
							{
								cout << *((*(ps + j))->teamlist + q) << " ";

							}
							cout << endl;

						}
						delete[]q1;
						delete[]q2;


					}
				}
}
/////////////////////////////////////////////////////������ � ������ ������ �������//////////////////////////////////////////////////////
void best_and_worst(char*a)
{
	int min = 0, max = 0;
	for (int i = 0; i < n ; i++)
		for (int k = 0; k < (*(ps + i))->comm; k++)
			if (strcmp(a, *((*(ps + i))->teamlist + k)) == 0)
			{
				max = *(*((*(ps + i))->teamgoals + k));
				min = max;
			}

	for (int j = 0; j < n ; j++)
		for (int k1 = 0; k1 < (*(ps + j))->comm; k1++)
			if (strcmp(a, *((*(ps + j))->teamlist + k1)) == 0)
			{
				if (*(*((*(ps + j))->teamgoals + k1)) > max)
					max = *(*((*(ps + j))->teamgoals + k1));
				else
				{
					if (*(*((*(ps + j))->teamgoals + k1)) < min)
						min = *(*((*(ps + j))->teamgoals + k1));
				}
			}
	cout << "������ ������ " << endl;
	cout << "���\t\t\t���������� �����" << endl;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < (*(ps + i))->comm; k++)
			if (strcmp(a, *((*(ps + i))->teamlist + k)) == 0)
				if (*(*((*(ps + i))->teamgoals + k)) == max)
					cout << (*(ps + i))->fullname << "\t]t" << *(*((*(ps + i))->teamgoals + k));
	cout << endl;
	cout << "������ ������ " << endl;
	cout << "���\t\t\t���������� �����" << endl;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < (*(ps + i))->comm; k++)
			if (strcmp(a, *((*(ps + i))->teamlist + k)) == 0)
				if (*(*((*(ps + i))->teamgoals + k)) == min)
					cout << (*(ps + i))->fullname << "\t\t" << *(*((*(ps + i))->teamgoals + k));


}
//////////////////////////////////////////////������ � ������� ������ ���� ����� �������////////////////////////////////////////////////////////////
void max_status_inteam(char*a)
{
	int m, max=0;
	for (int i = 0; i < n; i++)//���������
		for (int k = 0; k < (*(ps + i))->comm; k++)// ���������� ��� ������� �������������� ������
		{
			if (strcmp(a, *((*(ps + i))->teamlist + k))==0)
			{
				m = 0;
				for (int j = i; j < n; j++)//���������� ��������� ������� � �������������


					for (int k1 = 0; k1 < (*(ps + j))->comm; k1++)//������� ��������� ������� � ����. �������� ����. ������ ��
						if (strcmp(a, *((*(ps + j))->teamlist + k1))==0)
							if (strcmp((*(ps + i))->status, (*(ps + j))->status) == 0)
								m++;

				if (m > max)
					max = m;
			}
		}

	cout << "������ ����� ������� � ������� " << a << " ���� �� ��������" << endl;
	for (int i = 0; i < n ; i++)//���������
		for (int k = 0; k < (*(ps + i))->comm; k++)// ���������� ��� ������� �������������� ������
		{
			if (strcmp(a, *((*(ps + i))->teamlist + k)) == 0)
			{
				m = 0;
				for (int j = i ; j < n; j++)//���������� ��������� ������� � �������������
					for (int k1 = 0; k1 < (*(ps + j))->comm; k1++)//������� ��������� ������� � ����. �������� ����. ������ ��
						if (strcmp(a, *((*(ps + j))->teamlist + k1))==0)
							if (strcmp((*(ps + i))->status, (*(ps + j))->status) == 0)
								m++;

				if (m == max)
					cout << (*(ps + i))->status << endl;
			}
		}
	
}
/////////////////////////////////////////////////////////��������\�������� ���� � ������//////////////////////////////////////////////////////////
void info_add()
{
	cout << "1 - �������� �������(�) � ������ " << endl;
	cout << "2 - �������� ���������� ��� ��� ����� � ������" << endl;
	int x;
	cin >> x;
	if (x == 1)
	{
		cout << "������ ������ �������� �������?" << endl<<"������ �������: "<<endl;

		for (int i = 0; i < n; i++)
			cout << i<<" ";
		int player;
		cin >> player;
		cout << "������� ������ ������ ��������?" << endl;
		int addteam;
		cin >> addteam;
		for (int i = (*(ps + player))->comm; i < (*(ps + player))->comm + addteam;i++)
		{
			char tlist[100];
			int plays, goals;
			*((*(ps + player))->teamplays + i) = new int;
			*((*(ps + player))->teamgoals + i) = new int;
			cout << "������� �������� " << i + 1 << "-� �������: ";
			cin >> tlist;
			cout << "������� ���������� ���, ��������� �� ��� �������: ";
			cin >> plays;
			if (plays > 0) //���� ���� �������� ����
			{
				cout << "������� ���������� ������� ����� �� ��� �������: ";
				cin >> goals;
				*(*((*(ps + player))->teamgoals + i)) = goals;
			}
			else *(*((*(ps + player))->teamgoals + i)) = 0;//���� ���
			(*((*(ps + player))->teamlist + i)) = new char[strlen(tlist) + 1];
			strcpy((*((*(ps + player))->teamlist + i)), tlist);

			*(*((*(ps + player))->teamplays + i)) = plays;
		}
		(*(ps + player))->comm = (*(ps + player))->comm + addteam;

	}
	if (x == 2)
	{
		cout << "������ ������ ������ ���������?" << endl;
		for (int i = 0; i < n; i++)
			cout << i;
		int player;
		cin >> player;

		cout << "�������� �������, � ������� ����� ���������" << endl;
		for (int i = 0; i < (*(ps + player))->comm; i++)
			cout << *((*(ps + player))->teamlist + i) << endl;
		int team;
		cin >> team;
		cout << "1 - �������� ���������� �����" << endl;
		cout << "2 - �������� ���������� ���" << endl;
		int w;
		cin >> w;
		if (w==1)
		{
			cout << "���� ����� - " << *(*((*(ps + player))->teamgoals + team - 1)) << endl << "������� ����� ����� �����" << endl;
			int newgoals;
			cin >> newgoals;
			*(*((*(ps + player))->teamgoals + team - 1)) = newgoals;
		}
		else if (w == 2)
		{
			cout << "���� ��� - " << *(*((*(ps + player))->teamplays + team - 1)) << endl << "������� ����� ����� ���" << endl;
			int newplays;
			cin >> newplays;
			*(*((*(ps + player))->teamplays + team - 1)) = newplays;

		}
	}



}
int _tmain(int argc, _TCHAR* argv[])
{

	setlocale(LC_ALL, "Russian");
	add_from_file();
	char c;
	do
	{
		cout << "�������� ��������: " << endl;
		cout << "1 - ��������� ������ �� ������" << endl;
		cout << "2 - ���������� ������ ������" << endl;
		cout << "3 - ����������" << endl;
		cout << "4 - ����� ������� � ���������� ������ �������" << endl;
		cout << "5 - ������� ������ �� ������� �����" << endl;
		cout << "6 - �������� ������� �� ���������� �����" << endl;
		cout << "7 - ����� ������� �� �������� �������" << endl;
		cout << "8 - ������� ������ ������ �� ������" << endl;
		cout << "9 - ������� ���� �������" << endl;
		cout << "10 - ����� ������������� � ������ ��������" << endl;
		cout << "11 - ����� ������ � ������ ������� �� �������� �������" << endl;
		cout << "12 - ������� ������ ������� ���� ������ ����� � �������� �������" << endl;
		cout << "13 - �������� / �������� ���� � ������" << endl;
		cout << "14 - ������� ��� � ����" << endl;
		int x;
		cin >> x;
		if (x == 14)
		{
			fout();
			for (int i = 0; i < n; i++)
				del_player(i);


		}
		if (x == 1)
		{
			cout << "������� ����� ������ ��� ��������";
			int x1;
			cin >> x1;
			del_player(x1);
		}
		if (x == 2)
			add_player();
		if (x == 3)
			sort();
		if (x == 4)
			max_players_inteam();
		if (x == 5)
			topteam();
		if (x == 6)
		{
			cout << "����� �����" << endl;
			int x3;
			cin >> x3;
			del_player_goals(x3);

		}
		if (x == 7)
		{
			char x4[100];
			cout << "������� �������� �������" << endl;
			cin>>x4;
			print_by_team(x4);

		}
		if (x==8)
		{
			int q;
			cout << "����� ��� ������" << endl;
			cin >> q;
			print(q);
		}
		if (x == 9)
		{
			for (int i = 0; i < n; i++)
				print(i);
		}
		
		if (x == 10)
		{
			search_seem_f();
		}
		if (x == 11)
		{
			char a[20];
			cout << "������� �������� �������";
			cin >> a;
			best_and_worst(a);

		}
		if (x == 12)
		{
			char a[20];
			cout << "������� �������� �������" << endl;
			cin >> a;
			max_status_inteam(a);

		}
		if (x == 13)
		{
			info_add();

		}
		cout << endl;
		cout << "Povtor?" << endl;
		cin >> c;
		
	} while (c == 'y');
	getchar();
	getchar();

	return 0;
}