#include <gui/newhighscore_screen/NewHighScoreView.hpp>

NewHighScoreView::NewHighScoreView()
{
	keyboard.setPosition(8, 70, 224, 232);
	add(keyboard);

	remove(enterButton);
	add(enterButton);
}

void NewHighScoreView::setupScreen()
{
    NewHighScoreViewBase::setupScreen();
}

void NewHighScoreView::tearDownScreen()
{
    NewHighScoreViewBase::tearDownScreen();
}


void NewHighScoreView::enterPressedHandle() {
	if (Unicode::strlen(keyboard.getBuffer()) == 0)
		return;

	presenter->updateName(keyboard.getBuffer());
	presenter->saveHighScore();

	application().gotoLeaderboardScreenNoTransition();
}
