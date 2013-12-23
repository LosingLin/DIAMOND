//
//  GameLayer11.cpp
//  Diamond
//
//  Created by ManYou on 12-9-29.
//
//

#include "GameLayer1.h"
#include "Stone.h"
#include "TouchDisableLayer.h"
#include "Resources.h"

using namespace cocos2d;

#define kXOffset 70
#define kYOffset 60
#define kStoneWidth 100
#define kStoneHeight 100

#define kTouchDisableLayerTag 101


CCScene* GameLayer1::scene()
{
    CCScene *scene = CCScene::create();
    GameLayer1 *layer = GameLayer1::create();
    scene->addChild(layer);
    return scene;
}

bool GameLayer1::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    
    return true;
}

void GameLayer1::onEnter()
{
    CCLayer::onEnter();
    this->setTouchEnabled(true);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("stoneboard.plist", "stoneboard.png");
    
    CCSprite *bgSprite = CCSprite::createWithSpriteFrameName("chessBoard01.png");
    bgSprite->setPosition(ccp(winSize.width/2, bgSprite->getContentSize().height/2));
    this->addChild(bgSprite);
    m_isClear = true;
    
    initMap();
    initStatus();
    printMap();
}
#pragma mark - game init

void GameLayer1::initMap()
{
    for (int i=0; i<kMapWidth; ++i)
    {
        for (int j=0; j<kMapHeight; ++j)
        {
            int index = arc4random()%6;
            map[i][j] = index;
            Stone *_stone = Stone::createWithIndex(index);
            _stone->setPosition(ccp(i*kStoneWidth+kXOffset, j*kStoneHeight+kYOffset));
            _stone->m_mapX = i;
            _stone->m_mapY = j;
            this->addChild(_stone);
            if (m_stonesArray) {
                m_stonesArray->addObject(_stone);
            }else{
                m_stonesArray = CCArray::create();
                m_stonesArray->retain();
                
                m_stonesArray->addObject(_stone);
            }
        }
    }
}
void GameLayer1::printMap()
{
    CCLog("-----------------------------");
    for (int i=kMapHeight-1; i>=0; --i)
    {        
        CCLog("%d , %d , %d , %d , %d, %d", map[0][i], map[1][i], map[2][i], map[3][i], map[4][i], map[5][i]);
        
    }
}

