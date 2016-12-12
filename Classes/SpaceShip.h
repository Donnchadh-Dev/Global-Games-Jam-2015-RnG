
#ifndef SPACESHIP_H
#define SPACESHIP_H

// includes
#include "Enemy.h"

class SpaceShip : public Enemy
{
public:	
	SpaceShip(){ this->init(); }; // constructor 
	~SpaceShip(){ this->cleanUp(); }; // deconstructor
	virtual bool init(); // initialize the SpaceShip	
	virtual void runAI(); // run SpaceShip AI
	virtual void update(); // update the SpaceShip
	virtual void cleanUp(); // house keeping 

	// sprite
	virtual cocos2d::Sprite* getSprite();
	virtual void setSprite(char* pathToFile);
};

#endif