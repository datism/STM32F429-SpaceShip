#include <gui/newhighscore_screen/NewHighScoreView.hpp>
#include <gui/newhighscore_screen/NewHighScorePresenter.hpp>

NewHighScorePresenter::NewHighScorePresenter(NewHighScoreView& v)
    : view(v)
{

}

void NewHighScorePresenter::activate()
{

}

void NewHighScorePresenter::deactivate()
{

}

void NewHighScorePresenter::updateName(touchgfx::Unicode::UnicodeChar n[6]) {
	model->updateName(n);
}

void NewHighScorePresenter::saveHighScore() {
	model->saveHighScore();
}
