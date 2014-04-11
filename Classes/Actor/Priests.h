#ifndef _PRIESTS_H_
#define _PRIESTS_H_

#include "cocos2d.h"
#include "Person.h"

USING_NS_CC;

class Priests : public Person
{
public:
	Priests();
	~Priests();
	static Priests* createPriests(const char * pName);

	void killByDevils();
};

#endif