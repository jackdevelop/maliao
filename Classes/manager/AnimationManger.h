#include "cocos2d.h"

using namespace cocos2d;

// ��������
enum AnimationType
{
	eAniLeft,
	eAniRight,
	eAniLeftSmall,
	eAniRightSmall,
	eAniLeftFire,
	eAniRightFire,
	eAniBlinkCoin,
	eAniMushroom,
	eAniflower,
	eAniTortoiseLeft,
	eAniTortoiseRight,
	eAniTortoiseFly,
	eAniRotatedFireBall,
	eAniBoomedFireBall,
	eAniFireActionR,
	eAniFireActionL,
	eAniFlyFishR,
	eAniFlyFishL,
	eAniArrowBroken,
	eAniSmallDie,
	eAniNormalDie,
	eAniFireDie,
	eAniBossMoveLeft,
	eAniBossMoveRight,
	eAniBossFireLeft,
	eAniBossFireRight,
	eAniBatteryBoom,   // �궷����̨����
	eAniLighting,      // ���綯��
	eAniArrowLeft,
	eAniArrowRight,
	eAniArrowDie,
	eAniArrowActionL,
	eAniArrowActionR
};



class AnimationManager
{
public:
	Animate* createAnimate(const char *key);
	Animate* createAnimate(AnimationType key);
	Animation* getAnimation(AnimationType key);
	
	static AnimationManager*  getInstance();

private:
	static AnimationManager* m_instance;
	
	void AnimationManager::init();
	Animation* AnimationManager::createAnimationByAnimationType(AnimationType key);

};
