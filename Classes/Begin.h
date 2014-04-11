#ifndef _BEGIN_H_
#define _BEGIN_H_

#include "cocos2d.h"
#include "Restart.h"

#include <vector>
USING_NS_CC;


class Begin : public CCSprite
{
public:
	RestartButton *re;
	Begin();
	~Begin();
	static Begin* createBegin(const char * pName);	
};

#endif