#pragma once

#include "cocos2d.h"
#include "sprite\MapSprite.h"
#include "sprite\HeroSprite.h"

using namespace cocos2d;

class FightScene:public CCLayer
{
public:
	static Scene* createScene();
	virtual bool init();
	void update(float dt);
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

	CREATE_FUNC(FightScene);
private:
	MapSprite* m_mapSprite;
	HeroSprite* m_heroSprite;
	CCSprite* m_rightSpt;

	void FightScene::rightCallback(Ref* pSender);
	
};