void GameLayer1::initStatus()
{
    //red----->
    CCSprite *redSprite = CCSprite::createWithSpriteFrameName(kRedFireStoneName);
    redSprite->setScale(0.5);
    redSprite->setPosition(ccp(100, 960-30));
    this->addChild(redSprite, 101);
    
    CCLabelTTF *x3 = CCLabelTTF::create("x3:", "Arial", 32);
    x3->setPosition(ccp(30, 960-64));
    this->addChild(x3, 101);    
    m_red3Time = CCLabelTTF::create("0", "Arial", 32);
    m_red3Time->setPosition(ccp(100, 960-64));
    this->addChild(m_red3Time, 101);
    
    CCLabelTTF *x4 = CCLabelTTF::create("x4:", "Arial", 32);
    x4->setPosition(ccp(30, 960-96));
    this->addChild(x4, 101);
    m_red4Time = CCLabelTTF::create("0", "Arial", 32);
    m_red4Time->setPosition(ccp(100, 960-96));
    this->addChild(m_red4Time, 101);
    
    CCLabelTTF *x5 = CCLabelTTF::create("x5:", "Arial", 32);
    x5->setPosition(ccp(30, 960-128));
    this->addChild(x5, 101);
    m_red5Time = CCLabelTTF::create("0", "Arial", 32);
    m_red5Time->setPosition(ccp(100, 960-128));
    this->addChild(m_red5Time, 101);
    
    CCLabelTTF *x6 = CCLabelTTF::create("x6:", "Arial", 32);
    x6->setPosition(ccp(30, 960-160));
    this->addChild(x6, 101);
    m_red6Time = CCLabelTTF::create("0", "Arial", 32);
    m_red6Time->setPosition(ccp(100, 960-160));
    this->addChild(m_red6Time, 101);
    
    //blue----->
    CCSprite *blueSprite = CCSprite::createWithSpriteFrameName(kBlueStoneName);
    blueSprite->setScale(0.5);
    blueSprite->setPosition(ccp(200, 960-30));
    this->addChild(blueSprite, 101);
    
    m_blue3Time = CCLabelTTF::create("0", "Arial", 32);
    m_blue3Time->setPosition(ccp(200, 960-64));
    this->addChild(m_blue3Time, 101);
    
    m_blue4Time = CCLabelTTF::create("0", "Arial", 32);
    m_blue4Time->setPosition(ccp(200, 960-96));
    this->addChild(m_blue4Time, 101);
    
    m_blue5Time = CCLabelTTF::create("0", "Arial", 32);
    m_blue5Time->setPosition(ccp(200, 960-128));
    this->addChild(m_blue5Time, 101);

    m_blue5Time = CCLabelTTF::create("0", "Arial", 32);
    m_blue5Time->setPosition(ccp(200, 960-160));
    this->addChild(m_blue5Time, 101);
    
    //green----->
    CCSprite *greenSprite = CCSprite::createWithSpriteFrameName(kGreenStoneName);
    greenSprite->setScale(0.5);
    greenSprite->setPosition(ccp(300, 960-30));
    this->addChild(greenSprite, 101);
    
    m_green3Time = CCLabelTTF::create("0", "Arial", 32);
    m_green3Time->setPosition(ccp(300, 960-64));
    this->addChild(m_green3Time, 101);
    
    m_green4Time = CCLabelTTF::create("0", "Arial", 32);
    m_green4Time->setPosition(ccp(300, 960-96));
    this->addChild(m_green4Time, 101);
    
    m_green5Time = CCLabelTTF::create("0", "Arial", 32);
    m_green5Time->setPosition(ccp(300, 960-128));
    this->addChild(m_green5Time, 101);
    
    m_green6Time = CCLabelTTF::create("0", "Arial", 32);
    m_green6Time->setPosition(ccp(300, 960-160));
    this->addChild(m_green6Time, 101);
    
    //yellow----->
    CCSprite *yellowSprite = CCSprite::createWithSpriteFrameName(kYellowStoneName);
    yellowSprite->setScale(0.5);
    yellowSprite->setPosition(ccp(400, 960-30));
    this->addChild(yellowSprite, 101);
    
    m_yellow3Time = CCLabelTTF::create("0", "Arial", 32);
    m_yellow3Time->setPosition(ccp(400, 960-64));
    this->addChild(m_yellow3Time, 101);
    
    m_yellow4Time = CCLabelTTF::create("0", "Arial", 32);
    m_yellow4Time->setPosition(ccp(400, 960-96));
    this->addChild(m_yellow4Time, 101);
    
    m_yellow5Time = CCLabelTTF::create("0", "Arial", 32);
    m_yellow5Time->setPosition(ccp(400, 960-128));
    this->addChild(m_yellow5Time, 101);
    
    m_yellow6Time = CCLabelTTF::create("0", "Arial", 32);
    m_yellow6Time->setPosition(ccp(400, 960-160));
    this->addChild(m_yellow6Time, 101);
    
    //purple----->
    CCSprite *purpleSprite = CCSprite::createWithSpriteFrameName(kPurpleStoneName);
    purpleSprite->setScale(0.5);
    purpleSprite->setPosition(ccp(500, 960-30));
    this->addChild(purpleSprite, 101);
    
    m_purple3Time = CCLabelTTF::create("0", "Arial", 32);
    m_purple3Time->setPosition(ccp(500, 960-64));
    this->addChild(m_purple3Time, 101);
    
    m_purple4Time = CCLabelTTF::create("0", "Arial", 32);
    m_purple4Time->setPosition(ccp(500, 960-96));
    this->addChild(m_purple4Time, 101);
    
    m_purple5Time = CCLabelTTF::create("0", "Arial", 32);
    m_purple5Time->setPosition(ccp(500, 960-128));
    this->addChild(m_purple5Time, 101);
    
    m_purple6Time = CCLabelTTF::create("0", "Arial", 32);
    m_purple6Time->setPosition(ccp(500, 960-160));
    this->addChild(m_purple6Time, 101);
    
    //star----->
    CCSprite *starSprite = CCSprite::createWithSpriteFrameName(kRedHeartStoneName);
    starSprite->setScale(0.5);
    starSprite->setPosition(ccp(600, 960-30));
    this->addChild(starSprite, 101);
    
    m_star3Time = CCLabelTTF::create("0", "Arial", 32);
    m_star3Time->setPosition(ccp(600, 960-64));
    this->addChild(m_star3Time, 101);
    
    m_star4Time = CCLabelTTF::create("0", "Arial", 32);
    m_star4Time->setPosition(ccp(600, 960-96));
    this->addChild(m_star4Time, 101);
    
    m_star5Time = CCLabelTTF::create("0", "Arial", 32);
    m_star5Time->setPosition(ccp(600, 960-128));
    this->addChild(m_star5Time, 101);
    
    m_star6Time = CCLabelTTF::create("0", "Arial", 32);
    m_star6Time->setPosition(ccp(600, 960-160));
    this->addChild(m_star6Time, 101);
    
    m_red3Score = 0;
    m_red4Score = 0;
    m_red5Score = 0;
    m_red6Score = 0;
    
    m_blue3Score = 0;
    m_blue4Score = 0;
    m_blue5Score = 0;
    m_blue6Score = 0;
    
    m_green3Score = 0;
    m_green4Score = 0;
    m_green5Score = 0;
    m_green6Score = 0;
    
    m_yellow3Score = 0;
    m_yellow4Score = 0;
    m_yellow5Score = 0;
    m_yellow6Score = 0;
    
    m_purple3Score = 0;
    m_purple4Score = 0;
    m_purple5Score = 0;
    m_purple6Score = 0;
    
    m_star3Score = 0;
    m_star4Score = 0;
    m_star5Score = 0;
    m_star6Score = 0;

}

