#include "cocos2d.h"


using namespace cocos2d;

class HeroSprite:public Node
{

public:
	Sprite *mainBody;  // 主要的马里奥精灵

	SpriteFrame *m_smallRight;    // 正常状态下马里奥面向右
	SpriteFrame *m_smallJumpRight;     // 正常情况下马里奥面向左
	SpriteFrame *m_smallLeft;  // 左跳在空中停留状态下，主角对应的纹理
	SpriteFrame *m_smallJumpLeft; // 右跳同理
	
	static enum hero_state{
		stand_l,
		stand_r,
		right,
		up,
	};

public:
	HeroSprite();
	~HeroSprite();

	bool  init();
	void setHeroState(int state);
	static HeroSprite* create();




private:
	int m_crrentState;
};
