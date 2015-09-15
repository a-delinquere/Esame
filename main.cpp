#include <iostream>
#include <cstring>

#include "sportello.hpp"

#define BANKNAME "monte dei paschi di siena"
#define BANCOMAT_NUMBER "0000000001"

using namespace std;

void debug(string*,string*,string*);
void array2D(int*,string**);

int main()
{
	string bankName,bancomat;
	bankName = BANKNAME;
	bancomat = BANCOMAT_NUMBER;
	
	Sportello sport(bankName,bancomat);
	
	return 0;
}