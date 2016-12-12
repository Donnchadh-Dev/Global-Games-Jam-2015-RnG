#include "Floor.h"

USING_NS_CC;

Floor::Floor(){
	// using singleton to get info for our obstacle spawns
	visbleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}


void Pipe::SpawnPipe(Layer *layer){
	CCLOG("SPAWN PIPE");

	// creating obstacles
	auto topPipe = Sprite::create("topPipe.png");
	auto bottomPipe = Sprite::create("bottomPipe.png");

	// creating physics body around obstacles
	auto topPipeBody = PhysicsBody::createBox(topPipe->getContentSize());
	auto bottomPipeBody = PhysicsBody::createBox(bottomPipe->getContentSize());

	// creating random spawns for obstacles
	auto random = CCRANDOM_0_1();

	if (random < LOWER_SCRENE_PIPE_THRESHOLD){ // threshholds are for percent of screen
		random = LOWER_SCRENE_PIPE_THRESHOLD;
	}
	else if (random > UPPER_SCRENE_PIPE_THRESHOLD){
		random = UPPER_SCRENE_PIPE_THRESHOLD;
	}

	auto topPipePosition = (random * visbleSize.height) + (topPipe->getContentSize().height / 2);

	// dynamic bodies are not affected by gravity
	// we should totally experiment with this!
	topPipeBody->setDynamic(false);
	bottomPipeBody->setDynamic(false);

	// setting physics bodys for obstacles
	topPipe->setPhysicsBody(topPipeBody);
	bottomPipe->setPhysicsBody(bottomPipeBody);

	// setting position of top obstacle
	topPipe->setPosition(Point(
		visbleSize.width + topPipe->getContentSize().width + origin.x,
		topPipePosition));

	// setting position of bottom obstacle 
	bottomPipe->setPosition(Point(
		topPipe->getPositionX(),
		topPipePosition - (Sprite::create("Rocket.png")->getContentSize().height * PIPE_GAP) - topPipe->getContentSize().height));

	// adding obstacles to the scene
	layer->addChild(topPipe);
	layer->addChild(bottomPipe);

	// setting velocity of obstacles to give illusion of runner
	auto topPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visbleSize.width, Point(-visbleSize.width *1.5, 0));
	auto bottomPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visbleSize.width, Point(-visbleSize.width *1.5, 0));

	topPipe->runAction(topPipeAction);
	bottomPipe->runAction(bottomPipeAction);
}





