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
	
	CREATE_FUNC(FightScene);
private:
	MapSprite* m_mapSprite;
	HeroSprite* m_heroSprite;
};
