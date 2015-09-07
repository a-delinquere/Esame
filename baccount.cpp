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
		this->t_balance(&balance);
	}else{
		cout << "L'importo del prelievo non può superare il deposito" << endl;
	}

}

string** BAccount::b_transaction(int* i)
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
	for (*i = 0;n < this->t_dim();*i+=1)
	{
		t[*i] = new string[3];
		t[*i][0] = this->t_date(n);
		t[*i][1] = this->t_amount(n);
		t[*i][2] = this->t_causal(n);
		n++;
	}

	return t;
}

string** BAccount::b_transaction(int* n,int* sdd,int* smm,int* syy,int* edd,int* emm,int* eyy)
{
	string** t = 0;
	int dd,mm,yy;
	dd = mm = yy = *n = 0;
	int daytoend = b_dayCount(sdd,smm,syy,edd,emm,eyy);

	for (int i = 0;i < this->t_dim();i++)
	{
		b_splitDate(i,&dd,&mm,&yy);
		int daytoday = b_dayCount(sdd,smm,syy,&dd,&mm,&yy);
		
		if (0 <= daytoday && daytoday <= daytoend)
		{
			t = b_append(*n,t);
			t[*n] = new string[3];
			t[*n][0] = this->t_date(i);
			t[*n][1] = this->t_amount(i);
			t[*n][2] = this->t_causal(i);
			*n += 1;
		}
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
	this->t_balance(&balance);
}

void BAccount::b_splitDate(int i,int* gg,int* mm,int* aa)
{
	*gg = *mm = *aa = 0;

	string sgg,smm,saa;
	stringstream date(this->t_date(i));
	getline(date,sgg,'/');
	getline(date,smm,'/');
	getline(date,saa,'\0');

	stringstream converter;
	converter << sgg;
	converter >> *gg;

	converter.clear();
	converter << smm;
	converter >> *mm;

	converter.clear();
	converter << saa;
	converter >> *aa;
}

int BAccount::b_dayCount(int* igg,int* imm,int* iaa,int* gg,int* mm,int* aa)
{
	int day = 0;

	struct tm da = {0,0,0,*igg,*imm-1,*iaa-1900};
	struct tm a = {0,0,0,*gg,*mm-1,*aa-1900};

	time_t x = mktime(&da);
	time_t y = mktime(&a);

	day = difftime(y,x)/(60*60*24);

	return day;
}

string** BAccount::b_append(int n,string** oldarray)
{
	string** newarray = new string*[n+1];
	for (int i = 0;i < n; i++)
	{
		newarray[i] = new string[3];
		newarray[i][0] = oldarray[i][0];
		newarray[i][1] = oldarray[i][1];
		newarray[i][2] = oldarray[i][2];
	}
	
	//memcpy(newarray,oldarray,sizeof(string[n][3]));
	
	delete oldarray; 

	return newarray;
}