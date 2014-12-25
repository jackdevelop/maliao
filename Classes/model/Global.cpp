#include "model\Global.h"


/**
* 创建单例
**/
Global* Global::m_instance;
Global* Global::getInstance()
{
	if(m_instance == nullptr){
		m_instance = new Global();
	}

	return m_instance;
}




//构造函数，初始化基本信息
Global::Global():
currentLevel(1),
totalLevel(8)
{
	

}

//析构函数
Global::~Global()
{

}


int Global::getCurrentLevel()
{
	return currentLevel;
}

int Global::getTotalLevel()
{
	return totalLevel;
}

void Global::setCurrentLevel(int totalLevel)
{
	this->totalLevel = totalLevel;
}

void Global::setTotalLevel(int currentLevel)
{
	this->currentLevel = currentLevel;
}