#include "model\Global.h"
#include "sprite\MapSprite.h"
#include <iterator>





MapSprite::MapSprite() :m_tmx(NULL)
, cloudLayer(NULL)
, blockLayer(NULL)
, pipeLayer(NULL)
, landLayer(NULL)
, trapLayer(NULL)
, objectLayer(NULL)
, coinLayer(NULL)
, flagpoleLayer(NULL)
{
	
}



MapSprite::~MapSprite(){
	delete cloudLayer;
	delete blockLayer;
	delete pipeLayer;
	delete landLayer;
	delete trapLayer;
	delete objectLayer;
	delete coinLayer;
	delete flagpoleLayer;
}






void  MapSprite::init(){
	int lv = Global::getInstance()->getCurrentLevel();
	char temp[50] = { 0 };
	sprintf(temp, "fight/map/MarioMap%d.tmx", lv);

	//解析地图数据
	m_tmx = TMXTiledMap::create(temp);
	m_mapSize = m_tmx->getMapSize();
	m_titleSize = m_tmx->getTileSize();
	m_totalMapSize = CCSizeMake(m_mapSize.width * m_titleSize.width, m_mapSize.height * m_titleSize.height);
	cloudLayer = m_tmx->layerNamed("cloud");
	blockLayer = m_tmx->layerNamed("block");
	pipeLayer = m_tmx->layerNamed("pipe");
	landLayer = m_tmx->layerNamed("land");
	trapLayer = m_tmx->layerNamed("trap");
	coinLayer = m_tmx->layerNamed("coin");
	flagpoleLayer = m_tmx->layerNamed("flagpole");
	objectLayer = m_tmx->objectGroupNamed("objects");
	
	//设置地图的锚点 和位置
	m_tmx->setAnchorPoint(Vec2::ZERO);
	Size winSize = Director::getInstance()->getWinSize();
	m_tmx->setPosition(Vec2(0, winSize.height - m_totalMapSize.height));

	//解析对象层
	this->initObjects();
}




/**
解析tmx的地图的一些object属性
**/
void MapSprite::initObjects()
{
	ValueVector tempArray = objectLayer->getObjects();

	
	Value objPointMap;
	for each(objPointMap in tempArray)
	{
		ValueMap objPoint = objPointMap.asValueMap();
		int width = objPoint.at("width").asFloat();
		int height = objPoint.at("height").asFloat();
		int posX = objPoint.at("x").asFloat();
		int posY = objPoint.at("y").asFloat();
		posY -= this->m_titleSize.height;
		Point tileXY = this->positionToTileCoord(ccp(posX, posY));
		const std::string name = objPoint.at("name").asString();
		const std::string type = objPoint.at("type").asString();


		if (name == "others")
		{
			if (type == "BirthPoint")
			{
				// 马里奥在当前地图上的出生点
				marioBirthPos = this->tilecoordToPosition(tileXY);
				marioBirthPos.x += this->m_titleSize.width / 2;
			}
		}
	}
}












Point MapSprite::positionToTileCoord(Point pos)
{
	int x = pos.x / this->m_titleSize.width;
	int y = (this->m_mapSize.height - 1) - pos.y / this->m_titleSize.height;
	return ccp(x, y);
}
//tile格子坐标转化成地图坐标
Point MapSprite::tilecoordToPosition(Point tileCoord)
{
	float x = tileCoord.x * this->m_titleSize.width;
	float y = (this->m_mapSize.height - 1 - tileCoord.y) * this->m_titleSize.height + m_tmx->getPositionY();
	return ccp(x, y);
}




TMXTiledMap * MapSprite::getTMXMap(){
	return m_tmx;
}
Point MapSprite::getMarioBirthPos()
{
	return marioBirthPos;
}




void MapSprite::update(float dt){
	//CCLOG("%f",dt);
}
