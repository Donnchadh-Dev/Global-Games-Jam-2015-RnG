
// includes
#include <iostream>
#include "Player.h"
#include "cocos2d\cocos\math\Vec2.h"


/*
	Initialize the player

	@return bool true if initialized, false if not
*/
bool Player::init()
{
#ifdef _DEBUG
	//CCLOG("Player::init() called");
#endif	
	setType(EGameOjectType::PLAYER);
	setName("Player name");
	return true;
}

/*
	get player sprite information

	@return cocos2d::Sprite* the player sprite information
*/
cocos2d::Sprite* Player::getSprite()
{	
	return m_pCharacterSprite;
}

/*
	set player sprite information
*/
void Player::setSprite(char* pathToFile)
{
	m_pCharacterSprite = cocos2d::Sprite::create(pathToFile);
}

/*
	Update the player
*/
void Player::update()
{
	//CCLOG("Updating Player");
	
	// update the player poition to that of the sprite
	this->setPosition(this->m_pCharacterSprite->getPosition());
}

void Player::cleanUp()
{
#ifdef _DEBUG
	//CCLOG("Player::cleanUp()");
#endif	
}