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
	

	//地图和格子的宽高度
	Size m_mapSize;
	Size m_titleSize;
	Size m_totalMapSize;//地图的实际宽高度 其实就是m_mapSize * m_titleSize

	
	void initObjects();
	// 游戏图层坐标系与tilemap图块坐标系之间的转换
	Point positionToTileCoord(Point pos);
	Point tilecoordToPosition(Point tileCoord);

};
