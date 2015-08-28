#include "baccount.hpp"

BAccount::BAccount(Client* c,string* piban) : Trans(piban)
{
	
	client = c;
	iban = *piban;
	balance = 0;
	
	this->t_balance(&balance);
	
	time_t t = time(0);
	now = localtime(&t);
}

void BAccount::b_whitdraval(string* bankName,string* bancomat)
{
	float amount;
	string causal;
	
	cout << "Inserire importo: ";
	cin >> amount;
	cin.ignore(); //flush the newline of buffer
	cout << "Inserire causale: ";
	getline(cin,causal);
	
	if (amount <= balance && amount >= 0)
	{
		string respons;
		cout << "Stampare ricevuta? [s/n]: ";
		cin >> respons;
		
		if (respons=="s")
		{
			
			
			ofstream ticket("ticket.txt");
			ticket << *bankName << "     " << *bancomat << endl;
			ticket << causal << endl;
			ticket << "     " << balance << "     disponibile prima del prelievo" << endl;
			ticket << "     " << amount << "     prelievo" << endl;
			ticket << "     " << balance-amount << "     disponibile" << endl << endl << endl;
			ticket << "     " << "     " << now->tm_mday << "/" << now->tm_mon+1 << "/" << now->tm_year+1900;
			ticket.close();
		}
		
		amount *= -1;
		this->t_update(&iban,now->tm_mday,now->tm_mon+1,now->tm_year+1900,&amount,&causal);
	}else{
		cout << "L'importo del prelievo non può superare il deposito" << endl;
	}
	
}

string** BAccount::b_transaction()
{
	int n = this->t_dim() - 10;
	string** t;
	if (n < 0)
	{
		n=0;
		t = new string*[this->t_dim()];
	}else{
		t = new string*[10];
	}
	for (int i = 0;n < this->t_dim();i++)
	{
		t[i] = new string[3];
		t[i][0] = this->t_date(n);
		t[i][1] = this->t_amount(n);
		t[i][2] = this->t_causal(n);
		n++;
	}
	
	return t;
}

string** BAccount::b_ltransaction(int* sdd,int* smm,int* syy,int* edd,int* emm,int* eyy)
{
	int n = this->t_dim() - 10;
	string** t = 0;
	if (n < 0)
	{
		n=0;
		t = new string*[this->t_dim()];
	}else{
		t = new string*[10];
	}
	for (int i = 0;n < this->t_dim();i++)
	{
		t[i] = new string[3];
		t[i][0] = this->t_date(n);
		t[i][1] = this->t_amount(n);
		t[i][2] = this->t_causal(n);
		n++;
	}
	
	return t;
}

void  BAccount::b_telRecharge(string* bankName,string* bancomat)
{
	float amount;
	string number;
	
	cout << "Importo: ";
	cin >> amount;
	cout << "Numero di telefono: ";
	cin >> number;
	
	if (amount <= balance && amount > 0)
	{
		string t;
		cout << "Stampare scontrino? [s/n]: ";
		cin >> t;
		
		if (t=="s")
		{
			ofstream rech("recharge.txt");
			rech << *bankName << "     " << *bancomat << endl;
			rech << "     Importo ricarica : " << amount << "     " << endl;
			rech << "     Numero di telefono : " << number << "     " << endl << endl << endl;
			rech << "     " << "     " << now->tm_mday << "/" << now->tm_mon+1 << "/" << now->tm_year+1900;
			rech.close();
		}
		
		t = "Ricarica telefonica num: " + number;
		
		amount *= -1;
		this->t_update(&iban,now->tm_mday,now->tm_mon+1,now->tm_year+1900,&amount,&t);
	}else{
		cout << "La ricarica non può superare il deposito" << endl;
		cout << "e l'importo deve essere maggiore di 0." << endl;
	}
}