#pragma mark - gamelogic

void GameLayer1::checkExchangeStone(cocos2d::CCTime &dt)
{
}

void GameLayer1::scoreAddRed(int index)
{
    char str[8];
    switch (index) {
        case 3:
            m_red3Score++;
            sprintf(str, "%d", m_red3Score);
            m_red3Time->setString(str);
            break;
        case 4:
            m_red4Score++;
            sprintf(str, "%d", m_red4Score);
            m_red4Time->setString(str);
            break;
        case 5:
            m_red5Score++;
            sprintf(str, "%d", m_red5Score);
            m_red5Time->setString(str);
            break;
        case 6:
            m_red6Score++;
            sprintf(str, "%d", m_red6Score);
            m_red6Time->setString(str);
            break;            
        default:
            break;
    }
}

void GameLayer1::scoreAddBlue(int index)
{
    char str[8];
    switch (index) {
        case 3:
            m_blue3Score++;
            sprintf(str, "%d", m_blue3Score);
            m_blue3Time->setString(str);
            break;
        case 4:
            m_blue4Score++;
            sprintf(str, "%d", m_blue4Score);
            m_blue4Time->setString(str);
            break;
        case 5:
            m_blue5Score++;
            sprintf(str, "%d", m_blue5Score);
            m_blue5Time->setString(str);
            break;
        case 6:
            m_blue6Score++;
            sprintf(str, "%d", m_blue6Score);
            m_blue6Time->setString(str);
            break;
        default:
            break;
    }
}

void GameLayer1::scoreAddStar(int index)
{
    char str[8];
    switch (index) {
        case 3:
            m_star3Score++;
            sprintf(str, "%d", m_star3Score);
            m_star3Time->setString(str);
            break;
        case 4:
            m_star4Score++;
            sprintf(str, "%d", m_star4Score);
            m_star4Time->setString(str);
            break;
        case 5:
            m_star5Score++;
            sprintf(str, "%d", m_star5Score);
            m_star5Time->setString(str);
            break;
        case 6:
            m_star6Score++;
            sprintf(str, "%d", m_star6Score);
            m_star6Time->setString(str);
            break;
        default:
            break;
    }
}

