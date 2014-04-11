#include "MainScene.h"
#include "Actor/Boat.h"
#include "Actor/Bank.h"
#include "Actor/Devils.h"
#include "Actor/Priests.h"
#include "Begin.h"
#include "HelpButton.h"
#include "Restart.h"
#include <sstream>
#include <vector>

USING_NS_CC;

CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}





	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HelloWorld::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label





	Begin * background = Begin::createBegin("background.png");
	background->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	float winw = visibleSize.width; //获取屏幕宽度
	float winh = visibleSize.height;//获取屏幕高度

	float spx = background->getTextureRect().getMaxX();
	float spy = background->getTextureRect().getMaxY();

	background->setScaleX(winw/spx); //设置精灵宽度缩放比例
	background->setScaleY(winh/spy);
	this->addChild(background, 0);



	RestartButton * restart = RestartButton::createHelp("start_60_40.png");
	restart->setAnchorPoint(ccp(0.5f, 0.5f));
	restart->setPosition(ccp(visibleSize.width - restart->getTextureRect().size.width / 2 - 30,
		visibleSize.height - restart->getTextureRect().size.height / 2 - 20));
	this->addChild(restart, 0);

	CCLabelTTF * labelWelcome=CCLabelTTF::create("Please click 'START' to start or restart!","Bitstream Vera Sans Mono",15); 
	CCLabelTTF * labelWelcomes=CCLabelTTF::create("Left is Priests, Right is Devils","Bitstream Vera Sans Mono",15); 
	ccColor3B color = ccc3(255, 0, 0);
	labelWelcome->setColor(color);
	labelWelcomes->setColor(color);
	labelWelcome->setPosition(ccp(visibleSize.width / 2, restart->getPositionY()));
	labelWelcomes->setPosition(ccp(visibleSize.width / 2, restart->getPositionY() - 20));
	this->addChild(labelWelcome, 0);
	this->addChild(labelWelcomes, 0);

	CCLabelTTF * labelWelcome1=CCLabelTTF::create("Please click 'START' to start or restart!","Bitstream Vera Sans Mono",15); 
	CCLabelTTF * labelWelcomes1=CCLabelTTF::create("Left is Priests, Right is Devils","Bitstream Vera Sans Mono",15); 
	labelWelcome1->setColor(color);
	labelWelcomes1->setColor(color);
	labelWelcome1->setPosition(ccp(visibleSize.width / 2, restart->getPositionY()));
	labelWelcomes1->setPosition(ccp(visibleSize.width / 2, restart->getPositionY() - 20));
	this->addChild(labelWelcome1, 0);
	this->addChild(labelWelcomes1, 0);

	CCLabelTTF * labelWelcome2=CCLabelTTF::create("Please click 'START' to start or restart!","Bitstream Vera Sans Mono",15); 
	labelWelcome2->setColor(color);
	labelWelcome2->setPosition(ccp(visibleSize.width / 2, restart->getPositionY()));
	this->addChild(labelWelcome2, 0);
	CCLabelTTF * labelWelcomes2=CCLabelTTF::create("Left is Priests, Right is Devils","Bitstream Vera Sans Mono",15); 
	labelWelcomes2->setColor(color);
	labelWelcomes2->setPosition(ccp(visibleSize.width / 2, restart->getPositionY() - 20));
	this->addChild(labelWelcomes2, 0);

	CCLabelTTF * labelWelcome3=CCLabelTTF::create("Please click 'START' to start or restart!","Bitstream Vera Sans Mono",15); 
	labelWelcome3->setColor(color);
	labelWelcome3->setPosition(ccp(visibleSize.width / 2, restart->getPositionY()));
	this->addChild(labelWelcome3, 0);
	CCLabelTTF * labelWelcomes3=CCLabelTTF::create("Left is Priests, Right is Devils","Bitstream Vera Sans Mono",15); 
	labelWelcomes3->setColor(color);
	labelWelcomes3->setPosition(ccp(visibleSize.width / 2, restart->getPositionY() - 20));
	this->addChild(labelWelcomes3, 0);

	CCLabelTTF * labelWelcome4=CCLabelTTF::create("Please click 'START' to start or restart!","Bitstream Vera Sans Mono",15); 
	labelWelcome4->setColor(color);
	labelWelcome4->setPosition(ccp(visibleSize.width / 2, restart->getPositionY()));
	this->addChild(labelWelcome4, 0);
	CCLabelTTF * labelWelcomes4=CCLabelTTF::create("Left is Priests, Right is Devils","Bitstream Vera Sans Mono",15); 
	labelWelcomes4->setColor(color);
	labelWelcomes4->setPosition(ccp(visibleSize.width / 2, restart->getPositionY() - 20));
	this->addChild(labelWelcomes4, 0);

	restart->help = HelpButton::createHelp("help_60_40.png");
	restart->help->setAnchorPoint(ccp(0.5f, 0.5f));
	restart->help->setPosition(ccp(restart->help->getTextureRect().size.width, restart->getPositionY()));
	restart->help->state = Constant::STATIC;
	this->addChild(restart->help, 0);

	restart->help->boat = Boat::createBoat("Standart_Boat.png");
	restart->help->boat->setPosition(ccp(250,100));
	restart->help->boat->state = Constant::STATIC;
	this->addChild(restart->help->boat, 0);

	Bank * clock = Bank::createBank("touming.png");
	clock->setPosition(ccp(restart->getPositionX() - clock->getTextureRect().size.width - 30, restart->getPositionY()));
	this->addChild(clock, 0);

	restart->help->boat->pr = CCProgressTimer::create(CCSprite::create("untouming.png"));
	restart->help->boat->pr->setPosition(ccp(restart->getPositionX() - clock->getTextureRect().size.width - 30, restart->getPositionY()));
	restart->help->boat->pr->setType(kCCProgressTimerTypeRadial);
	this->addChild(restart->help->boat->pr, 1);

	Priests * priest = Priests::createPriests("Standard_priests.png");
	priest->setPosition(ccp(20, 125));
	this->addChild(priest, 0);

	restart->help->boat->record.push_back(priest);
	restart->help->boat->record[0]->lock = 0;
	restart->help->boat->record[0]->boatState = Constant::STATIC;
	priest->setPositions(0);		

	Devils * devils = Devils::createDevils("Standard_Devil.png");
	devils->setPosition(ccp(100, 125));
	this->addChild(devils, 0);

	restart->help->boat->record.push_back(devils);
	restart->help->boat->record[1]->lock = 0;
	restart->help->boat->record[1]->boatState = Constant::STATIC;
	devils->setPositions(1);

	Priests * priest2 = Priests::createPriests("Standard_priests.png");
	priest2->setPosition(ccp(20, 185));
	this->addChild(priest2, 0);
	restart->help->boat->record.push_back(priest2);
	restart->help->boat->record[2]->lock = 0;
	restart->help->boat->record[2]->boatState = Constant::STATIC;
	priest2->setPositions(2);

	Devils * devils2 = Devils::createDevils("Standard_Devil.png");
	devils2->setPosition(ccp(100, 185));
	this->addChild(devils2, 0);

	restart->help->boat->record.push_back(devils2);
	restart->help->boat->record[3]->lock = 0;
	restart->help->boat->record[3]->boatState = Constant::STATIC;
	devils2->setPositions(3);

	Priests * priest3 = Priests::createPriests("Standard_priests.png");
	priest3->setPosition(ccp(20, 245));
	this->addChild(priest3, 0);
	restart->help->boat->record.push_back(priest3);
	restart->help->boat->record[4]->lock = 0;
	restart->help->boat->record[4]->boatState = Constant::STATIC;
	priest3->setPositions(4);

	Devils * devils3 = Devils::createDevils("Standard_Devil.png");
	devils3->setPosition(ccp(100, 245));
	this->addChild(devils3, 0);

	restart->help->boat->record.push_back(devils3);
	restart->help->boat->record[5]->lock = 0;
	restart->help->boat->record[5]->boatState = Constant::STATIC;
	devils3->setPositions(5);

	Bank * leftBank = Bank::createBank("Bank.png");
	leftBank->setPosition(ccp(80, 20));
	this->addChild(leftBank, 0);

	location loc00(Constant::PERSON_PRIEST, 1);
	location loc01(Constant::PERSON_DEVIL, 1);
	location loc02(Constant::PERSON_PRIEST, 1);
	location loc03(Constant::PERSON_DEVIL, 1);
	location loc04(Constant::PERSON_PRIEST, 1);
	location loc05(Constant::PERSON_DEVIL, 1);
	leftBank->l.push_back(loc00);
	leftBank->l.push_back(loc01);
	leftBank->l.push_back(loc02);
	leftBank->l.push_back(loc03);
	leftBank->l.push_back(loc04);
	leftBank->l.push_back(loc05);
	restart->help->boat->vb.push_back(leftBank);

	Bank * rightBank = Bank::createBank("Bank.png");
	rightBank->setPosition(ccp(380, 20));
	this->addChild(rightBank, 0);

	location loc10(-1, 0);
	location loc11(-1, 0);
	location loc12(-1, 0);
	location loc13(-1, 0);
	location loc14(-1, 0);
	location loc15(-1, 0);
	rightBank->l.push_back(loc10);
	rightBank->l.push_back(loc11);
	rightBank->l.push_back(loc12);
	rightBank->l.push_back(loc13);
	rightBank->l.push_back(loc14);
	rightBank->l.push_back(loc15);
	restart->help->boat->vb.push_back(rightBank);

	restart->help->boat->record[0]->record.push_back(restart->help->boat->record[1]);
	restart->help->boat->record[0]->record.push_back(restart->help->boat->record[2]);
	restart->help->boat->record[0]->record.push_back(restart->help->boat->record[3]);
	restart->help->boat->record[0]->record.push_back(restart->help->boat->record[4]);
	restart->help->boat->record[0]->record.push_back(restart->help->boat->record[5]);

	restart->help->boat->record[1]->record.push_back(restart->help->boat->record[0]);
	restart->help->boat->record[1]->record.push_back(restart->help->boat->record[2]);
	restart->help->boat->record[1]->record.push_back(restart->help->boat->record[3]);
	restart->help->boat->record[1]->record.push_back(restart->help->boat->record[4]);
	restart->help->boat->record[1]->record.push_back(restart->help->boat->record[5]);

	restart->help->boat->record[2]->record.push_back(restart->help->boat->record[0]);
	restart->help->boat->record[2]->record.push_back(restart->help->boat->record[1]);
	restart->help->boat->record[2]->record.push_back(restart->help->boat->record[3]);
	restart->help->boat->record[2]->record.push_back(restart->help->boat->record[4]);
	restart->help->boat->record[2]->record.push_back(restart->help->boat->record[5]);

	restart->help->boat->record[3]->record.push_back(restart->help->boat->record[0]);
	restart->help->boat->record[3]->record.push_back(restart->help->boat->record[1]);
	restart->help->boat->record[3]->record.push_back(restart->help->boat->record[2]);
	restart->help->boat->record[3]->record.push_back(restart->help->boat->record[4]);
	restart->help->boat->record[3]->record.push_back(restart->help->boat->record[5]);

	restart->help->boat->record[4]->record.push_back(restart->help->boat->record[0]);
	restart->help->boat->record[4]->record.push_back(restart->help->boat->record[1]);
	restart->help->boat->record[4]->record.push_back(restart->help->boat->record[2]);
	restart->help->boat->record[4]->record.push_back(restart->help->boat->record[3]);
	restart->help->boat->record[4]->record.push_back(restart->help->boat->record[5]);

	restart->help->boat->record[5]->record.push_back(restart->help->boat->record[0]);
	restart->help->boat->record[5]->record.push_back(restart->help->boat->record[1]);
	restart->help->boat->record[5]->record.push_back(restart->help->boat->record[2]);
	restart->help->boat->record[5]->record.push_back(restart->help->boat->record[3]);
	restart->help->boat->record[5]->record.push_back(restart->help->boat->record[4]);

	return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}
