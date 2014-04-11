#ifndef _RESTART_H_
#define _RESTART_H_

#include "cocos2d.h"
#include "Actor/Boat.h"
#include "HelpButton.h"
#include <vector>
#include <string>

USING_NS_CC;

class RestartButton : public CCSprite, public CCTouchDelegate
{
public:
	HelpButton * help;
	CCLabelTTF * labelWelcome;
	CCLabelTTF * labelWelcome1;
	CCLabelTTF * labelWelcome2;
	CCLabelTTF * labelWelcome3;
	CCLabelTTF * labelWelcome4;

	CCLabelTTF * labelWelcome5;
	CCLabelTTF * labelWelcome6;
	CCLabelTTF * labelWelcome7;
	CCLabelTTF * labelWelcome8;
	CCLabelTTF * labelWelcome9;

	RestartButton();
	~RestartButton();
	static RestartButton* createHelp(const char * pName);	

	virtual void onEnter();  
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch * touch, CCEvent * event);
	virtual void ccTouchMoved(CCTouch * touch, CCEvent * event);
	virtual void ccTouchEnded(CCTouch * touch, CCEvent * event);	

	
};

#endif