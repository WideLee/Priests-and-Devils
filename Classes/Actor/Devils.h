#ifndef _DEVILS_H_
#define _DEVILS_H_

#include "cocos2d.h"
#include "Person.h"

USING_NS_CC;

class Devils : public Person
{
public:
	Devils();
	~Devils();
	static Devils* createDevils(const char * pName);

	void killPriest();
};

#endif