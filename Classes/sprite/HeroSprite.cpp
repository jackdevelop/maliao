
#include "sprite/HeroSprite.h"
#include "manager/AnimationManger.h"





HeroSprite::HeroSprite() :
mainBody(NULL),
m_smallRight(NULL),
m_smallJumpRight(NULL),
m_smallLeft(NULL),
m_smallJumpLeft(NULL)
{
	CCTexture2D *pTexture = TextureCache::getInstance()->addImage("fight/hero/smallWalkRight.png");
	m_smallRight = SpriteFrame::createWithTexture(pTexture, CCRectMake(0, 0, 14, 16));
	m_smallRight->retain();
	m_smallJumpRight = SpriteFrame::createWithTexture(pTexture, CCRectMake(140, 0, 14, 16));
	m_smallJumpRight->retain();

	pTexture = TextureCache::getInstance()->addImage("fight/hero/smallWalkLeft.png");
	m_smallLeft = SpriteFrame::createWithTexture(pTexture, CCRectMake(14 * 9, 0, 14, 16));
	m_smallLeft->retain();
	m_smallJumpLeft = SpriteFrame::createWithTexture(pTexture, CCRectMake(140, 0, 14, 16));
	m_smallJumpLeft->retain();

	this->setContentSize(CCSizeMake(14, 16));
}


HeroSprite::~HeroSprite(){

}




HeroSprite* HeroSprite::create()
{
	HeroSprite *pHero = new HeroSprite();
	if (pHero && pHero->init())
	{
		pHero->autorelease();
		return pHero;
	}
	CC_SAFE_DELETE(pHero);
	return NULL;
}


bool  HeroSprite::init(){
	if (!CCNode::init())
	{
		return false;
	}

	
	// 最初加载的是小型马里奥
	mainBody = Sprite::create("fight/hero/smallWalkRight.png", CCRectMake(0, 0, 14, 16));
	mainBody->setAnchorPoint(Vec2::ZERO);
	this->addChild(mainBody);
	this->setHeroState(stand_r);
	

	this->scheduleUpdate();
	return true;
}



/**
设置状态
**/
void HeroSprite::setHeroState(int state){
	if (m_crrentState == state)
	{
		return;
	}


	mainBody->stopAllActions();
	switch (state)
	{
		case	stand_r:
			mainBody->setDisplayFrame(m_smallRight);
			break;
		case	stand_l:
			mainBody->setDisplayFrame(m_smallLeft);
			break;
		case move_right:
			mainBody->runAction(RepeatForever::create(
				AnimationManager::getInstance()->createAnimate(eAniRightSmall)));
			break;
		default:
			break;
	}

	m_crrentState = state;
}
int HeroSprite::getHeroState(){
	return m_crrentState;
}




//更新tick
void HeroSprite::update(float dt){
	switch (m_crrentState)
	{
	case move_right:
		int x = this->getPositionX();
		int y = this->getPositionY();
		this->setPositionX(x + 1);
		break;

	}
}