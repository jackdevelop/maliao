#include "scene\FightScene.h"
#include "util\GameUtil.h"

/**
*¾²Ì¬ ´´½¨³¡¾°
**/
Scene* FightScene::createScene()
{
    auto scene = Scene::create();
    auto layer = FightScene::create();
    scene->addChild(layer);
    return scene;
}



bool FightScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	
	m_mapSprite = new MapSprite();
	m_mapSprite->init();
	this->addChild(m_mapSprite->getTMXMap());


	m_heroSprite = HeroSprite::create();
	m_heroSprite->setAnchorPoint(ccp(0.5f, 0.0f));
	m_heroSprite->setPosition(m_mapSprite->getMarioBirthPos());
	this->addChild(m_heroSprite);

	return true;
}