void GameLayer1::scoreAddYellow(int index)
{
    char str[8];
    switch (index) {
        case 3:
            m_yellow3Score++;
            sprintf(str, "%d", m_yellow3Score);
            m_yellow3Time->setString(str);
            break;
        case 4:
            m_yellow4Score++;
            sprintf(str, "%d", m_yellow4Score);
            m_yellow4Time->setString(str);
            break;
        case 5:
            m_yellow5Score++;
            sprintf(str, "%d", m_yellow5Score);
            m_yellow5Time->setString(str);
            break;
        case 6:
            m_yellow6Score++;
            sprintf(str, "%d", m_yellow6Score);
            m_yellow6Time->setString(str);
            break;
        default:
            break;
    }
}

void GameLayer1::scoreAddPurple(int index)
{
    char str[8];
    switch (index) {
        case 3:
            m_purple3Score++;
            sprintf(str, "%d", m_purple3Score);
            m_purple3Time->setString(str);
            break;
        case 4:
            m_purple4Score++;
            sprintf(str, "%d", m_purple4Score);
            m_purple4Time->setString(str);
            break;
        case 5:
            m_purple5Score++;
            sprintf(str, "%d", m_purple5Score);
            m_purple5Time->setString(str);
            break;
        case 6:
            m_purple6Score++;
            sprintf(str, "%d", m_purple6Score);
            m_purple6Time->setString(str);
            break;
        default:
            break;
    }
}

void GameLayer1::scoreAddGreen(int index)
{
    char str[8];
    switch (index) {
        case 3:
            m_green3Score++;
            sprintf(str, "%d", m_green3Score);
            m_green3Time->setString(str);
            break;
        case 4:
            m_green4Score++;
            sprintf(str, "%d", m_green4Score);
            m_green4Time->setString(str);
            break;
        case 5:
            m_green5Score++;
            sprintf(str, "%d", m_green5Score);
            m_green5Time->setString(str);
            break;
        case 6:
            m_green6Score++;
            sprintf(str, "%d", m_green6Score);
            m_green6Time->setString(str);
            break;
        default:
            break;
    }
}


void GameLayer1::checkStone(cocos2d::CCTime &dt)
{
    
    if (!allStonesActionDone())
    {
        return;
    }
    
    int x=-1, y=-1;
    int left=0, right=0, up=0, down=0;
    int total = 0;
    
    for (int i=0; i<kMapWidth; ++i)
    {
        for (int j=0; j<kMapHeight; ++j)
        {
            
            left = 0;
            right = 0;
            up = 0;
            down = 0;
            total = 0;
            const int val = map[i][j];
            if (val == -1) {
                m_isClear = false;
                continue;
            }
            x = i;
            y = j;
            while (--x >= 0 && x < kMapWidth && map[x][y] == val) {
                ++left;
            }
            x = i;
            y = j;
            while (++x < kMapWidth && x >= 0 && map[x][y] == val) {
                ++right;
            }
            
            x = i;
            y = j;
            while (--y >= 0 && y < kMapHeight && map[x][y] == val)
            {
                ++down;
            }
            x = i;
            y = j;
            while (++y < kMapHeight && y >= 0 && map[x][y] == val)
            {
                ++up;
            }
            if (left + right>=2) {
                m_isClear = false;
                
                CCLog("left = %d, right = %d, <-----(%d, %d)",left, right, i, j);
                
                Stone *_stone = getStoneWithMapXY(i, j);
                if (_stone)
                {
                    _stone->m_isChecked = true;
                    //map[i][j] = -1;
                }
                total += left + right;
            }
            
            if (total != 0) {
                total++;
                Stone *_stone = getStoneWithMapXY(i, j);
                kStoneType type = _stone->m_type;
                switch (type) {
                    case kRedFireStoneType:
                        scoreAddRed(total);
                        break;
                    case kGreenStoneType:
                        scoreAddGreen(total);
                        break;
                    case kPurpleStoneType:
                        scoreAddPurple(total);
                        break;
                    case kBlueStoneType:
                        scoreAddBlue(total);
                        break;
                    case kYellowStoneType:
                        scoreAddYellow(total);
                        break;
                    case kRedHeartStoneType:
                        scoreAddStar(total);
                        break;
                    case kNoneStoneType:
                        break;
                    default :
                        break;
                }
            }
            total = 0;
            
            if (up + down >= 2)
            {
                m_isClear = false;
                CCLog("up = %d, down = %d, <-----(%d, %d)", up, down, i, j);
                
                Stone *_stone = getStoneWithMapXY(i, j);
                if (_stone)
                {
                    _stone->m_isChecked = true;
                    //map[i][j] = -1;
                }
                total += up + down;
            }
            
            if (total != 0) {
                total++;
                Stone *_stone = getStoneWithMapXY(i, j);
                kStoneType type = _stone->m_type;
                switch (type) {
                    case kRedFireStoneType:
                        scoreAddRed(total);
                        break;
                    case kGreenStoneType:
                        scoreAddGreen(total);
                        break;
                    case kPurpleStoneType:
                        scoreAddPurple(total);
                        break;
                    case kBlueStoneType:
                        scoreAddBlue(total);
                        break;
                    case kYellowStoneType:
                        scoreAddYellow(total);
                        break;
                    case kRedHeartStoneType:
                        scoreAddStar(total);
                        break;
                    case kNoneStoneType:
                        break;
                    default :
                        break;
                }
            }
            
        }
    }
    
    if (!m_isClear) {
        for (int i=0; i<m_stonesArray->count(); ++i) {
            Stone *_stone = dynamic_cast<Stone*>(m_stonesArray->objectAtIndex(i));
            if (_stone->m_isChecked) {
                _stone->m_actionDone=false;
                _stone->runAction(CCSequence::create(CCFadeOut::create(0.1f), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::removeStone))));
            }
        }
        
    }
    //CCLog("*******************************");
    //printMap();
    //CCLog("*******************************");
    
    if (allStonesActionDone())
    {
        this->schedule(schedule_selector(GameLayer1::downStone));
        
    }
    if (m_isClear)
    {
        this->unschedule(schedule_selector(GameLayer1::checkStone));
        this->unschedule(schedule_selector(GameLayer1::downStone));
        if (this->getChildByTag(kTouchDisableLayerTag))
        {
            this->removeChildByTag(kTouchDisableLayerTag, true);
        }
    }
    
    
}

