/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ENEMY0BASE_HPP
#define ENEMY0BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/AnimatedImage.hpp>

class Enemy0Base : public touchgfx::Container
{
public:
    Enemy0Base();
    virtual ~Enemy0Base();
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::AnimatedImage animatedImage;

private:

};

#endif // ENEMY0BASE_HPP