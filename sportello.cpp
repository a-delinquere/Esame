#include "sportello.hpp"

Sportello::Sportello(string c,string bn)
{
	code = c;
	bankname = bn;

	string username,password,cc;
	/*cout << "inserire username:\n";
	cin >> username;
	cout << "inserire password:\n";
	cin >> password;*/
	username="raffaelemancino";password="password"; //comment for relese
	//Client client(username,password);
	//Person* user = &client;
	Client* user = new Client(username,password);
	
	if (user->c_loginTest(&cc))
	{
		cout << "Login Effettuato" << endl;
		BAccount baccount(user,cc);
		s_functions(baccount);
	}else{
		cout << "Username o password errati" << endl;
	}
}

void Sportello::s_functions(BAccount bank)
{
	int ctrl;
	cout << "Per effettuare un prelievo digitare \"0\"," << endl;
	cout << "Per visualizzare gli ultimi movimenti digitare \"1\"," << endl;
	cout << "Per visualizzare i movimenti in un intervallo digitare \"2\"," << endl;
	cout << "Per effettuare una ricarica telefonica digitare \"3\"," << endl;
	cout << "Codice operazione: ";
	cin >> ctrl;

	switch(ctrl)
	{
		case 0:
		{
			bank.b_whitdraval(bankname,code);
		}
			break;
		case 1:
		{
			string** t;
			int n;
			t = bank.b_transaction(&n);
			s_printTransactions(n,t);
		}
			break;
		case 2:
		{
			int n;
			string** t;
			int sday,eday,smonth,emonth,syear,eyear;
			cout << "da: ";
			cin >> sday >> smonth >> syear;
			cout << "a: ";
			cin >> eday >> emonth >> eyear;
			t = bank.b_transaction(&n,sday,smonth,syear,eday,emonth,eyear);
			s_printTransactions(n,t);
		}
			break;
		case 3:
		{

			bank.b_telRecharge(bankname,code);
		}
			break;
	}
}


void Sportello::s_printTransactions(int n,string** vector)
{
	for (int i = 0;i<n;i++)
	{
		cout << vector[i][0] << " " << vector[i][1] << " " << vector[i][2] << endl;
	}
}