//
//  TouchDisableLayer.h
//  Diamond
//
//  Created by ManYou on 12-10-2.
//
//

#ifndef Diamond_TouchDisableLayer_h
#define Diamond_TouchDisableLayer_h

#include "cocos2d.h"

class TouchDisableLayer : public cocos2d::CCLayerColor
{
public:
    bool init();
    CREATE_FUNC(TouchDisableLayer);
    static TouchDisableLayer *create(const cocos2d::ccColor4B& color, GLfloat width, GLfloat height);
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif
