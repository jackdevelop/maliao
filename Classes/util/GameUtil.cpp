#include "util\GameUtil.h"
#include <strstream >

using namespace std;
using namespace cocos2d;

//结束
void GameUtil::end()
{
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
		MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
		return;
	#endif

		Director::getInstance()->end();

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
	#endif
}




/**
*int转化成std::string
*/
std::string GameUtil::int_to_string(int num)
{
	strstream ss;
	string s;
    ss << num;
	ss >> s;

	return s;
}
