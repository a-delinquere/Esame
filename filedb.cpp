#include "filedb.hpp"
bool FileDatabase::fdb_login(string* name_s,string* surname_s,string* password_s,string* cc_s)
{
	db.open("bank/username.txt");
	bool resp = false;
	string line;
	
	while(!db.eof())
	{
		string name,surname,password,cc;
		getline(db,name,' ');
		getline(db,surname,' ');
		getline(db,password,' ');
		getline(db,cc,'\n');
		if (name==*name_s && surname==*surname_s && password==*password_s)
		{
			resp = true;
			*cc_s = cc;
			break;
		}
	}
	db.close();
	return resp;
}

string** FileDatabase::fdb_query(int* lines,string* cc_name)
{
	*lines = 0;
	
	string path;
	path = "bank/"+*cc_name+".txt";
	
	db.open(path.c_str());
	fdb_numOfLine(lines);
	
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

void FileDatabase::fdb_write(string* cc,string* txt)
{
	string path;
	path = "bank/"+*cc+".txt";
	
	db.open(path.c_str());
	db.seekg(0,ios::end);
	
	db << endl << *txt;
	
	db.close();
}

void FileDatabase::fdb_numOfLine(int* n)
{
	string t;
	*n = 0;
	
	while(getline(db,t))
	{
		*n += 1;
	}
	db.clear();
	db.seekg(0);//rewind filestream
}