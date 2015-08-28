#ifndef TRANS_H_
#define TRANS_H_

#include <iostream>
#include <cstdio>
#include <sstream>

#include "filedb.hpp"

using namespace std;

class Trans
{
public:
	Trans(string*);
	void t_init(string*);
	void t_update(string*,int,int,int,float*,string*);
	void t_balance(float*);
	
protected:
	int t_dim();
	string t_date(int);
	string t_amount(int);
	string t_causal(int);
	
private:
	string** trans;
	int len;
	FileDatabase* fdb;
	
private:
	int t_transLen();
};

#endif