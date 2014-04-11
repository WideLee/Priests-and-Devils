#include "Priests.h"

Priests::Priests() : Person(Constant::PERSON_PRIEST)
{
}
Priests::~Priests()
{
}

Priests* Priests::createPriests(const char* pName)
{
	Priests * priests = new Priests();
	if(priests && priests->initWithFile(pName) )
	{
		priests->autorelease();
		return priests;
	}
	CC_SAFE_DELETE(priests);
	return NULL;
}

void Priests::killByDevils()
{
	// TODO
}