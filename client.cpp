#include "client.hpp" 
Client::Client()
{
	username = "";
	password = "";
}


Client::Client(string u,string p)
{
	username = u;
	password = p;
}

bool Client::c_loginTest(string* cc)
{
	FileDatabase* fdb = new FileDatabase();
	return fdb->fdb_login(username,password,&name,&surname,cc);
}

string Client::c_getUsername()
{
	return username;
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