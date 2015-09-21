#include "filedb.hpp"
bool FileDatabase::fdb_login(string username_s,string password_s,string* name_s,string* surname_s,string* cc_s)
{
	db.open("bank/username.txt");
	bool resp = false;
	string line;
	
	while(!db.eof())
	{
		string username,password,name,surname,cc;
		getline(db,username,' ');
		getline(db,password,' ');
		getline(db,name,' ');
		getline(db,surname,' ');
		getline(db,cc,'\n');
		if (username==username_s && password==password_s)
		{
			resp = true;
			*name_s = name;
			*surname_s = surname;
			*cc_s = cc;
			break;
		}
	}
	db.close();
	return resp;
}

string** FileDatabase::fdb_query(int* lines,string cc_name)
{
	*lines = 0;
	
	string path;
	path = "bank/"+cc_name+".txt";
	
	db.open(path.c_str());
	*lines = fdb_numOfLine();
	
	string** transaction= new string*[*lines];
	
	for(int i = 0;i < *lines;i++)
	{
		transaction[i] = new string[3];
		getline(db,transaction[i][0],' ');
		getline(db,transaction[i][1],' ');
		getline(db,transaction[i][2],'\n');
	}
	db.close();
	return transaction;
}

void FileDatabase::fdb_write(string cc,string txt)
{
	string path;
	path = "bank/"+cc+".txt";
	
	db.open(path.c_str());
	db.seekg(0,ios::end);
	
	db << endl << txt;
	
	db.close();
}

int FileDatabase::fdb_numOfLine()
{
	string t;
	int n = 0;
	
	while(getline(db,t))
	{
		n++;
	}
	db.clear();
	db.seekg(0);//rewind filestream
	
	return n;
}