#include "Devils.h"

Devils::Devils() : Person(Constant::PERSON_DEVIL)
{
}
Devils::~Devils()
{
}

Devils* Devils::createDevils(const char* pName)
{
	Devils * devils = new Devils();
	if(devils && devils->initWithFile(pName) )
	{
		devils->autorelease();
		return devils;
	}
	CC_SAFE_DELETE(devils);
	return NULL;
}

void Devils::killPriest()
{
	// TODO
}