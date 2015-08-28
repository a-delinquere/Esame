#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <iostream>
#include <string>
#include <ctime>

#include "trans.hpp"

class Client; //delcaration as incomplete type

using namespace std;

class BAccount: private Trans
{
public:
	BAccount(Client*,string*);
	void b_whitdraval(string*,string*); //prelievo
	string** b_transaction(); //movimenti
	string** b_ltransaction(int*,int*,int*,int*,int*,int*); //movimenti intervallo
	void b_telRecharge(string*,string*); //ricarica telefonica

private:
	Client* client;
	Trans* trans;
	float balance;
	string iban;
	struct tm* now;
};

#include "client.hpp" //define Client type

#endif