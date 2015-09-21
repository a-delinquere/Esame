#ifndef CLIENTE_HPP_
#define CLIENTE_HPP_

#include <iostream>
#include <string>

#include "filedb.hpp"
#include "baccount.hpp"

using namespace std;

class Client
{
friend class BAccount;
public:
	Client();
	Client(string,string);
	bool c_loginTest(string*); //controlla se l'utente è valido ritornando un booleano e se valido inizializza il valore iban
	string c_getUsername();
	string c_getName();
	string c_getSurname();
	string c_getPassword();
private:
	string name;
	string surname;
	string username;
	string password;
};

#endif