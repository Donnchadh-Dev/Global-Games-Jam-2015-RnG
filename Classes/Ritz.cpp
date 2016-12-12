#include "Ritz.h"


Ritz::Ritz()
{
	setName("Ritz");
	m_ePlayerState = STANDING;
	//boundingBox = m_pCharacterSprite->getBoundingBox();
}


Ritz::~Ritz()
{
}

void Ritz::jump()
{
	//("Ritz Jump");
	if (m_ePlayerState == STANDING)
	{
		CCLOG("ritz jumping");
		m_ePlayerState = JUMPING;

		// plays a sound when player jumps
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("jump.wav", false, 1.0f, 1.0f, 1.0f);

		auto action = JumpBy::create(1.5, Point(0, 0), 150, 1);
		m_pCharacterSprite->runAction(action);
	}
	
}

void Ritz::update()
{
	//CCLOG("Updating Ritz");

	// update Ritz poition to that of the sprite
	this->setPosition(this->m_pCharacterSprite->getPosition());
		

}

void Ritz::fire(Layer* layer)
{
	auto bullet = Sprite::create("bullet.png");	
	bullet->setPosition(m_pCharacterSprite->getPosition());	
	auto bulletPhysics = PhysicsBody::createBox(bullet->getContentSize(), PhysicsMaterial(1, 0, 1));
	bullet->setPhysicsBody(bulletPhysics);
	bullet->getPhysicsBody()->setDynamic(true); 	
	bullet->getPhysicsBody()->setGravityEnable(true);
	auto bulletAction = MoveBy::create(1, Point(visibleSize.width, 0));

	// plays a sound when player shoots
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("shoot.wav", false, 1.0f, 1.0f, 1.0f);

	bullet->runAction(bulletAction);
	layer->addChild(bullet, 0);
}