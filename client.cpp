#include "client.hpp" 

Client::Client(string* n,string* c,string* p)
{
	name = *n;
	surname = *c;
	password = *p;
}

bool Client::c_loginTest(string* i)
{
	FileDatabase* fdb = new FileDatabase();
	return fdb->fdb_login(&name,&surname,&password,i);
}

string Client::c_getName()
{
	return name;
}

string Client::c_getSurname()
{
	return surname;
}

string Client::c_getPassword()
{
	return password;
}