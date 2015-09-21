#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

#include "trans.hpp"

class Client;

using namespace std;

class BAccount: virtual private Trans
{
public:
	BAccount(Client*,string);
	BAccount(const BAccount&); //costruttore di copie
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
};

#include "client.hpp"

#endif