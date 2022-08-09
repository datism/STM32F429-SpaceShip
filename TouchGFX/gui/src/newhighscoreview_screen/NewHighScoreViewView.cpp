#include <gui/newhighscoreview_screen/NewHighScoreViewView.hpp>

NewHighScoreViewView::NewHighScoreViewView()
{
	keyboard.setPosition(8, 70, 224, 232);
	add(keyboard);
}

void NewHighScoreViewView::setupScreen()
{
    NewHighScoreViewViewBase::setupScreen();
}

void NewHighScoreViewView::tearDownScreen()
{
    NewHighScoreViewViewBase::tearDownScreen();
}
