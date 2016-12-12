
//includes
#include "SpaceShip.h"
#include <iostream>

/*
	Initialization

	@return bool true if initialized succesfully
*/
bool SpaceShip::init()
{
#ifdef _DEBUG
	//CCLOG("SpaceShip::init() called");
#endif
	// initialize SpaceShip
	// set game object type	
	//setType(EGameOjectType::SpaceShip);
	setName("SpaceShip");
	return true;
}

/*
	get SpaceShip sprite information

	@return cocos2d::Sprite* SpaceShip sprite information
*/
cocos2d::Sprite* SpaceShip::getSprite()
{
	return m_pCharacterSprite;
}

/*
	set the SpaceShip sptire information

	@param path to file
*/
void SpaceShip::setSprite(char* pathToFile)
{
	m_pCharacterSprite = cocos2d::Sprite::create(pathToFile);
}

/*
	Run the SpaceShip AI
*/
void SpaceShip::runAI()
{
	//CCLOG("Running SpaceShip AI");
}

/*
	Update the SpaceShip
*/
void SpaceShip::update()
{
	//CCLOG("Updating SpaceShip");
	m_pCharacterSprite->setPositionY(60);
}

/*
	SpaceShip cleanup
*/
void SpaceShip::cleanUp()
{
#ifdef _DEBUG
	//CCLOG("SpaceShip::cleanUp()");
#endif
}