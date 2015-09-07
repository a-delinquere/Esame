#ifndef FILEDATABASE_H_
#define FILEDATABASE_H_

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class FileDatabase
{
public:
	bool fdb_login(string*,string*,string*,string*);  //login control
	string** fdb_query(int*,string*); //return all transations
	void fdb_write(string*,string*);
	
private:
	int fdb_numOfLine();
private:
	fstream db;
};

#endif