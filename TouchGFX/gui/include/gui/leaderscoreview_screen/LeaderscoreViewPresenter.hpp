#ifndef LEADERSCOREVIEWPRESENTER_HPP
#define LEADERSCOREVIEWPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LeaderscoreViewView;

class LeaderscoreViewPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LeaderscoreViewPresenter(LeaderscoreViewView& v);

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

    virtual ~LeaderscoreViewPresenter() {};

private:
    LeaderscoreViewPresenter();

    LeaderscoreViewView& view;
};

#endif // LEADERSCOREVIEWPRESENTER_HPP
