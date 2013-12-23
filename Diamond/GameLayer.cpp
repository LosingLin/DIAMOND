//
//  GameLayer.cpp
//  Diamond
//
//  Created by ManYou on 12-9-29.
//
//

#include "GameLayer.h"
#include "Stone.h"

using namespace cocos2d;

CCScene* GameLayer::scene()
{
    CCScene *scene = CCScene::create();
    GameLayer *layer = GameLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    
    return true;
}

void GameLayer::onEnter()
{
    CCLayer::onEnter();
    this->setTouchEnabled(true);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("stoneboard.plist", "stoneboard.png");
    
    CCSprite *bgSprite = CCSprite::createWithSpriteFrameName("chessBoard01.png");
    bgSprite->setPosition(ccp(winSize.width/2, bgSprite->getContentSize().height/2));
    this->addChild(bgSprite);
    
//    Stone *stone = Stone::createWithSpriteFrameName("stone00.png");
//    stone->setPosition(ccp(winSize.width/2, 200));
//    this->addChild(stone);
    
    initMap();
    printMap();
}
#pragma mark - game init

void GameLayer::initMap()
{
    for (int i=0; i<kMapWidth; ++i)
    {
        for (int j=0; j<kMapHeight; ++j)
        {
            int index = arc4random()%6;
            map[i][j] = index;
            Stone *_stone = Stone::createWithIndex(index);
            _stone->setPosition(ccp(i*100+70, j*100+60));
            _stone->setTag(i*10+j);
            this->addChild(_stone);
        }
    }
}
void GameLayer::printMap()
{
    for (int i=0; i<kMapWidth; ++i)
    {
        for (int j=0; j<kMapHeight; ++j)
        {
            CCLog("%d", map[i][j]);
        }
        CCLog("");
    }
}
#pragma mark - gamelogic

void GameLayer::checkExchangeStone(cocos2d::CCTime &dt)
{
    if (!m_movingStone)
    {
        return;
    }
    int tag = m_movingStone->getTag();
    CCPoint pos = m_movingStone->getPosition();
    pos = convertToMap(pos);
    if (tag!=pos.x*10+pos.y)  //当移动到了下个格子的位置时
    {
        //得到下个格子的Stone
        m_changingStone = dynamic_cast<Stone*>(this->getChildByTag(pos.x*10+pos.y));
        if(!m_changingStone)
        {
            return;
        }
        //把下个格子的stone移动到当前格子离开的那个空格子
        m_changingStone->runAction(CCMoveTo::create(0.05f, ccp(tag/10*100+70, tag%10*100+60)));
        m_changingStone->setTag(tag);
        
        //设置当前格子的tag对应于map中的格子位
        //CCPoint mapPos = convertToMap(pos);
        m_movingStone->setTag(pos.x*10+pos.y);
    }
}

#pragma mark - registerWithTouchDispatcher

void GameLayer::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}

#pragma mark - touch delegate methods

bool GameLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint touchLoc = pTouch->getLocationInView();
    touchLoc = CCDirector::sharedDirector()->convertToGL(touchLoc);
    
    CCPoint mapLoc = convertToMap(touchLoc);
    CCLog("----began-->(%f, %f)", touchLoc.x, touchLoc.y);
    CCLog("----began-->(%f, %f)", mapLoc.x, mapLoc.y);
    
    m_movingStone = dynamic_cast<Stone*>(this->getChildByTag(mapLoc.x*10+mapLoc.y));
    if (!m_movingStone) {
        return false;
    }
    m_movingStone->setPosition(touchLoc);
    this->reorderChild(m_movingStone, 99);
//    this->schedule(schedule_selector(GameLayer::checkExchangeStone), 1/60.0f);
    return true;
}
void GameLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint touchLoc = pTouch->getLocationInView();
    touchLoc = CCDirector::sharedDirector()->convertToGL(touchLoc);
    
    CCPoint mapLoc = convertToMap(touchLoc);
    //边界控制
    if (touchLoc.x<70)
    {
        touchLoc.x=70;
    }
    if (touchLoc.x>570)
    {
        touchLoc.x=570;
    }
    if (touchLoc.y<60)
    {
        touchLoc.y=60;
    }
    if (touchLoc.y>460)
    {
        touchLoc.y=460;
    }
    
    
    m_movingStone->setPosition(touchLoc);
    
    CCLog("----moved-->");
    
    
    
    if (!m_movingStone)
    {
        return;
    }
    int tag = m_movingStone->getTag();
    CCPoint pos = m_movingStone->getPosition();
    pos = convertToMap(pos);
    if (tag!=pos.x*10+pos.y)  //当移动到了下个格子的位置时
    {
        if (tag==(pos.x+1)*10+pos.y+1) {
            
        }
        //得到下个格子的Stone
        m_changingStone = dynamic_cast<Stone*>(this->getChildByTag(pos.x*10+pos.y));
        if(!m_changingStone)
        {
            return;
        }
        //把下个格子的stone移动到当前格子离开的那个空格子
        m_changingStone->runAction(CCMoveTo::create(0.05f, ccp(tag/10*100+70, tag%10*100+60)));
        m_changingStone->setTag(tag);
        
        //设置当前格子的tag对应于map中的格子位
        //CCPoint mapPos = convertToMap(pos);
        m_movingStone->setTag(pos.x*10+pos.y);
    }
    
}
void GameLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint touchLoc = pTouch->getLocationInView();
    touchLoc = CCDirector::sharedDirector()->convertToGL(touchLoc);
    
    //边界控制
    if (touchLoc.x<0)
    {
        touchLoc.x=0;
    }
    if (touchLoc.x>570)
    {
        touchLoc.x=570;
    }
    if (touchLoc.y<0)
    {
        touchLoc.y=0;
    }
    if (touchLoc.y>460)
    {
        touchLoc.y=460;
    }
    
    CCPoint mapLoc = convertToMap(touchLoc);

