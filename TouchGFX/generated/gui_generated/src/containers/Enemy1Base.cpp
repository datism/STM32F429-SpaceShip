/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/Enemy1Base.hpp>
#include <BitmapDatabase.hpp>

Enemy1Base::Enemy1Base() :
    fireBulletTriggerCallback(0)
{
    setWidth(29);
    setHeight(28);
    animatedImage.setXY(0, 0);
    animatedImage.setBitmaps(BITMAP_ENEMY1_ID, BITMAP_ENEMY1_ID);
    animatedImage.setUpdateTicksInterval(1);

    add(animatedImage);
}

Enemy1Base::~Enemy1Base()
{

}

void Enemy1Base::initialize()
{

}
