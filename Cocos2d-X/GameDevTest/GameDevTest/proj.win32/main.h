#ifndef __MAIN_H__
#define __MAIN_H__

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files:
#include <windows.h>
#include <tchar.h>

// C RunTime Header Files
#include "CCStdC.h"

using namespace cocos2d;

class GameLayer : public CCLayer{
	static GameLayer* create(){
		static GameLayer *ret = new (std::nothrow) GameLayer();
		if (ret && ret->init())
		{
			ret->autorelease();
			return ret;
		}
		else
		{
			CC_SAFE_DELETE(ret);
			return nullptr;
		}
	}
};

class GameScene :public CCScene{
public:
	GameScene(void){
		_gameLayer = NULL;
	}
	~GameScene(void){}
	CREATE_FUNC(GameScene);
	virtual bool init(){
		bool bRet = false;
		do{
			CC_BREAK_IF(!CCScene::init());
			_gameLayer = GameLayer::create();
			CCScene::create();
			this->addChild(_gameLayer);
			bRet = true;
		} while (0);
		return bRet;
	}
	GameLayer *_gameLayer;
};

#endif    // __MAIN_H__

