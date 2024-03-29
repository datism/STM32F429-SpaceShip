/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef NEWHIGHSCOREVIEWBASE_HPP
#define NEWHIGHSCOREVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/newhighscore_screen/NewHighScorePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/AnimatedImage.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>

class NewHighScoreViewBase : public touchgfx::View<NewHighScorePresenter>
{
public:
    NewHighScoreViewBase();
    virtual ~NewHighScoreViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void enterPressedHandle()
    {
        // Override and implement this function in NewHighScore
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::AnimatedImage space;
    touchgfx::TextArea textArea1;
    touchgfx::Button enterButton;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<NewHighScoreViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // NEWHIGHSCOREVIEWBASE_HPP
