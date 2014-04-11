#include "Begin.h"

Begin::Begin(){
}

Begin::~Begin(){
}

Begin * Begin::createBegin(const char * pName)
{
	Begin * bank = new Begin();
	if(bank && bank->initWithFile(pName) )
	{
		bank->autorelease();
		return bank;
	}
	CC_SAFE_DELETE(bank);
	return NULL;
}

