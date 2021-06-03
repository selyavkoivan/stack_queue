#pragma once


#include "THEATRE.h"

struct TICKET
{
	TICKET* next;
	THEATRE* theatre;
	PERFOMANCE* perfomance;
	unsigned int ticketNumber;

	static void headOfTheTable()
	{

		cout << "=====================================================================" << endl;
		cout << "|| Название театра                | Название представления         ||" << endl;
		cout << "||=================================================================||" << endl;
	}
	static void bottomOfTheTable()
	{
		cout << "=====================================================================" << endl;
	}
	TICKET();
	void add(THEATRE* theatre, PERFOMANCE* perfomance);
	void fwrite(ofstream& file);
	void fread(ifstream& file);

	void output();
	void input();
	bool compare(TICKET* ticket);
	void printFullData();
};