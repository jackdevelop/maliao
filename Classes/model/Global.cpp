#include "model\Global.h"


/**
* ��������
**/
Global* Global::m_instance;
Global* Global::getInstance()
{
	if(m_instance == nullptr){
		m_instance = new Global();
	}

	return m_instance;
}




//���캯������ʼ��������Ϣ
Global::Global():
currentLevel(1),
totalLevel(8)
{
	

}

//��������
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