void GameLayer1::downStone(cocos2d::CCTime &dt)
{
    if (!allStonesActionDone())
    {
        return;
    }
    for (int i=0; i<kMapWidth; ++i)
    {
        for (int j=0; j<kMapHeight; ++j)
        {
            if (map[i][j] == -1)
            {
                int x=i, y=j;
                while (++y>=0 && y<kMapHeight)
                {
                    if (map[x][y] != -1 && !getStoneWithMapXY(i, j)) {
                        Stone *_stone = getStoneWithMapXY(x, y);
                        if (_stone)
                        {
                            map[_stone->m_mapX][_stone->m_mapY] = -1;
                            _stone->m_mapX = i;
                            _stone->m_mapY = j;
                            _stone->runAction(CCSequence::create(CCMoveTo::create(0.5f, ccp(i*100+70, j*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneDownDone)), NULL));
                            break;
                        }
                    }
                }
            }
        }
    }
    
    
    for (int i=0; i<kMapWidth; ++i)
    {
        for (int j=0; j<kMapHeight; ++j)
        {
            if (map[i][j] == -1 && !getStoneWithMapXY(i, j))
            {
                //int x=i, y=j;
                
                Stone *_stone = Stone::createWithIndex(arc4random()%6);
                _stone->setPosition(ccp(i*100+70, 960-60));
                _stone->m_mapX = i;
                _stone->m_mapY = j;
                this->addChild(_stone);
                _stone->runAction(CCSequence::create(CCMoveTo::create(0.5f, ccp(i*100+70, j*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneDownDone)), NULL));
                m_stonesArray->addObject(_stone);
            }
        }
    }
    
    
    if (allStonesActionDone())
    {
        this->unschedule(schedule_selector(GameLayer1::downStone));
        m_isClear = true;
        this->schedule(schedule_selector(GameLayer1::checkStone));
        
    }
    
}

