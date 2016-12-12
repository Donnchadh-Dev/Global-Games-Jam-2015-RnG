#ifndef __PIPE_H__
#define __PIPE_H__

#include "cocos2d.h"
USING_NS_CC;
class Pipe
{
	
public:
	// pipe constructor
	Pipe();
	
	// spawns pipe on our specified layer
	void SpawnPipe(Layer *layer);

private:
	// determines the visibility of the player
	Size visbleSize;
	Vec2 origin;

};

#endif // __PIPE_H__
