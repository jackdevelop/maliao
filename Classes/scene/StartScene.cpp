#include "StartScene.h"
#include "scene\SelectScene.h"
#include "util\GameUtil.h"

/**
*静态 创建场景
**/
Scene* StartScene::createScene()
{
    auto scene = Scene::create();
    auto layer = StartScene::create();
    scene->addChild(layer);
    return scene;
}



bool StartScene::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	
	/**
	从plist中加载并使用
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Sheet_Login.plist", "Sheet_Login.png");
	auto sprite = Sprite::createWithSpriteFrameName("JM_UI_BG_0113_1.png");
	this->addChild(sprite);
	**/


	
	//添加背景图片  并保持全屏
	Size winSize = Director::getInstance()->getWinSize();
	CCLOG("屏幕尺寸：%f,%f",winSize.width,winSize.height);
	auto bg = Sprite::create("start/background.png");
	bg->setPosition(Vec2(winSize.width/2,winSize.height/2));
	bg->setContentSize(winSize);
	this->addChild(bg);
	



	//创建菜单
	auto startButton = MenuItemImage::create( "start/startgame_normal.png","start/startgame_select.png",CC_CALLBACK_1(StartScene::menuStartCallback, this));
	startButton->setPosition(Vec2(winSize.width/2 ,winSize.height/2));

	 auto setButton = MenuItemImage::create("start/setting_n.png","start/setting_s.png",CC_CALLBACK_1(StartScene::menuSetCallback, this));
	setButton->setPosition(Vec2(winSize.width/2 ,winSize.height/2 - setButton->getContentSize().height));


	auto closeButton = MenuItemImage::create("start/quitgame_normal.png","start/quitgame_select.png",CC_CALLBACK_1(StartScene::menuCloseCallback, this));
	closeButton->setPosition(Vec2(winSize.width/2 ,winSize.height/2 - closeButton->getContentSize().height*2));

    auto menu = Menu::create(startButton,setButton,closeButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	


	return true;
}



//开始
void StartScene::menuStartCallback(Ref* pSender)
{
	auto scene = SelectScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

//设置
void StartScene::menuSetCallback(Ref* pSender)
{


}

//结束
void StartScene::menuCloseCallback(Ref* pSender)
{
	GameUtil::end();
}
