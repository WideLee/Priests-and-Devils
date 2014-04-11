#include "HelpButton.h"

HelpButton::HelpButton(){
}

HelpButton::~HelpButton(){
}

HelpButton * HelpButton::createHelp(const char * pName)
{
	HelpButton * help = new HelpButton();
	if(help && help->initWithFile(pName) )
	{
		help->autorelease();
		return help;
	}
	CC_SAFE_DELETE(help);
	return NULL;
}
void HelpButton::onEnter()  
{  
	CCDirector* pDirector = CCDirector::sharedDirector();  
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);  
	CCSprite::onEnter();  
}  
  
void HelpButton::onExit()  
{  
	CCDirector* pDirector = CCDirector::sharedDirector();  
	pDirector->getTouchDispatcher()->removeDelegate(this);  
	CCSprite::onExit();  
}  


bool HelpButton::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCPoint sLocalPos = convertToNodeSpace(touch->getLocation());  
	CCRect sRC = CCRect(getPositionX() - getContentSize().width * getAnchorPoint().x,  
						   getPositionY() - getContentSize().height * getAnchorPoint().y,  
						   getContentSize().width, getContentSize().height);  
	  
	  
	sRC.origin = CCPointZero;  
	bool isTouched = sRC.containsPoint(sLocalPos);  
	if(isTouched){
		if(state != Constant::STATIC){
		removeChild(labelWelcome,true);
		removeChild(labelWelcome1,true);
		removeChild(labelWelcome2,true);
		removeChild(labelWelcome3,true);
		removeChild(labelWelcome4,true);
		int p_cl = 0;
		int d_cl = 0;
		int p_cr = 0;
		int d_cr = 0;
		for(int i = 0; i < boat->vb[0]->l.size(); i++){
			if(boat->vb[0]->l[i].type == Constant::PERSON_PRIEST)
				p_cl++;
			if(boat->vb[0]->l[i].type == Constant::PERSON_DEVIL)
				d_cl++;
		}
		for(int i = 0; i < boat->vb[1]->l.size(); i++){
			if(boat->vb[1]->l[i].type == Constant::PERSON_PRIEST)
				p_cr++;
			if(boat->vb[1]->l[i].type == Constant::PERSON_DEVIL)
				d_cr++;
		}
		std::string s;
		int num1 = 0;
		int num2 = 0;
		for(int i = 0; i < boat->record.size(); i++){
			if(boat->record[i]->boatState == 10)
				num1++;
		}
		for(int i = 0; i < boat->record.size(); i++){
			if(boat->record[i]->boatState == Constant::STATE_ONBOAT)
				num2++;
		}
		if(num1 != 0){
			s = "Please click the boat to move to another side.";		
		}
		else if(num2 != 0){
			s = "Please click the boat to let the person move to the bank!";
		}
		else{
		if(p_cl == 3 && d_cl == 3 && p_cr == 0 && d_cr == 0 && boat->state == Constant::STATE_LEFT){			
			s = "Please move two devils to the right side or move one devil and one priest to the right side.";
		}
		else if(p_cl == 3 && d_cl == 1 && p_cr == 0 && d_cr == 2 && boat->state == Constant::STATE_RIGHT){
			s = "Please move one devil to the left side.";
		}
		else if(p_cl == 2 && d_cl == 2 && p_cr == 1 && d_cr == 1 && boat->state == Constant::STATE_RIGHT){
			s = "Please move one priest to the left side.";
		}
		else if(p_cl == 3 && d_cl == 2 && p_cr == 0 && d_cr == 1 && boat->state == Constant::STATE_LEFT){
			s = "Please move two devils to the right side.";
		}
		else if(p_cl == 3 && d_cl == 0 && p_cr == 0 && d_cr == 3 && boat->state == Constant::STATE_RIGHT){
			s = "Please move one devil to the left side";
		}
		else if(p_cl == 3 && d_cl == 1 && p_cr == 0 && d_cr == 2 && boat->state == Constant::STATE_LEFT){
			s = "Please move two priests to the right side.";
		}
		else if(p_cl == 1 && d_cl == 1 && p_cr == 2 && d_cr == 2 && boat->state == Constant::STATE_RIGHT){
			s = "Please move one devil and one priest to the left side.";
		}
		else if(p_cl == 2 && d_cl == 2 && p_cr == 1 && d_cr == 1 && boat->state == Constant::STATE_LEFT){
			s = "Please move two priests to the right side.";
		}
		else if(p_cl == 0 && d_cl == 2 && p_cr == 3 && d_cr == 1 && boat->state == Constant::STATE_RIGHT){
			s = "Please move one devil to the left side.";
		}
		else if(p_cl == 0 && d_cl == 3 && p_cr == 3 && d_cr == 0 && boat->state == Constant::STATE_LEFT){
			s = "Please move two devils to the right side.";
		}
		else if(p_cl == 0 && d_cl == 1 && p_cr == 3 && d_cr == 2 && boat->state == Constant::STATE_RIGHT){
			s = "Please move one priest to the left side or move one devil to the left side.";
		}
		else if(p_cl == 1 && d_cl == 1 && p_cr == 2 && d_cr == 2 && boat->state == Constant::STATE_LEFT){
			s = "Please move one priest and one devil to the right side.";
		}
		else if(p_cl == 0 && d_cl == 2 && p_cr == 3 && d_cr == 1 && boat->state == Constant::STATE_LEFT){
			s = "Please move two devils to the right side.";
		}
		else if((p_cl < d_cl && p_cl > 0) || (p_cr < d_cr && p_cr > 0)){
			s = "You have to restart the game!";
		}
		else{
			s = "You have no choice but to go back the last step.";
		}
		}
		labelWelcome=CCLabelTTF::create(s.c_str(),"Bitstream Vera Sans Mono",13);
		ccColor3B color = ccc3(255, 0, 0);
		labelWelcome->setColor(color);
		CCSize size=CCDirector::sharedDirector()->getWinSize();  
		float width=size.width;  
		float height=size.height;  
		CCSize ss=labelWelcome->getContentSize(); 
		labelWelcome->setPosition(CCPoint(ss.width/2,ss.height/2-60));
		addChild(labelWelcome,1); 
		

		labelWelcome1=CCLabelTTF::create(s.c_str(),"Bitstream Vera Sans Mono",13); 
	CCSize size1=CCDirector::sharedDirector()->getWinSize();  
	ccColor3B color1 = ccc3(255, 0, 0);
	labelWelcome1->setColor(color1);
	float width1=size.width;  
	float height1=size.height;  
	CCSize s1=labelWelcome1->getContentSize(); 
	labelWelcome1->setPosition(CCPoint(ss.width/2,ss.height/2-60));
	this->addChild(labelWelcome1, 1);

	labelWelcome2=CCLabelTTF::create(s.c_str(),"Bitstream Vera Sans Mono",13); 
	CCSize size2=CCDirector::sharedDirector()->getWinSize();  
	ccColor3B color2 = ccc3(255, 0, 0);
	labelWelcome2->setColor(color2);
	float width2=size.width;  
	float height2=size.height;  
	CCSize s2=labelWelcome2->getContentSize(); 
	labelWelcome2->setPosition(CCPoint(ss.width/2,ss.height/2-60));

	this->addChild(labelWelcome2, 1);

	labelWelcome3=CCLabelTTF::create(s.c_str(),"Bitstream Vera Sans Mono",13); 
	CCSize size3=CCDirector::sharedDirector()->getWinSize();  
	ccColor3B color3 = ccc3(255, 0, 0);
	labelWelcome3->setColor(color3);
	float width3=size.width;  
	float height3=size.height;  
	CCSize s3=labelWelcome3->getContentSize(); 
	labelWelcome3->setPosition(CCPoint(ss.width/2,ss.height/2-60));

	this->addChild(labelWelcome3, 1);

	labelWelcome4=CCLabelTTF::create(s.c_str(),"Bitstream Vera Sans Mono",13); 
	CCSize size4=CCDirector::sharedDirector()->getWinSize();  
	ccColor3B color4 = ccc3(255, 0, 0);
	labelWelcome4->setColor(color4);
	float width4=size.width;  
	float height4=size.height;  
	CCSize s4=labelWelcome4->getContentSize(); 
	labelWelcome4->setPosition(CCPoint(ss.width/2,ss.height/2-60));

	this->addChild(labelWelcome4, 1);

	}
	}
	else{}
	return true;
}

