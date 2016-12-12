#include "Gunner.h"


Gunner::Gunner()
{
	setName("Gunner");
	m_ePlayerState = ALIVE;

}


Gunner::~Gunner()
{
}

void Gunner::jump()
{
	//("Gunner Jump");
	if (m_ePlayerState != JUMPING)
	{
		m_ePlayerState = JUMPING;

		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("jump.wav", false, 1.0f, 1.0f, 1.0f);

		auto action = JumpBy::create(1.5, Point(0, 0), 300, 1);
		m_pCharacterSprite->runAction(action);
	}
	m_ePlayerState = STANDING;
}

void Gunner::update()
{
	//CCLOG("Updating Gunner");

	// update Gunner poition to that of the sprite
	this->setPosition(this->m_pCharacterSprite->getPosition());

	// reset jumping when Gunner lands
	if (m_pCharacterSprite->getPhysicsBody()->isResting()) m_ePlayerState = STANDING;

}

