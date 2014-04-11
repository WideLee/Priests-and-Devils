#ifndef _PERSON_H_
#define _PERSON_H_

#include "cocos2d.h"
#include "Constant.h"


USING_NS_CC;

class Person : public CCSprite, public CCTouchDelegate
{
public:
	int type;
	int boatState;
	std::vector<Person *> record;
	int position;
	int posState;
	int boatloc;
	int lock;//0 can touch, 1 can't touch
public:
	Person(int type);
	~Person();
	static Person* createPerson(const char * pName, int type) ;

	

	virtual void onEnter();  
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch * touch, CCEvent * event);
	virtual void ccTouchMoved(CCTouch * touch, CCEvent * event);
	virtual void ccTouchEnded(CCTouch * touch, CCEvent * event);
	
	int getType();
	void jumpToBoat(int n);
	void leaveBoat(int locx, int locy);
	void setPositions(int p);
	int getPositions();
};

#endif