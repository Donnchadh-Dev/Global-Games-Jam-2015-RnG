#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"
#include "Ritz.h"
#include "Gunner.h"
#include "Pipe.h"
#include "Player.h"
#include <vector>

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	
	// update the game scene
	void update(float) override;

	// pointer to array which holds backgrounds
	cocos2d::Sprite *backgroundSpriteArray[2];
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
		
	void Pause(Ref *pSender);
	void EndGame(Ref *pSender);

	// function declaration for spawn pipe
	void SpawnPipe(float dt);


	// touch controls 
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
	//void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event);
	//void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event);


			

private:

	void SetPhysicsWorld(PhysicsWorld *world) { m_pSceneWorld = world; };
		
	PhysicsWorld* m_pSceneWorld;
	Player* m_pGunner; // I am groot!
	Player* m_pRitz; // player object rocket
	Pipe pipe; // pipe object
		
	
	
};



#endif // __GAMESCENE_SCENE_H__
