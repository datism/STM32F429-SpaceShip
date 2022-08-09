#ifndef LEADERBOARDVIEW_HPP
#define LEADERBOARDVIEW_HPP

#include <gui_generated/leaderboard_screen/LeaderboardViewBase.hpp>
#include <gui/leaderboard_screen/LeaderboardPresenter.hpp>

class LeaderboardView : public LeaderboardViewBase
{
public:
    LeaderboardView();
    virtual ~LeaderboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LEADERBOARDVIEW_HPP
