//
//  Stone.h
//  Diamond
//
//  Created by ManYou on 12-9-29.
//
//

#ifndef Diamond_Stone_h
#define Diamond_Stone_h

#include "cocos2d.h"

enum kStoneType
{
    kYellowStoneType = 4,
    kRedFireStoneType = 1,
    kGreenStoneType = 3,
    kBlueStoneType =2,
    kRedHeartStoneType = 0,
    kPurpleStoneType = 5,
    kNoneStoneType = -1,
};

class Stone : public cocos2d::CCSprite
{
public:
    virtual void setPosition(const cocos2d::CCPoint& pos);
    static Stone* createWithSpriteFrameName(const char *pszSpriteFrameName);
    static Stone* createWithIndex(const int index);
    
    int m_mapX;
    int m_mapY;
    kStoneType m_type;
    int val;
    bool m_isChecked;
    bool m_actionDone;
private:
    
};


#endif
