#ifndef FILEDATABASE_H_
#define FILEDATABASE_H_

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class FileDatabase
{
public:
	bool fdb_login(string,string,string*,string*,string*);  //effattua il controllo su username e password e se valido inizializza nome cognome e c/c
	string** fdb_query(int*,string); //ritorna l'array delle trasazioni effettuate (int* modifica il numero di elementi)
	void fdb_write(string,string); //scrive su file delle transazioni
	
private:
	int fdb_numOfLine();
private:
	fstream db;
};

#endif