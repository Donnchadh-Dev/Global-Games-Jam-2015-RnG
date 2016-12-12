#include "MainMenuScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	// adds background music for main menu
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("background-music-aac.wav", true);
	
	auto backGround =  Sprite::create("background.png");
	backGround->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backGround);

	// create the main menu items
	auto menu_item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(MainMenu::Play, this)); // start the game scene
	auto menu_item_2 = MenuItemFont::create("Highscores", CC_CALLBACK_1(MainMenu::Highscores, this)); // push the high scores scene
	auto menu_item_3 = MenuItemFont::create("Settings", CC_CALLBACK_1(MainMenu::Settings, this)); // push the settings scene
	//button to resume playing of background music
	auto menu_item_4 = MenuItemImage::create("volumeBtn.png", "VolumeBtn.png", CC_CALLBACK_1(MainMenu::volumeButton, this));
	// button to mute the background music
	auto menu_item_5 = MenuItemImage::create("muteBtn.png", "muteBtn.png", CC_CALLBACK_1(MainMenu::muteButton, this));

	// position the menu buttons on screen
	menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 6) * 4.5));
	menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 6) * 3));
	menu_item_3->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 6) * 1.5));
	menu_item_4->setPosition(Point(visibleSize.width - 120, visibleSize.height - 50));
	menu_item_5->setPosition(Point(visibleSize.width - 50, visibleSize.height - 50));

	// create menu and add menu items
	auto *menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, menu_item_4, menu_item_5,NULL);

	// position the main menu
	menu->setPosition(Point(0, 0));

	// add the menu to the scene
	this->addChild(menu);

	pressed = false;

	// adding sprite to the menu scene
	auto sprite = Sprite::create("topPipe.png");
	sprite->setPosition(Point(visibleSize.width - 280, visibleSize.height - 130));
	sprite->setScale(4, 4);
	this->addChild(sprite);

    return true;
}

/* 
	Play button creates a new game scene and replaces the main menu.

	@param cocos2d::Ref *pSender pointer used by the engine
*/
void MainMenu::Play(cocos2d::Ref *pSender)
{
	CCLOG("Play");

	// to play sound effect if button is pressed but does not work yet
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("button-21.wav", false, 1.0f, 1.0f, 1.0f);

	// delay opening of game scene to hear the button sound effects
	std::chrono::seconds duration(1);
	std::this_thread::sleep_for(duration); // Sleep for 2 seconds.

	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}


	

/*
	Highscores button creates the highscores scene to display the current scores for 
	players who have previously played the game.

	@param cocos2d::Ref *pSender pointer used by the engine
*/
void MainMenu::Highscores(cocos2d::Ref *pSender)
{
	CCLOG("Highscores");
	//auto scene = MainMenu::createScene();
	//Director::getInstance()->replaceScene(TransitionFade::create(1, scene));

	// to play sound effect if button is pressed but does not work yet
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("button-21.wav", false, 1.0f, 1.0f, 1.0f);

	// delay opening of game scene to hear the button sound effects
	std::chrono::seconds duration(1);
	std::this_thread::sleep_for(duration); // Sleep for 2 seconds.
}


/*
	Settings button creates the settings scene to modify how the game is rendered and
	played.

	@param cocos2d::Ref *pSender pointer used by the engine
*/
void MainMenu::Settings(cocos2d::Ref *pSender)
{
	CCLOG("Settings");	
	//auto scene = MainMenu::createScene();
	//Director::getInstance()->replaceScene(TransitionFade::create(1, scene));

	// to play sound effect if button is pressed but does not work yet
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("button-21.wav", false, 1.0f, 1.0f, 1.0f);

	// delay opening of game scene to hear the button sound effects
	std::chrono::seconds duration(1);
	std::this_thread::sleep_for(duration); // Sleep for 2 seconds.
}


/*
	ImageButton is an example of how an image can be used as a button.

	@param cocos2d::Ref *pSender pointer used by the engine
*/
void MainMenu::muteButton(cocos2d::Ref *pSender)
{
	CCLOG("IMAGE Button");
	//auto scene = MainMenu::createScene();
	//Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
	
	if (pressed = true){
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}

}

void MainMenu::volumeButton(cocos2d::Ref *pSender)
{
	CCLOG("muteButton");
	if (pressed = true){
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	}
}


void MainMenu::menuCloseCallback(Ref* pSender)
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
