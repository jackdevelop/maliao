#include "scene\SelectScene.h"
#include "model\Global.h"
#include "util/GameUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include "scene\FightScene.h"

/**
*静态 创建场景
**/
Scene* SelectScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SelectScene::create();
    scene->addChild(layer);
    return scene;
}



bool SelectScene::init()
{
	if ( !Layer::init() )
    {
        return false;
    }
	
	pselectSprite = nullptr;
	/**
	//这个是监听多点
	auto listener = EventListenerTouchAllAtOnce::create();
	void SelectScene::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
	{
		CCLOG("SelectScene::onTouchesBegan");
	}

	**/
	auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(SelectScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(SelectScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SelectScene::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(SelectScene::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
	/** 注册监听器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite3);
    _touchListener = listener;
	**/



	Size winSize = Director::getInstance()->getWinSize();
	//添加背景图片  并保持全屏
	auto bg = Sprite::create("select/bg.png");
	bg->setPosition(Vec2(winSize.width/2,winSize.height/2));
	bg->setContentSize(winSize);
	this->addChild(bg);


	//添加每个关卡的图片
	CCString *seleteName = NULL;
	CCString *selectLv = NULL;
	for (int i = 1; i <= Global::getInstance()->getTotalLevel(); ++i)
	{
		seleteName = CCString::createWithFormat("select/lv/select%d.jpg", i);
		Sprite *pSprite = Sprite::create(seleteName->getCString());
		if(i<5)
			pSprite->setPosition(ccp((i)*(pSprite->getContentSize().width+30)-30, winSize.height/2 + pSprite->getContentSize().height));
		else
			pSprite->setPosition(ccp((i-4)*(pSprite->getContentSize().width+30)-30, winSize.height/2 - + pSprite->getContentSize().height));

		this->addChild(pSprite);

		
		selectLv = CCString::createWithFormat("lv%d", i);
		pSprite->setName(selectLv->getCString());
		std::string name = pSprite->getName();
		CCLOG("sprite name :%s",name.c_str());
		
		CCLabelTTF *pLevel = CCLabelTTF::create(selectLv->getCString(), "Arial", 20);
		pLevel->setPosition(pSprite->getContentSize().width/2,pSprite->getContentSize().height/2);
		pSprite->addChild(pLevel);

	}

	return true;
}







bool SelectScene::compareSprite(Touch *pTouch)
{
	auto location = pTouch->getLocation();
	for (int i = 1; i <= Global::getInstance()->getTotalLevel(); ++i)
	{
		std::string name = "lv";
		name += GameUtil::int_to_string(i);

		auto *pSprite = static_cast<Sprite*>(this->getChildByName(name));
		if (pSprite)
		{
			
			Point locationInNode = pSprite->convertToNodeSpace(location);
			Size s = pSprite->getContentSize();
			Rect rect = Rect(0, 0, s.width, s.height);
			if (rect.containsPoint(locationInNode))
			{
				CCLOG("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
				selectOneSprite(pSprite);
				return true;
			}
		}
		
	}

    return false;
}
void SelectScene::selectOneSprite(CCSprite *pSprite)
{
	if(pselectSprite){
		pselectSprite->setOpacity(255);
	}

	pselectSprite = pSprite;
	pSprite->setOpacity(180);
}
void SelectScene::cancelSelectOneSprite()
{
	if (pselectSprite)
	{
		pselectSprite->setOpacity(255);
		
		pselectSprite = nullptr;

	}
	

}





void SelectScene::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	auto diff = pTouch->getDelta();
	this->compareSprite(pTouch);
}

void SelectScene::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	CCLOG("SelectScene::onTouchEnded");
	if (pselectSprite)
	{	
		//删除事件
		_eventDispatcher->removeAllEventListeners();


		//进入新的场景
		std::string name = pselectSprite->getName();
		char c= name[2];
		int lv=atoi(&c);
		Global::getInstance()->setCurrentLevel(lv);
		auto scene = FightScene::createScene();
		Director::getInstance()->replaceScene(scene);
	}
	this->cancelSelectOneSprite();
}

void SelectScene::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
	//this->cancelSelectOneSprite();
}



bool SelectScene::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	bool flag =  this->compareSprite(pTouch);
	return flag;
}



















void SelectScene::onExit()
{
	CCLOG("SelectScene::onExit()");
	//_eventDispatcher->removeEventListenersForTarget(this);
	//_eventDispatcher->removeAllEventListeners();
	Layer::onExit();
}
