//
//  GameLayer1.h
//  Diamond
//
//  Created by ManYou on 12-9-29.
//
//

#ifndef Diamond_GameLayer1_h
#define Diamond_GameLayer1_h

#include "cocos2d.h"
#include "Resources.h"

class Stone;
class GameLayer1 : public cocos2d::CCLayer
{
public:
    
    ~GameLayer1();
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameLayer1);
    
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
    void initStatus();
    void checkExchangeStone(cocos2d::CCTime &dt);
    void checkStone(cocos2d::CCTime &dt);
    void downStone(cocos2d::CCTime &dt);
    void beganCheckStone(cocos2d::CCTime &dt);
    
    void scoreAddRed(int index);
    void scoreAddBlue(int index);
    void scoreAddYellow(int index);
    void scoreAddPurple(int index);
    void scoreAddGreen(int index);
    void scoreAddStar(int index);
    
    Stone* getStoneWithMapXY(int x, int y);
    
    void removeStone(cocos2d::CCNode *_stone);
    void stoneActionDone(cocos2d:: CCNode *_stone);
    void stoneDownDone(cocos2d::CCNode *_stone);
    
    bool allStonesActionDone();
private:
    int map[kMapWidth][kMapHeight];
    Stone *m_movingStone;
    Stone *m_changingStone;
    cocos2d::CCArray *m_stonesArray;
    
    cocos2d::CCLabelTTF *m_red3Time;
    cocos2d::CCLabelTTF *m_red4Time;
    cocos2d::CCLabelTTF *m_red5Time;
    cocos2d::CCLabelTTF *m_red6Time;
    
    cocos2d::CCLabelTTF *m_blue3Time;
    cocos2d::CCLabelTTF *m_blue4Time;
    cocos2d::CCLabelTTF *m_blue5Time;
    cocos2d::CCLabelTTF *m_blue6Time;
    
    cocos2d::CCLabelTTF *m_green3Time;
    cocos2d::CCLabelTTF *m_green4Time;
    cocos2d::CCLabelTTF *m_green5Time;
    cocos2d::CCLabelTTF *m_green6Time;
    
    cocos2d::CCLabelTTF *m_yellow3Time;
    cocos2d::CCLabelTTF *m_yellow4Time;
    cocos2d::CCLabelTTF *m_yellow5Time;
    cocos2d::CCLabelTTF *m_yellow6Time;
    
    cocos2d::CCLabelTTF *m_purple3Time;
    cocos2d::CCLabelTTF *m_purple4Time;
    cocos2d::CCLabelTTF *m_purple5Time;
    cocos2d::CCLabelTTF *m_purple6Time;
    
    cocos2d::CCLabelTTF *m_star3Time;
    cocos2d::CCLabelTTF *m_star4Time;
    cocos2d::CCLabelTTF *m_star5Time;
    cocos2d::CCLabelTTF *m_star6Time;
    
    int m_red3Score;
    int m_red4Score;
    int m_red5Score;
    int m_red6Score;
    
    int m_blue3Score;
    int m_blue4Score;
    int m_blue5Score;
    int m_blue6Score;
    
    int m_green3Score;
    int m_green4Score;
    int m_green5Score;
    int m_green6Score;
    
    int m_yellow3Score;
    int m_yellow4Score;
    int m_yellow5Score;
    int m_yellow6Score;
    
    int m_purple3Score;
    int m_purple4Score;
    int m_purple5Score;
    int m_purple6Score;
    
    int m_star3Score;
    int m_star4Score;
    int m_star5Score;
    int m_star6Score;
    
    bool m_isClear;
};

#endif
