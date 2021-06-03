#pragma once


#include "THEATRE.h"
#include "USER.h"

struct THEATRES {

	LIST <THEATRE> theatres;
	LIST <USER> users;

	void printUsers();

	void theatreOutput();

	void nextFucntionToBuyATicket(USER* me, THEATRE* theatre);

	void buyingATicket(USER* me);


	void USERMyData(USER* me);
	void ListToMassive(int);
	void SORTtheatreOutputMonth();
	void ListToMassive();
	void SORTtheatreOutput();
	void USERmenu(USER* me);


	bool perfomanceMenu(PERFOMANCE* perfomance, THEATRE* theatre);
	void findPerformance(THEATRE* theatre);
	bool theatreMenu(THEATRE* theatre);
	void findTheatres(bool status);
	void AdminUserMenu(USER* user);
	void findUsers();
	void ADMINmenu();




	bool checkREG(USER* user);

	void USERregistration();


	void USERauthorization();
	void authorisationMenu();
};