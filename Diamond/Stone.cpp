//
//  Stone.cpp
//  Diamond
//
//  Created by ManYou on 12-9-29.
//
//

#include "Stone.h"
#include "Resources.h"

using namespace cocos2d;


Stone* Stone::createWithSpriteFrameName(const char *pszSpriteFrameName)
{
    Stone *sStone = new Stone;
    if (sStone && sStone->initWithSpriteFrameName(pszSpriteFrameName))
    {
        sStone->autorelease();
        sStone->m_type = kNoneStoneType;
        sStone->m_isChecked = false;
        sStone->m_actionDone = true;
        return sStone;
    }
    CC_SAFE_DELETE(sStone);
    return NULL;
}

Stone* Stone::createWithIndex(const int index){
    Stone *sStone = NULL;
    switch (index) {
        case 0:
            sStone = Stone::createWithSpriteFrameName(kRedHeartStoneName);
            sStone->m_type = kRedHeartStoneType;
            break;
        case 1:
            sStone = Stone::createWithSpriteFrameName(kRedFireStoneName);
            sStone->m_type = kRedFireStoneType;
            break;
        case 2:
            sStone = Stone::createWithSpriteFrameName(kBlueStoneName);
            sStone->m_type = kBlueStoneType;
            break;
        case 3:
            sStone = Stone::createWithSpriteFrameName(kGreenStoneName);
            sStone->m_type = kGreenStoneType;
            break;
        case 4:
            sStone = Stone::createWithSpriteFrameName(kYellowStoneName);
            sStone->m_type = kYellowStoneType;
            break;
        case 5:
            sStone = Stone::createWithSpriteFrameName(kPurpleStoneName);
            sStone->m_type = kPurpleStoneType;
            break;            
        default:
            return NULL;
            break;
    }
    sStone->val = index;
    return sStone;
}


void Stone::setPosition(const cocos2d::CCPoint &pos)
{
    CCSprite::setPosition(pos);
    
    //CCLog("this is my setPosition");
}