void GameLayer1::beganCheckStone(cocos2d::CCTime &dt)
{
    if (allStonesActionDone())
    {
        this->schedule(schedule_selector(GameLayer1::checkStone), 0.2f);
        this->unschedule(schedule_selector(GameLayer1::beganCheckStone));
    }
}
#pragma mark - help
Stone* GameLayer1::getStoneWithMapXY(int x, int y)
{
    for (int i=0; i<m_stonesArray->count(); ++i)
    {
        Stone *_stone = dynamic_cast<Stone*>(m_stonesArray->objectAtIndex(i));
        if (_stone->m_mapX == x && _stone->m_mapY == y) {
            return _stone;
        }
    }
    return NULL;
}

void GameLayer1::removeStone(cocos2d::CCNode *_stone)
{
    Stone *stone = dynamic_cast<Stone*>(_stone);
    stone->m_actionDone = true;
    map[stone->m_mapX][stone->m_mapY] = -1;
    this->removeChild(_stone, true);
    m_stonesArray->removeObject(_stone);
}

void GameLayer1::stoneActionDone(CCNode *_stone)
{
    Stone *__stone =  dynamic_cast<Stone*>(_stone);
    __stone->m_actionDone = true;
}
void GameLayer1::stoneDownDone(cocos2d::CCNode *_stone)
{
    Stone *__stone =  dynamic_cast<Stone*>(_stone);
    map[__stone->m_mapX][__stone->m_mapY] = __stone->val;
    __stone->m_actionDone = true;
}
bool GameLayer1::allStonesActionDone()
{
    for (int i=0; i<m_stonesArray->count(); ++i) {
        Stone *_stone = dynamic_cast<Stone*>(m_stonesArray->objectAtIndex(i));
        if (!_stone->m_actionDone) {
            return false;
        }
    }
    return true;
}

#pragma mark - registerWithTouchDispatcher

void GameLayer1::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}

#pragma mark - touch delegate methods

