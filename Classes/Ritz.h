#ifndef RITZ_H__
#define RITZ_H__

#include <iostream>
#include "Player.h"
#include "cocos2d.h"

class Ritz : public Player
{
public:
	Ritz();
	virtual ~Ritz();


	void update();
	void jump();
	void fire(Layer* layer);

};

#endif // RITZ_H__
