#include "cocos2d.h"
using namespace cocos2d;


class MapSprite
{

	


public:
	MapSprite();
	~MapSprite();
	void init();
	TMXTiledMap* getTMXMap();


	// 每张地图中马里奥的出生点，GL坐标系下的坐标，CCGameLayer获取后直接可用的
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
	// 游戏图层坐标系与tilemap图块坐标系之间的转换
	Point positionToTileCoord(Point pos);
	Point tilecoordToPosition(Point tileCoord);

};
