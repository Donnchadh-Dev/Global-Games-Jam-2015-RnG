#include "Pipe.h"
#include "Definitions.h"

USING_NS_CC;

Pipe::Pipe(){
	// using singleton to get info for our obstacle spawns
	visbleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}


void Pipe::SpawnPipe(Layer *layer){
	//CCLOG("SPAWN PIPE");

	// creating obstacles
	auto spaceShip = Sprite::create("topPipe.png");
	auto groundEnemyA = Sprite::create("bottomPipe.png");

	// creating physics body around obstacles
	auto spaceShipBody = PhysicsBody::createBox(spaceShip->getContentSize());
	auto bottomPipeBody = PhysicsBody::createBox(groundEnemyA->getContentSize());
	
	auto spaceshipY = (CCRANDOM_0_1() * visbleSize.height) + 150;
	auto groundEnemyAY = (CCRANDOM_0_1() * visbleSize.height) + 150;

	/*
	// this controls where our spaceships spawn
	while (spaceshipY < visbleSize.height / 2){
		spaceshipY = CCRANDOM_0_1() * visbleSize.height;
	}
	while (groundEnemyAY > visbleSize.height / 2){
		spaceshipY = CCRANDOM_0_1() * visbleSize.height;
	}
	*/
		

	// dynamic bodies are not affected by gravity
	// we should totally experiment with this!
	spaceShipBody->setDynamic(true);
	spaceShipBody->setGravityEnable(false);
	bottomPipeBody->setDynamic(true);

	// setting physics bodys for obstacles
	spaceShip->setPhysicsBody(spaceShipBody);
	groundEnemyA->setPhysicsBody(bottomPipeBody);

	// setting position of top obstacle
	spaceShip->setPosition(Point(
		visbleSize.width + spaceShip->getContentSize().width + origin.x,
		spaceshipY));

	// setting position of bottom obstacle 
	groundEnemyA->setPosition(Point(
		visbleSize.width + groundEnemyA->getContentSize().width + origin.x,
		groundEnemyAY));

	// adding obstacles to the scene
	layer->addChild(spaceShip, 1);
	layer->addChild(groundEnemyA, 1);

	// setting velocity of obstacles to give illusion of runner
	//auto spaceShipAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visbleSize.width, Point(-visbleSize.width *1.5, 0));
	auto spaceShipAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visbleSize.width, Point(-visbleSize.width *1.5, 0));
	auto groundEnemyAAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visbleSize.width, Point(-visbleSize.width *1.5, 0));
	
	spaceShip->runAction(spaceShipAction);
	groundEnemyA->runAction(groundEnemyAAction);
}





