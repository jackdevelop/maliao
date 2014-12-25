#include "cocos2d.h"

using namespace cocos2d;

class SelectScene:public CCLayer
{
public:
	static Scene* createScene();
	
	virtual bool init();
	//virtual bool onTouchesBegan(Touch *pTouch, Event *pEvent);
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
	virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);

	virtual void onExit() override;//3���˳���ǰlayer��ʱ����ã������ﶼ����һЩ�������  
	CREATE_FUNC(SelectScene);


private:
	Point m_touchPoint;
	CCSprite *pselectSprite;
	bool compareSprite(Touch *pTouch);
	void selectOneSprite(CCSprite *sprite);
	void cancelSelectOneSprite();
};

