#ifndef LEADERBOARDPRESENTER_HPP
#define LEADERBOARDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LeaderboardView;

class LeaderboardPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LeaderboardPresenter(LeaderboardView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~LeaderboardPresenter() {};

    void getHighScore(touchgfx::Unicode::UnicodeChar names[5][6], uint32_t points[5]);
private:
    LeaderboardPresenter();

    LeaderboardView& view;
};

#endif // LEADERBOARDPRESENTER_HPP
