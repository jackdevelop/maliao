#include "cocos2d.h"
using namespace cocos2d;


class MapSprite
{

	


public:
	MapSprite();
	~MapSprite();

	void init();
	TMXTiledMap* getTMXMap();


	// ÿ�ŵ�ͼ������µĳ����㣬GL����ϵ�µ����꣬CCGameLayer��ȡ��ֱ�ӿ��õ�
	Point marioBirthPos;
	Point getMarioBirthPos();


	void update(float dt);
private:
	TMXTiledMap* m_tmx;
	TMXLayer*  cloudLayer;
	TMXLayer*  blockLayer;
	TMXLayer*  pipeLayer;
	TMXLayer*  landLayer;
	TMXLayer*  trapLayer;
	CCTMXObjectGroup *  objectLayer;
	TMXLayer*  coinLayer;
	TMXLayer*  flagpoleLayer;
	

	//��ͼ�͸��ӵĿ�߶�
	Size m_mapSize;
	Size m_titleSize;
	Size m_totalMapSize;//��ͼ��ʵ�ʿ�߶� ��ʵ����m_mapSize * m_titleSize

	
	void initObjects();
	// ��Ϸͼ������ϵ��tilemapͼ������ϵ֮���ת��
	Point positionToTileCoord(Point pos);
	Point tilecoordToPosition(Point tileCoord);

};
