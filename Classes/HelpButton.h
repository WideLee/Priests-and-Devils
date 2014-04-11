#ifndef _HELP_H_
#define _HELP_H_

#include "cocos2d.h"
#include "Actor/Boat.h"
#include <vector>
#include <string>

USING_NS_CC;

class HelpButton : public CCSprite, public CCTouchDelegate
{
public:
	int state;
	Boat * boat;
	CCLabelTTF * labelWelcome;
	CCLabelTTF * labelWelcome1;
	CCLabelTTF * labelWelcome2;
	CCLabelTTF * labelWelcome3;
	CCLabelTTF * labelWelcome4;
	

	HelpButton();
	~HelpButton();
	static HelpButton* createHelp(const char * pName);	

	virtual void onEnter();  
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch * touch, CCEvent * event);
	virtual void ccTouchMoved(CCTouch * touch, CCEvent * event);
	virtual void ccTouchEnded(CCTouch * touch, CCEvent * event);	

	
};

#endif