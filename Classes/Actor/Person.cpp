#include "Person.h"

Person::Person(int type)
{
	this->type = type;
	this->posState = Constant::STATE_LEFT;
	this->boatState = Constant::STATE_OFFBOAT;
}

Person::~Person()
{
}

Person* Person::createPerson(const char* pName, int type)
{
	Person * person = new Person(type);
	if(person && person->initWithFile(pName) )
	{
		person->autorelease();
		return person;
	}
	CC_SAFE_DELETE(person);
	return NULL;
}

void Person::onEnter()  
{  
	CCDirector* pDirector = CCDirector::sharedDirector();  
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);  
	CCSprite::onEnter();  
}  
  
void Person::onExit()  
{  
	CCDirector* pDirector = CCDirector::sharedDirector();  
	pDirector->getTouchDispatcher()->removeDelegate(this);  
	CCSprite::onExit();  
}  

bool Person::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCPoint sLocalPos = convertToNodeSpace(touch->getLocation());  
	CCRect sRC = CCRect(getPositionX() - getContentSize().width * getAnchorPoint().x,  
						   getPositionY() - getContentSize().height * getAnchorPoint().y,  
						   getContentSize().width, getContentSize().height);  
	  
	  
	sRC.origin = CCPointZero;  
	bool isTouched = sRC.containsPoint(sLocalPos);  
	if(isTouched){
		if(lock == 0){
		if(boatState == Constant::STATE_OFFBOAT)//登船
		{
			int count = 0;
			int count2 = 0;
			for(int i = 0; i < record.size(); i++){
				if(record[i]->boatState == 10)
					count++;
			}
			for(int i = 0; i < record.size(); i++){
				if(record[i]->boatState == Constant::STATE_ONBOAT)
					count2++;
			}
			if(count2 == 0){
			if(count < 2){
				if(count == 0){
					boatState =  10;  //新上船	
					boatloc = Constant::ON_BOAT_LEFT;
					this->jumpToBoat(Constant::ON_BOAT_LEFT);
				}
				if(count == 1){
					boatState =  10;  //新上船	
					boatloc = Constant::ON_BOAT_RIGHT;
					this->jumpToBoat(Constant::ON_BOAT_RIGHT);				}
			}
			}
			else{}
		}
	}
		else{}
	}
	return true;
}

void Person::ccTouchMoved(CCTouch* touch, CCEvent* event) {}
void Person::ccTouchEnded(CCTouch* touch, CCEvent* event) {}

int Person::getType()
{
	return type;
}

void Person::jumpToBoat(int n)//位置信息修改
{
	if(posState == Constant::STATE_LEFT)
	{
		CCJumpTo * action = CCJumpTo::create(0.5f, ccp(200+n, 125), 50, 1);
		this->runAction(action);
	} 
	else 
	{
		CCJumpTo * action = CCJumpTo::create(0.5f, ccp(450+n, 125), 50, 1);
		this->runAction(action);
	}
}

void Person::leaveBoat(int locx, int locy)
{
	if(posState == Constant::STATE_LEFT)
	{

		CCJumpTo * action = CCJumpTo::create(0.5f, ccp(20 + locx,125 + locy), 50, 1);
		this->runAction(action);
	} 
	else 
	{
		CCJumpTo * action = CCJumpTo::create(0.5f, ccp(600 + locx,125 + locy), 50, 1);
		this->runAction(action);
	}
}
void Person::setPositions(int p){
	position = p;
}
int Person::getPositions(){
	return position;
}