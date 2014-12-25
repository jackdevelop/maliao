#ifndef __START_SCENE_H__
#define __START_SCENE_H__


#include "cocos2d.h"

using namespace cocos2d;  
//using namespace CocosDenshion;

class StartScene:public CCLayer
{
public:
	static Scene* createScene();
	virtual bool init();

	CREATE_FUNC(StartScene);
private:
	void menuStartCallback(cocos2d::Ref* pSender);
	void menuSetCallback(cocos2d::Ref* pSender);
	void menuCloseCallback(Ref* pSender);
};


#endif 