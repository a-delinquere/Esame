#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <iostream>
#include <string>
#include <ctime>

#include "trans.hpp"

class Client; //delcaration as incomplete type

using namespace std;

class BAccount: virtual private Trans
{
public:
	BAccount(Client*,string);
	~BAccount();
	void b_whitdraval(string,string); //prelievo
	string** b_transaction(int*); //movimenti
	string** b_transaction(int*,int,int,int,int,int,int); //movimenti intervallo
	void b_telRecharge(string,string); //ricarica telefonica

private:
	void b_splitDate(int,int*,int*,int*); //separa la data da string in 3 interi
	int b_dayCount(int,int,int,int,int,int); //conta i giorni tra 2 date
	string** b_append(int,string**); //aggiunge un elemento a un vettore

private:
	Client* client;
	float balance;
	string iban;
	struct tm* now;
};

#include "client.hpp" //define Client type

#endif