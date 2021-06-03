#pragma once


#include "TICKET.h"

struct USER {
	string login;
	string password;
	LIST<TICKET> tickets;
	USER* next;
	bool ban;

	static void headOfTheTable()
	{
		cout << "==============================================================================" << endl;
		cout << "|| Логин                          | Пароль                         | Статус ||" << endl;
		cout << "||==========================================================================||" << endl;
	}
	static void bottomOfTheTable()
	{
		cout << "==============================================================================" << endl;
	}
	static void Error()
	{
		cout << "Пользователь с таким логином уже зарегестрирован" << endl;
		system("pause");
	}
	static string fileName() { return "users.txt"; }
	bool inputLogin();
	bool inputPassword();
	bool input();
	bool compare(string login, string password);

	bool compare(USER* user);
	void fwrite(ofstream& file);
	void fread(ifstream& file);
	void choiceTicket();
	bool microMenu();
	void printTicket();
	void Block();
	void unBlock();
	void output();

};