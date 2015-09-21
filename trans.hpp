#ifndef TRANS_H_
#define TRANS_H_

#include <iostream>
#include <sstream>

#include "filedb.hpp"

using namespace std;

class Trans
{
public:
	Trans(string);
	Trans(const Trans&); //costruttore di copie
	~Trans();
	void t_update(int,int,int,float,string); //aggiorna le transazioni aggiungendo un elemento
	float t_balance(); //calcola il risultato dei valori delle transazioni
	string** operator<<(const string&);
	
protected:
	int t_dim();
	string t_date(int);
	string t_amount(int);
	string t_causal(int);
	
private:
	string** trans;
	string iban;
	int len;
	FileDatabase* fdb;
};


/*string** operator+ (int const& a,string const& txt)
{
	cout << txt << " " << a << endl;
	return 0;
}*/

#endif