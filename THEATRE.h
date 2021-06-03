#pragma once


#include "PERFOMANCES.h"
#include "LIST.h"



struct THEATRE
{
	string nameOfTheatre;
	LIST<PERFOMANCE> performances;
	THEATRE* next;


	static string fileName() { return "theatre.txt"; }
	static void headOfTable()
	{
		cout << std::setiosflags(std::ios_base::left) << setw(20) << "Название театра";
		cout << "Кол-во представлений" << endl;
	}
	static void headOfFULLTable()
	{
		cout << "==================================================================" << endl;
		cout << "|| Название театра      | Кол-во представлений | Кол-во билетов ||" << endl;
		cout << "||==============================================================||" << endl;
	}
	static void bottomOfFULLTable()
	{
		cout << "==================================================================" << endl;
	}

	int getCount();
	int getCount(int);
	void input();
	void outputMonth(int);
	void output();
	void userMenu();
	void ListToMassive();
	void ListToDateMassive();
	void ListToPopularMassive(int);
	void SORTtheatreOutput();
	void SORTtheatreDateOutput();
	void SORTtheatrePopularOutput();
	int getCountPerfomance(int);
	void fwrite(ofstream&);
	void fread(ifstream&);

	bool compare(THEATRE*);
	bool check(PERFOMANCE*);
	void outputFULL();

};