//
//  TouchDisableLayer.cpp
//  Diamond
//
//  Created by ManYou on 12-10-2.
//
//

#include "TouchDisableLayer.h"

using namespace cocos2d;

bool TouchDisableLayer::init()
{
    if(!CCLayerColor::init());
    {
        
        this->setTouchEnabled(true);
        return false;
    }
    return true;
}

TouchDisableLayer *TouchDisableLayer::create(const cocos2d::ccColor4B &color, GLfloat width, GLfloat height)
{
    TouchDisableLayer *touchLayer = new TouchDisableLayer;
    if (touchLayer && touchLayer->initWithColor(color, width, height)) {
        touchLayer->setTouchEnabled(true);
        touchLayer->autorelease();
        return touchLayer;
    }
    return NULL;
}

void TouchDisableLayer::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}

bool TouchDisableLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return true;
}
void TouchDisableLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}
void TouchDisableLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}
void TouchDisableLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}
