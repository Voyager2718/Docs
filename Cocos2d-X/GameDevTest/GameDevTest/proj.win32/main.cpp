#include "main.h"
#include "AppDelegate.h"
#include "cocos2d.h"

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	CCScene *scene = CCScene::create();
	CCLayer *layer0 = CCLayer::create();
	CCSprite *sprite0 = CCSprite::create();
	sprite0->setPosition(ccp(300, 300));
	sprite0->setAnchorPoint(ccp(0.5, 0.5));
	scene->addChild(layer0);
	layer0->addChild(sprite0);

	CCDirector::getInstance()->runWithScene(scene);

	// create the application instance
	AppDelegate app;
	return Application::getInstance()->run();
}
;