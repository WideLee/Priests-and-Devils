#include "Boat.h"
#include <string>
Boat::Boat()
{
	count = 0;
	state = Constant::STATE_LEFT;
	left = NULL;
	right = NULL;
}
Boat::~Boat()
{
}

Boat* Boat::createBoat(const char* pName)
{
	Boat * boat = new Boat();
	if(boat && boat->initWithFile(pName) )
	{
		boat->autorelease();
		return boat;
	}
	CC_SAFE_DELETE(boat);
	return NULL;
}

void Boat::onEnter()  
{  
	CCDirector* pDirector = CCDirector::sharedDirector();  
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);  
	CCSprite::onEnter();  
}  
  
void Boat::onExit()  
{  
	CCDirector* pDirector = CCDirector::sharedDirector();  
	pDirector->getTouchDispatcher()->removeDelegate(this);  
	CCSprite::onExit();  
}  

bool Boat::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCPoint sLocalPos = convertToNodeSpace(touch->getLocation());  
	CCRect sRC = CCRect(getPositionX() - getContentSize().width * getAnchorPoint().x,  
						   getPositionY() - getContentSize().height * getAnchorPoint().y,  
						   getContentSize().width, getContentSize().height);  
	  
	  
	sRC.origin = CCPointZero;  
	bool isTouched = sRC.containsPoint(sLocalPos);  
	if(isTouched){		
		int num = 0;
		for(int i = 0; i < record.size(); i++)
			if(record[i]->boatState == Constant::STATE_OFFBOAT)
				num++;
		if(num != 6){
		if(state == Constant::STATE_LEFT)
		{
			std::vector<Person *>::iterator it;
			int count = 0;
			for(it = record.begin(); it != record.end(); it++){
				if((*it)->boatState == Constant::STATE_ONBOAT){
				count++;
				}
			}
			if(count > 0){// leave boat correctly
				std::vector<Person *>::iterator it;
				for(it = record.begin(); it != record.end(); it++){
					if((*it)->boatState == Constant::STATE_ONBOAT){
						int flag = (*it)->getPositions();
						vb[0]->l[(*it)->getPositions()].isempty = 1;
						vb[0]->l[(*it)->getPositions()].type = (*it)->type;
						int locx = 0;
						int locy = 0;
						switch(flag){
							case 0:
								locx = 0;
								locy = 0;
								break;
							case 1:
								locx = 80;
								locy = 0;
								break;
							case 2:
								locx = 0;
								locy = 60;
								break;
							case 3:
								locx = 80;
								locy = 60;
								break;
							case 4:
								locx = 0;
								locy = 120;
								break;
							case 5:
								locx = 80;
								locy = 120;
								break;
						}	
						
						(*it)->boatState =  Constant::STATE_OFFBOAT;
						(*it)->leaveBoat(locx, locy);
				}
				}
				std::vector<Person *>::iterator p;
				for(p = record.begin(); p != record.end(); p++){
					if((*p)->posState == this->state)
						(*p)->lock = 0;
					else 
						(*p)->lock = 1;
				}
				int pl_num = 0;
				int dl_num = 0;
				for(int i = 0; i < vb[0]->l.size(); i++){
					if(vb[0]->l[i].type == Constant::PERSON_PRIEST && vb[0]->l[i].isempty == 1)
						pl_num++;
					if(vb[0]->l[i].type == Constant::PERSON_DEVIL && vb[0]->l[i].isempty == 1)
						dl_num++;
				}
				if((dl_num > pl_num) && (dl_num > 0) && (pl_num > 0)){
				labelWelcome=CCLabelTTF::create("Game Over","Bitstream Vera Sans Mono",48); 
				CCSize size=CCDirector::sharedDirector()->getWinSize();  
				float width=size.width;  
				float height=size.height;  
				CCSize s=labelWelcome->getContentSize(); 
				labelWelcome->setPosition(CCPoint(s.width/2+160,s.height/2+160));
				this->vb[0]->addChild(labelWelcome,1); 
				this->record[0]->boatState = Constant::STATIC;
				this->record[1]->boatState = Constant::STATIC;
				this->record[2]->boatState = Constant::STATIC;
				this->record[3]->boatState = Constant::STATIC;
				this->record[4]->boatState = Constant::STATIC;
				this->record[5]->boatState = Constant::STATIC;
				this->state = Constant::STATIC;
				}

				int pr_num = 0;
				int dr_num = 0;
				for(int i = 0; i < vb[1]->l.size(); i++){
					if(vb[1]->l[i].type == Constant::PERSON_PRIEST && vb[1]->l[i].isempty == 1)
						pr_num++;
					if(vb[1]->l[i].type == Constant::PERSON_DEVIL && vb[1]->l[i].isempty == 1)
						dr_num++;
				}
				if((dr_num > pr_num) && (dr_num > 0) && (pr_num > 0)){
				labelWelcome=CCLabelTTF::create("Game Over","Bitstream Vera Sans Mono",48); 
				CCSize size=CCDirector::sharedDirector()->getWinSize();  
				float width=size.width;  
				float height=size.height;  
				CCSize s=labelWelcome->getContentSize(); 
				labelWelcome->setPosition(CCPoint(s.width/2+160,s.height/2+160));
				this->vb[0]->addChild(labelWelcome,1); 	
				this->record[0]->boatState = Constant::STATIC;
				this->record[1]->boatState = Constant::STATIC;
				this->record[2]->boatState = Constant::STATIC;
				this->record[3]->boatState = Constant::STATIC;
				this->record[4]->boatState = Constant::STATIC;
				this->record[5]->boatState = Constant::STATIC;
				this->state = Constant::STATIC;
				}

				int final = 0;
				for(int i = 0; i < vb[1]->l.size(); i++){
					if(vb[1]->l[i].isempty == 1)
						final++;
				}
				if(final == 6){
					labelWelcome=CCLabelTTF::create("You Win!","Bitstream Vera Sans Mono",48); 
					CCSize size=CCDirector::sharedDirector()->getWinSize();  
					float width=size.width;  
					float height=size.height;  
					CCSize s=labelWelcome->getContentSize(); 
					labelWelcome->setPosition(CCPoint(s.width/2+160,s.height/2+160));
					this->vb[0]->addChild(labelWelcome,1); 
				}
			}
			else{
				
			CCMoveTo * boatAction = CCMoveTo::create(1.0f, ccp(500, 100));
			this->runAction(boatAction);
			state = Constant::STATE_RIGHT;

			int count2 = 0;
			std::vector<Person *>::iterator it;
			for(it = record.begin(); it != record.end(); it++){
				if((*it)->boatState == 10){
					if((*it)->boatloc == Constant::ON_BOAT_LEFT){
						CCMoveTo * personAction = CCMoveTo::create(1.0f, ccp(450 + Constant::ON_BOAT_LEFT, 125));
						(*it)->runAction(personAction);
						(*it)->boatState = Constant::STATE_ONBOAT;
						(*it)->posState = Constant::STATE_RIGHT;
					}
					else if((*it)->boatloc == Constant::ON_BOAT_RIGHT){
						CCMoveTo * personAction = CCMoveTo::create(1.0f, ccp(450 + Constant::ON_BOAT_RIGHT, 125));
						(*it)->runAction(personAction);
						(*it)->boatState = Constant::STATE_ONBOAT;
						(*it)->posState = Constant::STATE_RIGHT;
					}
				}
			}
			}
			for(it = record.begin(); it != record.end(); it++){
				if((*it)->boatState == Constant::STATE_ONBOAT){
					int temp = (*it)->getPositions();
					vb[0]->l[temp].isempty = 0;
					vb[0]->l[temp].type = -1;
				}
			}


		} else if(state == Constant::STATE_RIGHT){
			std::vector<Person *>::iterator it;
			int count = 0;
			for(it = record.begin(); it != record.end(); it++){
				if((*it)->boatState == Constant::STATE_ONBOAT){
				count++;
				}
			}
			if(count > 0){

				std::vector<Person *>::iterator it;
				for(it = record.begin(); it != record.end(); it++){
					if((*it)->boatState == Constant::STATE_ONBOAT){
						int flag = (*it)->getPositions();
						vb[1]->l[(*it)->getPositions()].isempty = 1;
						vb[1]->l[(*it)->getPositions()].type = (*it)->type;
						
						int locx = 0;
						int locy = 0;
						switch(flag){
							case 0:
								locx = 0;
								locy = 0;
								break;
							case 1:
								locx = 80;
								locy = 0;
								break;
							case 2:
								locx = 0;
								locy = 60;
								break;
							case 3:
								locx = 80;
								locy = 60;
								break;
							case 4:
								locx = 0;
								locy = 120;
								break;
							case 5:
								locx = 80;
								locy = 120;
								break;
						}	
						(*it)->boatState =  Constant::STATE_OFFBOAT;
						(*it)->leaveBoat(locx, locy);
				}
				}
				std::vector<Person *>::iterator p;
				for(p = record.begin(); p != record.end(); p++){
					if((*p)->posState == this->state)
						(*p)->lock = 0;
					else 
						(*p)->lock = 1;
				}

				int pl_num = 0;
				int dl_num = 0;
				for(int i = 0; i < vb[0]->l.size(); i++){
					if(vb[0]->l[i].type == Constant::PERSON_PRIEST && vb[0]->l[i].isempty == 1)
						pl_num++;
					if(vb[0]->l[i].type == Constant::PERSON_DEVIL && vb[0]->l[i].isempty == 1)
						dl_num++;
				}
				if((dl_num > pl_num) && (dl_num > 0) && (pl_num > 0)){
				labelWelcome=CCLabelTTF::create("Game Over","Bitstream Vera Sans Mono",48); 
				CCSize size=CCDirector::sharedDirector()->getWinSize();  
				float width=size.width;  
				float height=size.height;  
				CCSize s=labelWelcome->getContentSize(); 
				labelWelcome->setPosition(CCPoint(s.width/2+160,s.height/2+160));
				this->vb[0]->addChild(labelWelcome,1); 
				this->record[0]->boatState = Constant::STATIC;
				this->record[1]->boatState = Constant::STATIC;
				this->record[2]->boatState = Constant::STATIC;
				this->record[3]->boatState = Constant::STATIC;
				this->record[4]->boatState = Constant::STATIC;
				this->record[5]->boatState = Constant::STATIC;
				this->state = Constant::STATIC;
				}

				int pr_num = 0;
				int dr_num = 0;
				for(int i = 0; i < vb[1]->l.size(); i++){
					if(vb[1]->l[i].type == Constant::PERSON_PRIEST && vb[1]->l[i].isempty == 1)
						pr_num++;
					if(vb[1]->l[i].type == Constant::PERSON_DEVIL && vb[1]->l[i].isempty == 1)
						dr_num++;
				}
				if((dr_num > pr_num) && (dr_num > 0) && (pr_num > 0)){
				labelWelcome=CCLabelTTF::create("Game Over","Bitstream Vera Sans Mono",48); 
				CCSize size=CCDirector::sharedDirector()->getWinSize();  
				float width=size.width;  
				float height=size.height;  
				CCSize s=labelWelcome->getContentSize(); 
				labelWelcome->setPosition(CCPoint(s.width/2+160,s.height/2+160));
				this->vb[0]->addChild(labelWelcome,1); 
				this->record[0]->boatState = Constant::STATIC;
				this->record[1]->boatState = Constant::STATIC;
				this->record[2]->boatState = Constant::STATIC;
				this->record[3]->boatState = Constant::STATIC;
				this->record[4]->boatState = Constant::STATIC;
				this->record[5]->boatState = Constant::STATIC;
				this->state = Constant::STATIC;
				}

				int final = 0;
				for(int i = 0; i < vb[1]->l.size(); i++){
					if(vb[1]->l[i].isempty == 1)
						final++;
				}
				if(final == 6){
					labelWelcome=CCLabelTTF::create("You Win!","Bitstream Vera Sans Mono",48); 
					CCSize size=CCDirector::sharedDirector()->getWinSize();  
					float width=size.width;  
					float height=size.height;  
					CCSize s=labelWelcome->getContentSize(); 
					labelWelcome->setPosition(CCPoint(s.width/2+160,s.height/2+160));
					this->vb[0]->addChild(labelWelcome,1); 
				}

			}
			else{
				
			CCMoveTo * action = CCMoveTo::create(1.0f, ccp(250, 100));
			this->runAction(action);
			state = Constant::STATE_LEFT;

			std::vector<Person *>::iterator it;
			int count2 = 0;
			for(it = record.begin(); it != record.end(); it++){
				if((*it)->boatState == 10){
					if((*it)->boatloc == Constant::ON_BOAT_LEFT){
						CCMoveTo * personAction = CCMoveTo::create(1.0f, ccp(200 + Constant::ON_BOAT_LEFT, 125));
						(*it)->runAction(personAction);
						(*it)->boatState = Constant::STATE_ONBOAT;
						(*it)->posState = Constant::STATE_LEFT;
					}
					else if((*it)->boatloc == Constant::ON_BOAT_RIGHT){
						CCMoveTo * personAction = CCMoveTo::create(1.0f, ccp(200 + Constant::ON_BOAT_RIGHT, 125));
						(*it)->runAction(personAction);
						(*it)->boatState = Constant::STATE_ONBOAT;
						(*it)->posState = Constant::STATE_LEFT;
					}
				}
			}
			for(it = record.begin(); it != record.end(); it++){
				if((*it)->boatState == Constant::STATE_ONBOAT){
					int temp = (*it)->getPositions();
					vb[1]->l[temp].isempty = 0;
					vb[1]->l[temp].type = -1;
				}
			}
		
		}
		}
		else if(state == Constant::STATIC){}
	}
	}
	else{}
	return true;
}

void Boat::ccTouchMoved(CCTouch* touch, CCEvent* event) {}
void Boat::ccTouchEnded(CCTouch* touch, CCEvent* event) {}

int Boat::getState()
{
	return state;
}

bool Boat::addPerson(Person * person)
{
	if(left == NULL)
	{
		left = person;
		return true;
	}
	else if(right == NULL)
	{
		right = person;
		return true;
	}
	else
	{
		return false;
	}
}

bool Boat::removePerson(Person * person)
{
	if(left == person)
	{
		left = NULL;
		return true;		
	}
	else if(right == person)
	{
		right = NULL;
		return true;
	}
	else
	{
		return false;
	}
}