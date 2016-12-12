#include "GameScene.h"
#include "MainMenuScene.h"
#include "PauseScene.h"
#include "EndScene.h"
#include "Definitions.h"

USING_NS_CC;


Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); // draw debug lines around objects in the world
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld()); // set the layers physics
	
    // add layer as a child to scene
    scene->addChild(layer);
		
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// adds background music for game screen
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("POL-floating-town-short.wav", true);
	    
    // add a label shows "Hello World"
    // create and initialize a label    
    auto label = Label::create("Game Scene", "Helvetica", 18);    
    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 10);
	
	// scrolling background sprites
	for (int i = 0; i < 2; i++)
	{	
		// create a new background sprite
		backgroundSpriteArray[i] = Sprite::create("background.png");

		// set the backgrounds position
		backgroundSpriteArray[i]->setPosition
	    (Point((visibleSize.width / 2) + origin.x, (-1 *
		visibleSize.height * i) + (visibleSize.height / 2) + origin.y));
		this->addChild(backgroundSpriteArray[i], -2);

	}

	
	// create an outline around the edge of the screen
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 1);

	// create a node
	auto edgeNode = Node::create();

	// set the poisition of the node
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x,
		visibleSize.height / 2 + origin.y));

	// give the edge node the outline of the physics body
	edgeNode->setPhysicsBody(edgeBody);

	// add the edge node that has the outline, to the layer
	this->addChild(edgeNode);

	// add foreground to game scene
	auto foreground = Sprite::create("foreground.png");
	foreground->setPosition(Vec2(visibleSize.width / 2 + origin.x, 50));
	
	// create physics body for floor
	auto floorEdgeBody = PhysicsBody::createEdgeBox(foreground->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, 1);

	// give the foreground a physics body
	foreground->setPhysicsBody(floorEdgeBody);
	foreground->getPhysicsBody()->setDynamic(false);
	this->addChild(foreground, 1); // add at z:1 for foreground

	// groot	
	this->m_pGunner = new Gunner(); // create a player object

	this->m_pGunner->setSprite("Groot1.png"); // set the player objects sprite
	this->m_pGunner->getSprite()->setPosition(50, foreground->getContentSize().height + this->m_pGunner->getSprite()->getContentSize().height / 2); // set the sprites position

	
	// create a physics body for groot "I am groot!"
	auto gunnerPhysics = PhysicsBody::createBox(this->m_pGunner->getSprite()->getContentSize(), PhysicsMaterial(1, 0, 1));
	this->m_pGunner->getSprite()->setPhysicsBody(gunnerPhysics);

	gunnerPhysics->setDynamic(false); // groot will not move
	

	
	Vector<SpriteFrame*> animFrames(8);
	char str[100] = { 0 };
	for (int i = 1; i < 9; i++){
		sprintf(str, "Groot%d.png", i);
		auto frame = SpriteFrame::create(str, Rect(0, 0, 63, 96)); //we assume that the sprites' dimentions are 540*540 rectangles.
		animFrames.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.2f);

	m_pGunner->getSprite()->runAction(RepeatForever::create(Animate::create(animation)));
	//////////////////ANIMATION CODE/////////

	//m_pGunner->setScale(0.5, 0.5);
	

	this->addChild(this->m_pGunner->getSprite(), 100); // add the player to the scene with z:100

	

	// rocket
	this->m_pRitz = new Ritz(); // create a player object
	this->m_pRitz->setSprite("Rocket.png"); // set the player objects sprite	
	this->m_pRitz->getSprite()->setPosition(Vec2(m_pGunner->getSprite()->getPositionX(), m_pGunner->getSprite()->getPositionY() + m_pRitz->getSprite()->getContentSize().height)); // set the sprites position above groot
	

	// create a physics body for rocket
	auto rocketPhysics = PhysicsBody::createBox(this->m_pRitz->getSprite()->getContentSize(), PhysicsMaterial(1, 0, 1));
	rocketPhysics->setDynamic(false);
	this->m_pRitz->getSprite()->setPhysicsBody(rocketPhysics);
	



	Vector<SpriteFrame*> animFrames2(2);
	char str2[100] = { 0 };
	for (int i = 1; i < 3; i++){
		sprintf(str, "Rocket%d.png", i);
		auto frame2 = SpriteFrame::create(str, Rect(0, 0, 100, 100)); //we assume that the sprites' dimentions are 540*540 rectangles.
		animFrames2.pushBack(frame2);
	}

	auto animation2 = Animation::createWithSpriteFrames(animFrames2, 0.2f);

	m_pRitz->getSprite()->runAction(RepeatForever::create(Animate::create(animation2)));
	//////////////////ANIMATION CODE/////////

	//m_pGunner->setScale(0.5, 0.5);


	this->addChild(this->m_pRitz->getSprite(), 99); // add the player to the scene with z:100

	


	
	// pause button
	auto menu_item_pause = MenuItemImage::create("pause11.png", "pause36.png", CC_CALLBACK_1(GameScene::Pause, this));
	menu_item_pause->setPosition(Point(visibleSize.width - 50, visibleSize.height - 50));

	// end game button
	auto menu_item_endScene = MenuItemImage::create("cancel20.png", "cancel20.png", CC_CALLBACK_1(GameScene::EndGame, this));
	menu_item_endScene->setPosition(Point(visibleSize.width - 50, 50));

	// create menu, add menu items and add to the game scene
	auto *menu = Menu::create(menu_item_pause, menu_item_endScene, NULL);	
	menu->setPosition(Point(0, 0));	
	this->addChild(menu);

	// creating a schedule to control obstacle spawns in delta time
	this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQ * visibleSize.width );
	
	// touch controls
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	//listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	//listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// call the schedule update in order to run this layers update function
	this->scheduleUpdate();


    return true;
}

