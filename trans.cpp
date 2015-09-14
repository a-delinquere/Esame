#include "trans.hpp"

Trans::Trans(string* iban)
{
	fdb = new FileDatabase;
	trans = fdb->fdb_query(&len,iban);
}

Trans::~Trans()
{
	delete fdb;
	for (int i = 0;i < len;i++)
	{
		delete trans[i];
	}
	delete trans;
}

void Trans::t_update(string* iban,int dd,int mm,int aa,float* value,string* causal)
{
	stringstream convert;
	string txt;
	convert << dd << "/" << mm << "/" << aa << " " << *value << " " << *causal;
	txt = convert.str();
	
	fdb->fdb_write(iban,&txt);
	trans = fdb->fdb_query(&len,iban);
}

void Trans::t_balance(float* balance)
{
	float v = 0;
	
	for (int i = 0;i < len;i++)
	{
		sscanf(trans[i][1].c_str(),"%f",&v);
		*balance += v;
	}
}

int Trans::t_dim()
{
	return len;
}
	
string Trans::t_date(int i)
{
	return trans[i][0];
}

string Trans::t_amount(int i)
{
	return trans[i][1];
}

string Trans::t_causal(int i)
{
	return trans[i][2];
}