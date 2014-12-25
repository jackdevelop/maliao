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
	

	Size m_mapSize;
	Size m_titleSize;

	void initObjects();
	// ��Ϸͼ������ϵ��tilemapͼ������ϵ֮���ת��
	Point positionToTileCoord(Point pos);
	Point tilecoordToPosition(Point tileCoord);

};
