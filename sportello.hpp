#ifndef SPORTELLO_H_
#define SPORTELLO_H_

#include <iostream>

#include "client.hpp"
#include "baccount.hpp"

using namespace std;

class Sportello
{
public:
	Sportello(string,string);

private:
	void s_functions(BAccount*);
	void s_printTransactions(int,string**);

private:
	string code;
	string bankname;
};

#endif