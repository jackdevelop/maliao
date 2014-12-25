#include "model\Global.h"
#include "sprite\MapSprite.h"
#include <iterator>





MapSprite::MapSprite(){
	
}


MapSprite::~MapSprite(){


}



void  MapSprite::init(){

	int lv = Global::getInstance()->getCurrentLevel();
	char temp[50] = { 0 };
	sprintf(temp, "fight/map/MarioMap%d.tmx", lv);


	
	//解析地图数据
	TMXTiledMap * tmx = TMXTiledMap::create(temp);
	m_tmx = tmx;
	m_mapSize = tmx->getMapSize();
	m_titleSize = tmx->getTileSize();
	cloudLayer = tmx->layerNamed("cloud");
	blockLayer = tmx->layerNamed("block");
	pipeLayer = tmx->layerNamed("pipe");
	landLayer = tmx->layerNamed("land");
	trapLayer = tmx->layerNamed("trap");
	coinLayer = tmx->layerNamed("coin");
	flagpoleLayer = tmx->layerNamed("flagpole");
	objectLayer = tmx->objectGroupNamed("objects");
	this->initObjects();


	//设置地图的锚点 和位置
	tmx->setAnchorPoint(Vec2::ZERO);
	int height = m_mapSize.height * m_titleSize.height;
	Size winSize = Director::getInstance()->getWinSize();
	tmx->setPosition(Vec2(0, winSize.height - height));	
}

/**
解析tmx的地图的一些object属性
**/
void MapSprite::initObjects()
{
	ValueVector tempArray = objectLayer->getObjects();

	float x, y, w, h;
	Value objPointMap;
	for each(objPointMap in tempArray)
	{
		ValueMap objPoint = objPointMap.asValueMap();
		int width = objPoint.at("width").asFloat();
		int height = objPoint.at("height").asFloat();
		//std::string type = objPoint.at("type").asString();
		int posX = objPoint.at("x").asFloat();
		int posY = objPoint.at("y").asFloat();
		posY -= this->m_titleSize.height;
		Point tileXY = this->positionToTileCoord(ccp(posX, posY));

		int type = objPoint.at("type").asFloat();
		int name = objPoint.at("name").asFloat();
	}
		//CCLOG("%s", objPoint["name"].getType());
		//std::string name;

		
		//objPoint = NULL;
		/**
		std::string type = NULL;
		vc = objPoint.at("type");
		if (vc.isNull()){
		}
		else
		{
			//type = objPoint.at("type").asString();
		}
		**/

		/**
		if (name == "others")
		{
			if (type == "BirthPoint")
			{
				// 马里奥在当前地图上的出生点
				marioBirthPos = this->tilecoordToPosition(tileXY);
				marioBirthPos.x += this->m_titleSize.width / 2;
			}
			else if (type == "flagpoint")
			{
				//flagPoint = ccp(posX, posY);
			}
			else if (type == "finalpoint")
			{
				//finalPoint = ccp(posX, posY);
			}
			else if (type == "bridgestartpos")
			{
				//bridgeTileStartPos = tileXY;
			}
		}
		**/
}





TMXTiledMap * MapSprite::getTMXMap(){
	return m_tmx;
}
Point MapSprite::getMarioBirthPos()
{
	return marioBirthPos;
}

Point MapSprite::positionToTileCoord(Point pos)
{
	int x = pos.x / this->m_titleSize.width;
	int y = (this->m_mapSize.height - 1) - pos.y / this->m_titleSize.height;
	return ccp(x, y);
}

Point MapSprite::tilecoordToPosition(Point tileCoord)
{
	float x = tileCoord.x * this->m_titleSize.width;
	float y = (this->m_mapSize.height - 1 - tileCoord.y) * this->m_titleSize.height;
	return ccp(x, y);
}