/*fuck---
    //当快速移动时， 下一格的stone还没来得及跳转到前面的格子时， 会有bug
    Stone *_stone = dynamic_cast<Stone*>(this->getChildByTag(mapLoc.x*10+mapLoc.y));
    if (_stone || _stone!=m_movingStone) {
        Stone *tStone = NULL;
        //左边的格子是空的时
        if (mapLoc.x-1>=0&&mapLoc.x-1<kMapWidth) {
            tStone = dynamic_cast<Stone*>(this->getChildByTag((mapLoc.x-1)*10+(mapLoc.y)));
            if (!tStone || tStone!=m_movingStone) {
                m_movingStone->setPosition(ccp((mapLoc.x-1)*100+70, (mapLoc.y)*100+60));
                m_movingStone->setTag(mapLoc.x*10+mapLoc.y);
                this->reorderChild(m_movingStone, 1);
            }
        }
        //右边的格子是空的时
        if (mapLoc.x+1>=0&&mapLoc.x+1<kMapWidth) {
            tStone = dynamic_cast<Stone*>(this->getChildByTag((mapLoc.x+1)*10+(mapLoc.y)));
            if (!tStone || tStone!=m_movingStone) {
                m_movingStone->setPosition(ccp((mapLoc.x+1)*100+70, (mapLoc.y)*100+60));
                m_movingStone->setTag(mapLoc.x*10+mapLoc.y);
                this->reorderChild(m_movingStone, 1);
            }
        }
        //上边的格子是空的时
        if (mapLoc.y+1>=0&&mapLoc.y+1<kMapWidth) {
            tStone = dynamic_cast<Stone*>(this->getChildByTag((mapLoc.x)*10+(mapLoc.y+1)));
            if (!tStone || tStone!=m_movingStone) {
                m_movingStone->setPosition(ccp((mapLoc.x)*100+70, (mapLoc.y+1)*100+60));
                m_movingStone->setTag(mapLoc.x*10+mapLoc.y);
                this->reorderChild(m_movingStone, 1);
            }
        }
        //下边的格子是空的时
        if (mapLoc.y-1>=0&&mapLoc.y-1<kMapWidth) {
            tStone = dynamic_cast<Stone*>(this->getChildByTag((mapLoc.x)*10+(mapLoc.y-1)));
            if (!tStone || tStone!=m_movingStone) {
                m_movingStone->setPosition(ccp((mapLoc.x)*100+70, (mapLoc.y-1)*100+60));
                m_movingStone->setTag(mapLoc.x*10+mapLoc.y);
                this->reorderChild(m_movingStone, 1);
            }
        }
        return;
    }
 */
/*part2-fuck
    if (!m_movingStone)
    {
        return;
    }
    int tag = m_movingStone->getTag();
    CCPoint pos = m_movingStone->getPosition();
    pos = convertToMap(pos);
    if (tag!=pos.x*10+pos.y)  //当移动到了下个格子的位置时
    {
        //得到下个格子的Stone
        m_changingStone = dynamic_cast<Stone*>(this->getChildByTag(pos.x*10+pos.y));
        if(!m_changingStone)
        {
            return;
        }
        //把下个格子的stone移动到当前格子离开的那个空格子
        m_changingStone->runAction(CCMoveTo::create(0.05f, ccp(tag/10*100+70, tag%10*100+60)));
        m_changingStone->setTag(tag);
        
        //设置当前格子的tag对应于map中的格子位
        //CCPoint mapPos = convertToMap(pos);
        m_movingStone->setTag(pos.x*10+pos.y);
    }
 */
    
    m_movingStone->setPosition(ccp(mapLoc.x*100+70, mapLoc.y*100+60));
    m_movingStone->setTag(mapLoc.x*10+mapLoc.y);
    this->reorderChild(m_movingStone, 1);
    this->unschedule(schedule_selector(GameLayer::checkExchangeStone));
    
    CCLog("----ended-->");
}
void GameLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCLog("----cancelled-->");
}

#pragma mark - uitl methods

CCPoint GameLayer::convertToMap(CCPoint &glPoint)
{
    return CCPointMake(static_cast<int>(glPoint.x)/100, static_cast<int>(glPoint.y)/100);
}
CCPoint GameLayer::convertToGLView(cocos2d::CCPoint &mapPoint)
{
    return CCPointMake((mapPoint.x*100), mapPoint.y*100);
}
