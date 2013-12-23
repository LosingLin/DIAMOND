//
//  GameLayer.h
//  Diamond
//
//  Created by ManYou on 12-9-29.
//
//

#ifndef Diamond_GameLayer_h
#define Diamond_GameLayer_h

#include "cocos2d.h"
#include "Resources.h"

class Stone;
class GameLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameLayer);
    
    virtual void onEnter();
    
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    
     cocos2d::CCPoint convertToMap(cocos2d::CCPoint &glPoint);
     cocos2d::CCPoint convertToGLView(cocos2d::CCPoint &mapPoint);
    
    void initMap();
    void printMap();
    void checkExchangeStone(cocos2d::CCTime &dt);
    
private:
    int map[kMapWidth][kMapHeight];
    Stone *m_movingStone;
    Stone *m_changingStone;
};


#endif
