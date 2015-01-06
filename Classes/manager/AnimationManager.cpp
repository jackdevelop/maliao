#include "manager\AnimationManger.h"


AnimationManager* AnimationManager::m_instance = nullptr;








/**
初始化
**/
void AnimationManager::init(){
	char temp[20] = { 0 };

	sprintf(temp, "%d", eAniRight);
	AnimationCache::getInstance()->addAnimation(
		createAnimationByAnimationType(eAniRight), temp);


	sprintf(temp, "%d", eAniRightSmall);
	AnimationCache::getInstance()->addAnimation(
		createAnimationByAnimationType(eAniRightSmall), temp);
}







/**
通过类型获取动画
**/
Animation* AnimationManager::createAnimationByAnimationType(AnimationType key)
{
	Vector<SpriteFrame*> pArray;
	SpriteFrame *frame = NULL;
	Texture2D *pTexture;
	Animation *pAnimation = NULL;

	switch (key)
	{
		case eAniRight:
		{
						  pTexture = TextureCache::getInstance()->addImage("fight/hero/walkRight.png");
						  for (int i = 0; i < 10; ++i)
						  {
							  frame = SpriteFrame::createWithTexture(pTexture, CCRectMake(18 * i, 0, 18, 32));
							  pArray.pushBack(frame);
						  }
						  pAnimation = Animation::createWithSpriteFrames(pArray, 0.02f);
						  break;
		}
		case eAniLeft:
		{
						 pTexture = TextureCache::getInstance()->addImage("fight/hero/walkLeft.png");
						 for (int i = 9; i >= 0; --i)
						 {
							 frame = SpriteFrame::createWithTexture(pTexture, CCRectMake(18 * i, 0, 18, 32));
							 pArray.pushBack(frame);
						 }
						 pAnimation = Animation::createWithSpriteFrames(pArray, 0.02f);
						 break;
		}
		case eAniLeftSmall:
		{
							  pTexture = TextureCache::getInstance()->addImage("fight/hero/smallWalkLeft.png");
							  for (int i = 9; i >= 0; --i)
							  {
								  frame = SpriteFrame::createWithTexture(pTexture, CCRectMake(14 * i, 0, 14, 16));
								  pArray.pushBack(frame);
							  }
							  pAnimation = Animation::createWithSpriteFrames(pArray, 0.02f);
							  break;
		}
		case eAniRightSmall:
		{
							   pTexture = TextureCache::getInstance()->addImage("fight/hero/smallWalkRight.png");
							   for (int i = 0; i < 10; ++i)
							   {
								   frame = SpriteFrame::createWithTexture(pTexture, CCRectMake(14 * i, 0, 14, 16));
								   pArray.pushBack(frame);
							   }
							   pAnimation = Animation::createWithSpriteFrames(pArray, 0.02f);
							   break;
		}
		default:
			break;
	}

	//	pArray->release();

	return pAnimation;
}







Animate* AnimationManager::createAnimate(const char *key)
{
	Animation *anim = AnimationCache::getInstance()->animationByName(key);
	if (anim)
	{
		return Animate::create(anim);
	}
	return NULL;
}

Animate* AnimationManager::createAnimate(AnimationType key)
{
	Animation *anim = getAnimation(key);
	if (anim)
	{
		return Animate::create(anim);
	}
	return NULL;
}
Animation* AnimationManager::getAnimation(AnimationType key)
{
	char temp[20] = { 0 };
	sprintf(temp, "%d", key);

	return AnimationCache::getInstance()->animationByName(temp);
}






/**
获取单例
**/
AnimationManager*  AnimationManager::getInstance(){
	if (!m_instance)
	{
		m_instance = new AnimationManager();
		m_instance->init();
	}

	return m_instance;
}