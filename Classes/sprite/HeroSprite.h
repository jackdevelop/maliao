#include "cocos2d.h"


using namespace cocos2d;

class HeroSprite:public Node
{

public:
	Sprite *mainBody;  // ��Ҫ������¾���

	SpriteFrame *m_smallRight;    // ����״̬�������������
	SpriteFrame *m_smallJumpRight;     // ��������������������
	SpriteFrame *m_smallLeft;  // �����ڿ���ͣ��״̬�£����Ƕ�Ӧ������
	SpriteFrame *m_smallJumpLeft; // ����ͬ��
	
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
