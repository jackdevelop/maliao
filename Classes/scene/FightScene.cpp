#include "scene\FightScene.h"
#include "util\GameUtil.h"

/**
*静态 创建场景
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

	m_rightSpt = nullptr;

	
	m_mapSprite = new MapSprite();
	m_mapSprite->init();
	this->addChild(m_mapSprite->getTMXMap());


	m_heroSprite = HeroSprite::create();
	m_heroSprite->setAnchorPoint(ccp(0.5f, 0.0f));
	m_heroSprite->setPosition(m_mapSprite->getMarioBirthPos());
	this->addChild(m_heroSprite);


	//加载ui
	CCSprite* controlUI = CCSprite::create("fight/ui/controlUI.png");
	controlUI->setAnchorPoint(Vec2::ZERO);
	this->addChild(controlUI);

	/**
	auto rightButton = MenuItemImage::create("fight/ui/backKeyImage.png", "fight/ui/backKeyImage.png", CC_CALLBACK_1(FightScene::rightCallback, this));
	rightButton->setPosition(Vec2(100, 100));

	auto menu = Menu::create(rightButton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	**/

	m_rightSpt = CCSprite::create("fight/ui/backKeyImage.png");
	m_rightSpt->setPosition(100,50);
	this->addChild(m_rightSpt);

	
	
	//监听事件
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(FightScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(FightScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(FightScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
	

	//开始启动地图
	this->scheduleUpdate();

	return true;
}









void FightScene::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	
}
void FightScene::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	m_heroSprite->setHeroState(HeroSprite::stand_r);
}
bool FightScene::onTouchBegan(Touch *pTouch, Event *pEvent){
	CCLOG("%s", pEvent->getType());
	auto location = pTouch->getLocation();

	Point locationInNode = m_rightSpt->convertToNodeSpace(location);
	Size s = m_rightSpt->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	if (rect.containsPoint(locationInNode))//往右行走
	{
		m_heroSprite->setHeroState(HeroSprite::move_right);
		return true;
	}


	return false;
}



//更新
void FightScene::update(float dt){
	int heroCurrentState = m_heroSprite->getHeroState();
	this->m_mapSprite->update(dt);
}

