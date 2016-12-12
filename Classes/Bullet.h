#ifndef BULLET_H
#define BULLET_H

#include "cocos2d.h"

class Bullet : public cocos2d::Layer
{
public:

	Bullet(){ this->init(); }
	~Bullet(){ this->cleanUp(); }
	virtual bool init();
	//virtual void update();
	virtual void cleanUp();

	virtual cocos2d::Sprite* getSprite();
	virtual void setSprite(char* pathToFile);

private:

};

#endif 