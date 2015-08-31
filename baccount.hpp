#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <iostream>
#include <cstring>
#include <sstream>
#include <ctime>

#include "trans.hpp"

class Client; //delcaration as incomplete type

using namespace std;

class BAccount: private Trans
{
public:
	BAccount(Client*,string*);
	void b_whitdraval(string*,string*); //prelievo
	string** b_transaction(int*); //movimenti
	string** b_transaction(int*,int*,int*,int*,int*,int*,int*); //movimenti intervallo
	void b_telRecharge(string*,string*); //ricarica telefonica

private:
	void b_splitDate(int,int*,int*,int*);
	int b_dayCount(int*,int*,int*,int*,int*,int*);
	string** b_append(int,string**);

private:
	Client* client;
	Trans* trans;
	float balance;
	string iban;
	struct tm* now;
};

#include "client.hpp" //define Client type

#endif