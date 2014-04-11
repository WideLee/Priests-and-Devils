#ifndef _BOAT_H_
#define _BOAT_H_

#include "cocos2d.h"
#include "Constant.h"
#include "Actor/Person.h"
#include "Actor/Bank.h"
#include <vector>


USING_NS_CC;

class Boat : public CCSprite, public CCTouchDelegate
{
public:
	Person * left;
	Person * right;
	std::vector<Bank *> vb;
	std::vector<Person *> record;
	CCLabelTTF * labelWelcome;
	CCProgressTimer * pr;
	int count;
	int state;
	
public:
	Boat();
	~Boat();
	static Boat* createBoat(const char * pName);
	
	virtual void onEnter();  
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch * touch, CCEvent * event);
	virtual void ccTouchMoved(CCTouch * touch, CCEvent * event);
	virtual void ccTouchEnded(CCTouch * touch, CCEvent * event);

	bool addPerson(Person * person);
	bool removePerson(Person * person);
	int getState();
};

#endif