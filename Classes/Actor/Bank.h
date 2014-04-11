#ifndef _BANK_H_
#define _BANK_H_

#include "cocos2d.h"

#include <vector>
USING_NS_CC;

class location{
public:
	int type;
	int isempty;
	location(int t, int ie);
};

class Bank : public CCSprite
{
public:
	std::vector<location> l;
	Bank();
	~Bank();
	static Bank* createBank(const char * pName);	
};

#endif