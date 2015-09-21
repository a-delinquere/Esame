#include "trans.hpp"

Trans::Trans(string cc)
{
	iban = cc;
	fdb = new FileDatabase;
	trans = fdb->fdb_query(&len,iban);
}

Trans::Trans(const Trans& original)
{
	iban = original.iban;
	len = original.len;
	trans = new string*[original.len];
	for (int i = 0;i < original.len;i++)
	{
		trans[i] = new string[3];
		trans[i][0] = original.trans[i][0];
		trans[i][1] = original.trans[i][1];
		trans[i][2] = original.trans[i][2];
	}
	fdb = new FileDatabase;
}

Trans::~Trans()
{
	delete fdb;
	for (int i = 0;i < len;i++)
	{
		delete[] trans[i];
	}
	delete[] trans;
}

void Trans::t_update(int dd,int mm,int aa,float value,string causal)
{
	stringstream convert;
	string txt;
	convert << dd << "/" << mm << "/" << aa << " " << value << " " << causal;
	txt = convert.str();
	
	trans = operator<<(txt);
	//trans << txt;
	//fdb->fdb_write(iban,txt);
	//trans = fdb->fdb_query(&len,iban);
}

string** Trans::operator<<(const string& txt)
{
	fdb->fdb_write(iban,txt);
	return fdb->fdb_query(&len,iban);
}

float Trans::t_balance()
{
	float v,balance = 0;
	
	for (int i = 0;i < len;i++)
	{
		sscanf(trans[i][1].c_str(),"%f",&v);
		balance += v;
	}
	
	return balance;
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