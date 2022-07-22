/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SHIPBASE_HPP
#define SHIPBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/AnimatedImage.hpp>

class ShipBase : public touchgfx::Container
{
public:
    ShipBase();
    virtual ~ShipBase();
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

#endif // SHIPBASE_HPP