// calling this function to spawn pipes
void GameScene::SpawnPipe(float dt)
{
	pipe.SpawnPipe(this);
}


// TOUCH BEGIN
bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	//CCLOG("onTouchBegan x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
	m_pRitz->jump();
	m_pRitz->fire(this);
	//m_pGunner->jump();
	return true;
}

/*
	The hello world update function is calling the game managers
	update function 60 times per second or whatever the fps is set
	to. This is the game loop implementation because if a seperate loop was added to the 
	game managers update function the application would be caught in an infinite loop.

	@param delta time
*/

void GameScene::update(float delta)
{	
	//CCLOG("-------------GAME LOOP START--------------");
	// call the player update
	this->m_pGunner->update();
	this->m_pRitz->update();

	// collision detection
	if (m_pRitz->getSprite()->getBoundingBox().intersectsRect(m_pGunner->getSprite()->getBoundingBox()))
	{
		CCLOG("ritz standing");
		// rocket is back on gunner
		m_pRitz->setState(m_pRitz->STANDING);

	}
	else
	{
		m_pRitz->setState(m_pRitz->JUMPING);
	}

	Size visibleSize = Director::getInstance()-> getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	for (int i = 0; i < 2; i++)
	{
		if (backgroundSpriteArray[i]->getPosition().x <= -visibleSize.width / 2 + visibleSize.width / 2 )
		{
			
			backgroundSpriteArray[i]->setPosition(Point((visibleSize.width) + getPosition().x, (visibleSize.height / 2)));
		}	
	}

	for (int i = 0; i < 2; i++)
	{
		backgroundSpriteArray[i]->setPosition (Point(backgroundSpriteArray[i]->getPosition().x -4.0,backgroundSpriteArray[i]->getPosition().y));
	}


	
	// print statement "render"
	//CCLOG("Render");
	//CCLOG("-------------GAME LOOP END--------------");
}

/*
	Pause button creates a new pause scene and pushes it over the game scene

	@param cocos2d::Ref *pSender pointer used by the engine
*/
void GameScene::Pause(cocos2d::Ref *pSender)
{
	CCLOG("Pause");
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(TransitionFade::create(1, scene));

	// to play sound effect if button is pressed but does not work yet
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("button-21.wav", false, 1.0f, 1.0f, 1.0f);
}

/*
	EndGame button creates a new game game scene and replaces the game scene

	@param cocos2d::Ref *pSender pointer used by the engine
*/
void GameScene::EndGame(cocos2d::Ref *pSender)
{
	CCLOG("End Game");
	auto scene = EndScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}

void GameScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
