#include <gui/leaderboard_screen/LeaderboardView.hpp>
#include <gui/leaderboard_screen/LeaderboardPresenter.hpp>

LeaderboardPresenter::LeaderboardPresenter(LeaderboardView& v)
    : view(v)
{

}

void LeaderboardPresenter::activate()
{

}

void LeaderboardPresenter::deactivate()
{

}

void LeaderboardPresenter::getHighScore(touchgfx::Unicode::UnicodeChar names[5][6], uint32_t points[5]) {
	model->getHighScore(names, points);
}
