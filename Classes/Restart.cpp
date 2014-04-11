#include "Restart.h"

RestartButton::RestartButton(){
}

RestartButton::~RestartButton(){
}

RestartButton * RestartButton::createHelp(const char * pName)
{
	RestartButton * restart = new RestartButton();
	if(restart && restart->initWithFile(pName) )
	{
		restart->autorelease();
		return restart;
	}
	CC_SAFE_DELETE(restart);
	return NULL;
}
void RestartButton::onEnter()  
{  
	CCDirector* pDirector = CCDirector::sharedDirector();  
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);  
	CCSprite::onEnter();  
}  

void RestartButton::onExit()  
{  
	CCDirector* pDirector = CCDirector::sharedDirector();  
	pDirector->getTouchDispatcher()->removeDelegate(this);  
	CCSprite::onExit();  
}  


bool RestartButton::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCPoint sLocalPos = convertToNodeSpace(touch->getLocation());  
	CCRect sRC = CCRect(getPositionX() - getContentSize().width * getAnchorPoint().x,  
		getPositionY() - getContentSize().height * getAnchorPoint().y,  
		getContentSize().width, getContentSize().height);  


	sRC.origin = CCPointZero;  
	bool isTouched = sRC.containsPoint(sLocalPos);  
	if(isTouched){		
		removeChild(labelWelcome,true);
		removeChild(labelWelcome1,true);
		removeChild(labelWelcome2,true);
		removeChild(labelWelcome3,true);
		removeChild(labelWelcome4,true);
		removeChild(labelWelcome5,true);
		removeChild(labelWelcome6,true);
		removeChild(labelWelcome7,true);
		removeChild(labelWelcome8,true);
		removeChild(labelWelcome9,true);
		//   设置进度条的样式
		help->boat->pr->setType(kCCProgressTimerTypeRadial);
		//   设置进度条的值的范围【0 100】
		help->boat->pr->setPercentage(0);
		//   设置动作
		CCProgressTo * to1= CCProgressTo::create(1800, 99.9);

		help->boat->pr->runAction(CCRepeatForever::create(to1));	

		if(help->boat->record[0]->boatState == Constant::STATE_OFFBOAT
			&& help->boat->record[1]->boatState == Constant::STATE_OFFBOAT
			&& help->boat->record[2]->boatState == Constant::STATE_OFFBOAT
			&& help->boat->record[3]->boatState == Constant::STATE_OFFBOAT
			&& help->boat->record[4]->boatState == Constant::STATE_OFFBOAT
			&& help->boat->record[5]->boatState == Constant::STATE_OFFBOAT
			&& help->boat->record[0]->posState == Constant::STATE_LEFT
			&& help->boat->record[1]->posState == Constant::STATE_LEFT
			&& help->boat->record[2]->posState == Constant::STATE_LEFT
			&& help->boat->record[3]->posState == Constant::STATE_LEFT
			&& help->boat->record[4]->posState == Constant::STATE_LEFT
			&& help->boat->record[5]->posState == Constant::STATE_LEFT)
		{}
		else{
			CCMoveTo * action = CCMoveTo::create(1.0f, ccp(20, 125));
			help->boat->record[0]->runAction(action);
			help->boat->record[0]->boatState = Constant::STATE_OFFBOAT;
			help->boat->record[0]->posState = Constant::STATE_LEFT;
			help->boat->record[0]->lock = 0;
			CCMoveTo * action2 = CCMoveTo::create(1.0f, ccp(100, 125));
			help->boat->record[1]->runAction(action2);
			help->boat->record[1]->boatState = Constant::STATE_OFFBOAT;
			help->boat->record[1]->posState = Constant::STATE_LEFT;
			help->boat->record[1]->lock = 0;
			CCMoveTo * action3 = CCMoveTo::create(1.0f, ccp(20, 185));
			help->boat->record[2]->runAction(action3);
			help->boat->record[2]->boatState = Constant::STATE_OFFBOAT;
			help->boat->record[2]->posState = Constant::STATE_LEFT;
			help->boat->record[2]->lock = 0;
			CCMoveTo * action4 = CCMoveTo::create(1.0f, ccp(100, 185));
			help->boat->record[3]->runAction(action4);
			help->boat->record[3]->boatState = Constant::STATE_OFFBOAT;
			help->boat->record[3]->posState = Constant::STATE_LEFT;
			help->boat->record[3]->lock = 0;
			CCMoveTo * action5 = CCMoveTo::create(1.0f, ccp(20, 245));
			help->boat->record[4]->runAction(action5);
			help->boat->record[4]->boatState = Constant::STATE_OFFBOAT;
			help->boat->record[4]->posState = Constant::STATE_LEFT;
			help->boat->record[4]->lock = 0;
			CCMoveTo * action6 = CCMoveTo::create(1.0f, ccp(100, 245));
			help->boat->record[5]->runAction(action6);
			help->boat->record[5]->boatState = Constant::STATE_OFFBOAT;
			help->boat->record[5]->posState = Constant::STATE_LEFT;
			help->boat->record[5]->lock = 0;

			help->boat->vb[0]->removeChild(help->boat->labelWelcome, true);

			CCMoveTo * action7 = CCMoveTo::create(1.0f, ccp(250,100));
			help->boat->runAction(action7);	
			help->boat->state = Constant::STATE_LEFT;
		}

		help->boat->vb[0]->l[0].isempty = 1;
		help->boat->vb[0]->l[0].type = Constant::PERSON_PRIEST;

		help->boat->vb[0]->l[1].isempty = 1;
		help->boat->vb[0]->l[1].type = Constant::PERSON_DEVIL;

		help->boat->vb[0]->l[2].isempty = 1;
		help->boat->vb[0]->l[2].type = Constant::PERSON_PRIEST;

		help->boat->vb[0]->l[3].isempty = 1;
		help->boat->vb[0]->l[3].type = Constant::PERSON_DEVIL;

		help->boat->vb[0]->l[4].isempty = 1;
		help->boat->vb[0]->l[4].type = Constant::PERSON_PRIEST;

		help->boat->vb[0]->l[5].isempty = 1;
		help->boat->vb[0]->l[5].type = Constant::PERSON_DEVIL;

		help->boat->vb[1]->l[0].isempty = 0;
		help->boat->vb[1]->l[0].type = -1;

		help->boat->vb[1]->l[1].isempty = 0;
		help->boat->vb[1]->l[1].type = -1;

		help->boat->vb[1]->l[2].isempty = 0;
		help->boat->vb[1]->l[2].type = -1;

		help->boat->vb[1]->l[3].isempty = 0;
		help->boat->vb[1]->l[3].type = -1;

		help->boat->vb[1]->l[4].isempty = 0;
		help->boat->vb[1]->l[4].type = -1;

		help->boat->vb[1]->l[5].isempty = 0;
		help->boat->vb[1]->l[5].type = -1;




		help->state = 1;
		help->removeChild(help->labelWelcome, true);
		help->removeChild(help->labelWelcome1, true);
		help->removeChild(help->labelWelcome2, true);
		help->removeChild(help->labelWelcome3, true);
		help->removeChild(help->labelWelcome4, true);

		labelWelcome=CCLabelTTF::create("You can start now!!","Bitstream Vera Sans Mono",13);
		ccColor3B color = ccc3(255, 0, 0);
		labelWelcome->setColor(color);
		CCSize size=CCDirector::sharedDirector()->getWinSize();  
		float width=size.width;  
		float height=size.height;  
		CCSize ss=labelWelcome->getContentSize(); 
		labelWelcome->setPosition(CCPoint(ss.width/2-80,ss.height/2-40));
		addChild(labelWelcome,1); 


		labelWelcome1=CCLabelTTF::create("You can start now!!","Bitstream Vera Sans Mono",13); 
		CCSize size1=CCDirector::sharedDirector()->getWinSize();  
		ccColor3B color1 = ccc3(255, 0, 0);
		labelWelcome1->setColor(color1);
		float width1=size.width;  
		float height1=size.height;  
		CCSize s1=labelWelcome1->getContentSize(); 
		labelWelcome1->setPosition(CCPoint(ss.width/2-80,ss.height/2-40));
		this->addChild(labelWelcome1, 1);

		labelWelcome2=CCLabelTTF::create("You can start now!!","Bitstream Vera Sans Mono",13); 
		CCSize size2=CCDirector::sharedDirector()->getWinSize();  
		ccColor3B color2 = ccc3(255, 0, 0);
		labelWelcome2->setColor(color2);
		float width2=size.width;  
		float height2=size.height;  
		CCSize s2=labelWelcome2->getContentSize(); 
		labelWelcome2->setPosition(CCPoint(ss.width/2-80,ss.height/2-40));

		this->addChild(labelWelcome2, 1);

		labelWelcome3=CCLabelTTF::create("You can start now!!","Bitstream Vera Sans Mono",13); 
		CCSize size3=CCDirector::sharedDirector()->getWinSize();  
		ccColor3B color3 = ccc3(255, 0, 0);
		labelWelcome3->setColor(color3);
		float width3=size.width;  
		float height3=size.height;  
		CCSize s3=labelWelcome3->getContentSize(); 
		labelWelcome3->setPosition(CCPoint(ss.width/2-80,ss.height/2-40));

		this->addChild(labelWelcome3, 1);

		labelWelcome4=CCLabelTTF::create("You can start now!!","Bitstream Vera Sans Mono",13); 
		CCSize size4=CCDirector::sharedDirector()->getWinSize();  
		ccColor3B color4 = ccc3(255, 0, 0);
		labelWelcome4->setColor(color4);
		float width4=size.width;  
		float height4=size.height;  
		CCSize s4=labelWelcome4->getContentSize(); 
		labelWelcome4->setPosition(CCPoint(ss.width/2-80,ss.height/2-40));

		labelWelcome5=CCLabelTTF::create("Timer Start","Bitstream Vera Sans Mono",13);
		labelWelcome5->setColor(color);
		CCSize size5=CCDirector::sharedDirector()->getWinSize();  
		float width5=size5.width;  
		float height5=size5.height;  
		CCSize ss5=labelWelcome5->getContentSize(); 
		labelWelcome5->setPosition(CCPoint(ss5.width/2-80,ss5.height/2-20));
		addChild(labelWelcome5,1); 


		labelWelcome6=CCLabelTTF::create("Timer Start","Bitstream Vera Sans Mono",13);
		labelWelcome6->setColor(color);
		CCSize size6=CCDirector::sharedDirector()->getWinSize();  
		float width6=size6.width;  
		float height6=size6.height;  
		CCSize ss6=labelWelcome6->getContentSize(); 
		labelWelcome6->setPosition(CCPoint(ss6.width/2-80,ss6.height/2-20));
		addChild(labelWelcome6,1); 

		labelWelcome7=CCLabelTTF::create("Timer Start","Bitstream Vera Sans Mono",13);
		labelWelcome7->setColor(color);
		CCSize size7=CCDirector::sharedDirector()->getWinSize();  
		float width7=size7.width;  
		float height7=size7.height;  
		CCSize ss7=labelWelcome7->getContentSize(); 
		labelWelcome7->setPosition(CCPoint(ss7.width/2-80,ss7.height/2-20));
		addChild(labelWelcome7,1);

		labelWelcome8=CCLabelTTF::create("Timer Start","Bitstream Vera Sans Mono",13);
		labelWelcome8->setColor(color);
		CCSize size8=CCDirector::sharedDirector()->getWinSize();  
		float width8=size8.width;  
		float height8=size8.height;  
		CCSize ss8=labelWelcome8->getContentSize(); 
		labelWelcome8->setPosition(CCPoint(ss8.width/2-80,ss8.height/2-20));
		addChild(labelWelcome8,1); 

		labelWelcome9=CCLabelTTF::create("Timer Start","Bitstream Vera Sans Mono",13);
		labelWelcome9->setColor(color);
		CCSize size9=CCDirector::sharedDirector()->getWinSize();  
		float width9=size9.width;  
		float height9=size9.height;  
		CCSize ss9=labelWelcome9->getContentSize(); 
		labelWelcome9->setPosition(CCPoint(ss9.width/2-80,ss9.height/2-20));
		addChild(labelWelcome9,1); 

	}
	return true;
}

void RestartButton::ccTouchMoved(CCTouch* touch, CCEvent* event) {}
void RestartButton::ccTouchEnded(CCTouch* touch, CCEvent* event) {}

