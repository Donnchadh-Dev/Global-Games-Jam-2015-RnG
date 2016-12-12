#ifndef GUNNER_H_
#define GUNNER_H_

#include <iostream>
#include "Player.h"

#include "cocos2d.h"


class Gunner : public Player
{
public:
	Gunner();
	virtual ~Gunner();


	void update();
	void jump();


};

#endif // GUNNER_H_