bool GameLayer1::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint touchLoc = pTouch->getLocationInView();
    touchLoc = CCDirector::sharedDirector()->convertToGL(touchLoc);
    
    CCPoint mapLoc = convertToMap(touchLoc);
    
    CCLog("%f, %f", mapLoc.x, mapLoc.y);
    
    //get The stone
    m_movingStone = getStoneWithMapXY(mapLoc.x, mapLoc.y);
    if (!m_movingStone)
    {
        return false;
    }
    m_movingStone->setPosition(touchLoc);
    m_movingStone->m_actionDone = false;
    this->reorderChild(m_movingStone, 99);
    CCLog("----began-->");
    
    return true;
}
void GameLayer1::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
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
    
    if (mapLoc.x!=m_movingStone->m_mapX || mapLoc.y!=m_movingStone->m_mapY)
    {
        if (mapLoc.x-m_movingStone->m_mapX==1) //向右
        {
            m_changingStone = getStoneWithMapXY(m_movingStone->m_mapX+1, m_movingStone->m_mapY);
            if (!m_changingStone) {
                return;
            }
            m_changingStone->m_mapX = m_movingStone->m_mapX;
            //m_changingStone->m_mapY = m_movingStone->m_mapY;
            m_changingStone->m_actionDone = false;
            m_changingStone->runAction(CCSequence::create(CCMoveTo::create(0.1f, ccp(m_movingStone->m_mapX*100+70, m_movingStone->m_mapY*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneActionDone))));
            m_movingStone->m_mapX = mapLoc.x;
            //m_movingStone->m_mapY = m_movingStone->m_mapY;
            
            map[m_changingStone->m_mapX][m_changingStone->m_mapY] = m_changingStone->val;
            map[m_movingStone->m_mapX][m_movingStone->m_mapY] = m_movingStone->val;


        }
        else if(mapLoc.x-m_movingStone->m_mapX==-1) //向左
        {
            m_changingStone = getStoneWithMapXY(m_movingStone->m_mapX-1, m_movingStone->m_mapY);
            if (!m_changingStone) {
                return;
            }
            m_changingStone->m_mapX = m_movingStone->m_mapX;
            //m_changingStone->m_mapY = m_movingStone->m_mapY;
            m_changingStone->m_actionDone = false;
            m_changingStone->runAction(CCSequence::create(CCMoveTo::create(0.1f, ccp(m_movingStone->m_mapX*100+70, m_movingStone->m_mapY*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneActionDone))));
            m_movingStone->m_mapX = mapLoc.x;
            //m_movingStone->m_mapY = m_movingStone->m_mapY;
            
            map[m_changingStone->m_mapX][m_changingStone->m_mapY] = m_changingStone->val;
            map[m_movingStone->m_mapX][m_movingStone->m_mapY] = m_movingStone->val;

        }
        
                
        if (mapLoc.y-m_movingStone->m_mapY==1) //向上
        {
            m_changingStone = getStoneWithMapXY(m_movingStone->m_mapX, m_movingStone->m_mapY+1);
            if (!m_changingStone) {
                return;
            }
            //m_changingStone->m_mapX = m_movingStone->m_mapX;
            m_changingStone->m_mapY = m_movingStone->m_mapY;
            m_changingStone->m_actionDone = false;
            m_changingStone->runAction(CCSequence::create(CCMoveTo::create(0.1f, ccp(m_movingStone->m_mapX*100+70, m_movingStone->m_mapY*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneActionDone))));
            //m_movingStone->m_mapX = m_movingStone->m_mapX;
            m_movingStone->m_mapY = mapLoc.y;
            
            map[m_changingStone->m_mapX][m_changingStone->m_mapY] = m_changingStone->val;
            map[m_movingStone->m_mapX][m_movingStone->m_mapY] = m_movingStone->val;
            
        }
        else if(mapLoc.y-m_movingStone->m_mapY==-1) //向上
        {
            m_changingStone = getStoneWithMapXY(m_movingStone->m_mapX, m_movingStone->m_mapY-1);
            if (!m_changingStone) {
                return;
            }
            //m_changingStone->m_mapX = m_movingStone->m_mapX;
            m_changingStone->m_mapY = m_movingStone->m_mapY;
            m_changingStone->m_actionDone = false;
            m_changingStone->runAction(CCSequence::create(CCMoveTo::create(0.1f, ccp(m_movingStone->m_mapX*100+70, m_movingStone->m_mapY*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneActionDone))));
            //m_movingStone->m_mapX = m_movingStone->m_mapX;
            m_movingStone->m_mapY = mapLoc.y;
            
            map[m_changingStone->m_mapX][m_changingStone->m_mapY] = m_changingStone->val;
            map[m_movingStone->m_mapX][m_movingStone->m_mapY] = m_movingStone->val;
            
        }
        
    }
    //CCLog("----moved-->");
    
        
}
void GameLayer1::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
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
    
    
    
    if (mapLoc.x!=m_movingStone->m_mapX || mapLoc.y!=m_movingStone->m_mapY)
    {
        if (mapLoc.x-m_movingStone->m_mapX==1) //向右
        {
            m_changingStone = getStoneWithMapXY(m_movingStone->m_mapX+1, m_movingStone->m_mapY);
            if (!m_changingStone) {
                return;
            }
            m_changingStone->m_mapX = m_movingStone->m_mapX;
            //m_changingStone->m_mapY = m_movingStone->m_mapY;
            m_changingStone->m_actionDone = false;
            m_changingStone->runAction(CCSequence::create(CCMoveTo::create(0.1f, ccp(m_movingStone->m_mapX*100+70, m_movingStone->m_mapY*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneActionDone))));
            m_movingStone->m_mapX = mapLoc.x;
            //m_movingStone->m_mapY = m_movingStone->m_mapY;
            
            map[m_changingStone->m_mapX][m_changingStone->m_mapY] = m_changingStone->val;
            map[m_movingStone->m_mapX][m_movingStone->m_mapY] = m_movingStone->val;
            
            
        }
        else if(mapLoc.x-m_movingStone->m_mapX==-1) //向左
        {
            m_changingStone = getStoneWithMapXY(m_movingStone->m_mapX-1, m_movingStone->m_mapY);
            if (!m_changingStone) {
                return;
            }
            m_changingStone->m_mapX = m_movingStone->m_mapX;
            //m_changingStone->m_mapY = m_movingStone->m_mapY;
            m_changingStone->m_actionDone = false;
            m_changingStone->runAction(CCSequence::create(CCMoveTo::create(0.1f, ccp(m_movingStone->m_mapX*100+70, m_movingStone->m_mapY*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneActionDone))));
            m_movingStone->m_mapX = mapLoc.x;
            //m_movingStone->m_mapY = m_movingStone->m_mapY;
            
            map[m_changingStone->m_mapX][m_changingStone->m_mapY] = m_changingStone->val;
            map[m_movingStone->m_mapX][m_movingStone->m_mapY] = m_movingStone->val;
            
        }
        
        
        if (mapLoc.y-m_movingStone->m_mapY==1) //向上
        {
            m_changingStone = getStoneWithMapXY(m_movingStone->m_mapX, m_movingStone->m_mapY+1);
            if (!m_changingStone) {
                return;
            }
            //m_changingStone->m_mapX = m_movingStone->m_mapX;
            m_changingStone->m_mapY = m_movingStone->m_mapY;
            m_changingStone->m_actionDone = false;
            m_changingStone->runAction(CCSequence::create(CCMoveTo::create(0.1f, ccp(m_movingStone->m_mapX*100+70, m_movingStone->m_mapY*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneActionDone))));
            //m_movingStone->m_mapX = m_movingStone->m_mapX;
            m_movingStone->m_mapY = mapLoc.y;
            
            map[m_changingStone->m_mapX][m_changingStone->m_mapY] = m_changingStone->val;
            map[m_movingStone->m_mapX][m_movingStone->m_mapY] = m_movingStone->val;
            
        }
        else if(mapLoc.y-m_movingStone->m_mapY==-1) //向上
        {
            m_changingStone = getStoneWithMapXY(m_movingStone->m_mapX, m_movingStone->m_mapY-1);
            if (!m_changingStone) {
                return;
            }
            //m_changingStone->m_mapX = m_movingStone->m_mapX;
            m_changingStone->m_mapY = m_movingStone->m_mapY;
            //m_changingStone->runAction(CCMoveTo::create(0.1f, ccp(m_movingStone->m_mapX*100+70, m_movingStone->m_mapY*100+60)));
            m_changingStone->m_actionDone = false;
            m_changingStone->runAction(CCSequence::create(CCMoveTo::create(0.1f, ccp(m_movingStone->m_mapX*100+70, m_movingStone->m_mapY*100+60)), CCCallFuncN::create(this, callfuncN_selector(GameLayer1::stoneActionDone))));
            //m_movingStone->m_mapX = m_movingStone->m_mapX;
            m_movingStone->m_mapY = mapLoc.y;
            
            map[m_changingStone->m_mapX][m_changingStone->m_mapY] = m_changingStone->val;
            map[m_movingStone->m_mapX][m_movingStone->m_mapY] = m_movingStone->val;
            
        }
        
    }
    //m_movingStone->m_mapX = mapLoc.x;
    //m_movingStone->m_mapY = mapLoc.y;
    m_movingStone->setPosition(ccp(mapLoc.x*100+70, mapLoc.y*100+60));
    this->reorderChild(m_movingStone, 1);
    m_movingStone->m_actionDone = true;
    printMap();
    
    m_isClear = true;
    this->schedule(schedule_selector(GameLayer1::beganCheckStone));
    
    CCLog("----ended-->");
    
    //this->setTouchEnabled(false);
    if (!this->getChildByTag(kTouchDisableLayerTag)) {
        TouchDisableLayer *touchDisableLayer = TouchDisableLayer::create(ccc4(0, 0 ,0, 100), 640, 960);
        this->addChild(touchDisableLayer, 100, kTouchDisableLayerTag);
    }    
}
void GameLayer1::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCLog("----cancelled-->");
}

#pragma mark - uitl methods

CCPoint GameLayer1::convertToMap(CCPoint &glPoint)
{
    return CCPointMake(static_cast<int>(glPoint.x-20)/kStoneWidth, static_cast<int>(glPoint.y)/kStoneHeight);
}
CCPoint GameLayer1::convertToGLView(cocos2d::CCPoint &mapPoint)
{
    return CCPointMake((mapPoint.x*kStoneWidth)+20, mapPoint.y*kStoneHeight);
}

#pragma mark - dealloc

GameLayer1::~GameLayer1()
{
    m_stonesArray->release();
    m_stonesArray = NULL;
    m_movingStone = NULL;
    m_changingStone = NULL;
}
