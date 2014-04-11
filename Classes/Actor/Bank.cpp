#include "Bank.h"

Bank::Bank(){
}

Bank::~Bank(){
}

Bank * Bank::createBank(const char * pName)
{
	Bank * bank = new Bank();
	if(bank && bank->initWithFile(pName) )
	{
		bank->autorelease();
		return bank;
	}
	CC_SAFE_DELETE(bank);
	return NULL;
}

location::location(int t, int ie){
	type = t;  //
	isempty = ie;  // 0 is empty

}