void HelpButton::ccTouchMoved(CCTouch* touch, CCEvent* event) {}
void HelpButton::ccTouchEnded(CCTouch* touch, CCEvent* event) {}

/*
int p_cl = 0;
		int d_cl = 0;
		int p_cr = 0;
		int d_cr = 0;
		for(int i = 0; i < boat->vb[0]->l.size(); i++){
			if(boat->vb[0]->l[i].type == Constant::PERSON_PRIEST)
				p_cl++;
			if(boat->vb[0]->l[i].type == Constant::PERSON_DEVIL)
				d_cl++;
		}
		for(int i = 0; i < boat->vb[1]->l.size(); i++){
			if(boat->vb[1]->l[i].type == Constant::PERSON_PRIEST)
				p_cr++;
			if(boat->vb[1]->l[i].type == Constant::PERSON_DEVIL)
				d_cr++;
		}
		std::string s = help(p_cl, d_cl, p_cr, d_cr, boat->state);
		const char* c_s = s.c_str();
		CCLabelTTF * labelWelcome=CCLabelTTF::create("nihao","Bitstream Vera Sans Mono",48); 
		CCSize size=CCDirector::sharedDirector()->getWinSize();  
		
		labelWelcome->setPosition(ccp(40, 100));
		addChild(labelWelcome,1); 
*/