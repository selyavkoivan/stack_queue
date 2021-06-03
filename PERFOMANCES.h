#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;


struct PERFOMANCE {
	double priceForTicket;
	unsigned int amountOfPurchasedTickets;
	string nameOfPerfomance;
	int day;
	int month;
	int year;

	PERFOMANCE* next;

	static void headOfTheTable()
	{
		cout << "===============================================================================" << endl;
		cout << "|| Название представления         | Дата       | Цена BYR | Проданные билеты ||" << endl;
		cout << "||===========================================================================||" << endl;

	}
	static void BottomOfTheTable()
	{
		cout << "===============================================================================" << endl;
	}

	void input();
	void inputName();
	void inputDate();

	void output();
	void fwrite(ofstream& file);
	void fread(ifstream& file);
	bool compare(PERFOMANCE* performance);
	bool compare(string name);
	int getCount(int);
	string getDate();
};