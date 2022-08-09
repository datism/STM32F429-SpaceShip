#ifndef LEADERSCOREVIEWVIEW_HPP
#define LEADERSCOREVIEWVIEW_HPP

#include <gui_generated/leaderscoreview_screen/LeaderscoreViewViewBase.hpp>
#include <gui/leaderscoreview_screen/LeaderscoreViewPresenter.hpp>

class LeaderscoreViewView : public LeaderscoreViewViewBase
{
public:
    LeaderscoreViewView();
    virtual ~LeaderscoreViewView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LEADERSCOREVIEWVIEW_HPP
