#ifndef PLAYER_H_
#define	PLAYER_H_

// includes
#include <iostream>
#include "Character.h" // inherit from Character

class Player : public Character
{
public:
	Player(){ this->init(); }; // constructor	
	virtual ~Player(){ this->cleanUp(); }; // deconstructor
	virtual bool init(); // initialization
	virtual bool collidesWith(std::shared_ptr<GameObject> obj){ return false; }; // collision detection
	virtual void jump(){ std::cout << "Player jumping" << std::endl; }; // jump
	virtual void duck(){ std::cout << "Player ducking" << std::endl; }; // duck
	virtual void boost(){ std::cout << "Player boosting" << std::endl; }; // boost
	virtual void update(); // update Player
	virtual void cleanUp(); // delete Player object
	virtual void fire(Layer* layer){}; // fire bullet
	
	// sprite
	virtual cocos2d::Sprite* getSprite();
	virtual void setSprite(char* pathToFile);

	// getters
	virtual int getState(){ return m_ePlayerState; };

	// setters 
	virtual void setState(int state){ m_ePlayerState = (EPlayerState)state; };

	typedef enum { ALIVE, DEAD, BOOSTING, JUMPING, STANDING} EPlayerState; // player state

protected:	
	EPlayerState m_ePlayerState; // Player state

};

#endif