/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LEADERBOARDVIEWBASE_HPP
#define LEADERBOARDVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/leaderboard_screen/LeaderboardPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/AnimatedImage.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

class LeaderboardViewBase : public touchgfx::View<LeaderboardPresenter>
{
public:
    LeaderboardViewBase();
    virtual ~LeaderboardViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::AnimatedImage space;
    touchgfx::TextArea header;
    touchgfx::TextArea pos1;
    touchgfx::TextArea pos2;
    touchgfx::TextArea pos3;
    touchgfx::TextArea pos4;
    touchgfx::TextArea pos5;
    touchgfx::TextAreaWithOneWildcard name0;
    touchgfx::ButtonWithLabel backButton;
    touchgfx::TextAreaWithOneWildcard point0;
    touchgfx::TextAreaWithOneWildcard name1;
    touchgfx::TextAreaWithOneWildcard point1;
    touchgfx::TextAreaWithOneWildcard point2;
    touchgfx::TextAreaWithOneWildcard name2;
    touchgfx::TextAreaWithOneWildcard point4;
    touchgfx::TextAreaWithOneWildcard name4;
    touchgfx::TextAreaWithOneWildcard point3;
    touchgfx::TextAreaWithOneWildcard name3;

    /*
     * Wildcard Buffers
     */
    static const uint16_t NAME0_SIZE = 10;
    touchgfx::Unicode::UnicodeChar name0Buffer[NAME0_SIZE];
    static const uint16_t POINT0_SIZE = 10;
    touchgfx::Unicode::UnicodeChar point0Buffer[POINT0_SIZE];
    static const uint16_t NAME1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar name1Buffer[NAME1_SIZE];
    static const uint16_t POINT1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar point1Buffer[POINT1_SIZE];
    static const uint16_t POINT2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar point2Buffer[POINT2_SIZE];
    static const uint16_t NAME2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar name2Buffer[NAME2_SIZE];
    static const uint16_t POINT4_SIZE = 10;
    touchgfx::Unicode::UnicodeChar point4Buffer[POINT4_SIZE];
    static const uint16_t NAME4_SIZE = 10;
    touchgfx::Unicode::UnicodeChar name4Buffer[NAME4_SIZE];
    static const uint16_t POINT3_SIZE = 10;
    touchgfx::Unicode::UnicodeChar point3Buffer[POINT3_SIZE];
    static const uint16_t NAME3_SIZE = 10;
    touchgfx::Unicode::UnicodeChar name3Buffer[NAME3_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<LeaderboardViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // LEADERBOARDVIEWBASE_HPP
