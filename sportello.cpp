#include "sportello.hpp"

Sportello::Sportello(string* c,string* bn)
{
	code = *c;
	bankname = *bn;
	
	string name,surname,password,cc;
	/*cout << "inserire nome e cognome:\n";
	cin >> name >> surname;
	cout << "inserire password:\n";
	cin >> password;*/
	name = "raffaele";surname="mancino";password="password"; //comment for relese
	
	Client* client = new Client(&name,&surname,&password);
	if (client->c_loginTest(&cc))
	{
		cout << "Login Effettuato" << endl;
		BAccount* baccount = new BAccount(client,&cc);
		s_functions(baccount);
	}else{
		cout << "Cliente o password errati" << endl;
	}
}

void Sportello::s_functions(BAccount* ba)
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
			ba->b_whitdraval(&bankname,&code);
		}
			break;
		case 1:
		{
			string** t;
			int n = 10;
			t = ba->b_transaction();
			s_printTransactions(&n,t);
		}
			break;
		case 2:
		{
			string** t;
			int sday,eday,smonth,emonth,syear,eyear;
			cout << "da: ";
			cin >> sday >> smonth >> syear;
			cout << "a: ";
			cin >> eday >> emonth >> eyear;
			t = ba->b_ltransaction(&sday,&smonth,&syear,&eday,&emonth,&eyear);
			//int n = 14;
			//s_printTransactions(&n,t);
		}
			break;
		case 3:
		{
			
			ba->b_telRecharge(&bankname,&code);
		}
			break;
	}
}


void Sportello::s_printTransactions(int* n,string** vector)
{
	for (int i = 0;i<*n;i++)
	{
		cout << vector[i][0] << " " << vector[i][1] << " " << vector[i][2] << endl;
	}
}