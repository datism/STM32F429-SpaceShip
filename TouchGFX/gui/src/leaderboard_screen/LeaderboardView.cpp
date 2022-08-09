#include <gui/leaderboard_screen/LeaderboardView.hpp>

LeaderboardView::LeaderboardView()
{

}

void LeaderboardView::setupScreen()
{
    LeaderboardViewBase::setupScreen();

    Unicode::UnicodeChar names[5][6];
	uint32_t points[5];

	presenter->getHighScore(names, points);

	if (Unicode::strlen(names[0]) != 0) {
		Unicode::strncpy(name0Buffer, names[0], sizeof(names[0]));
		Unicode::snprintf(point0Buffer, NAME0_SIZE, "%d", points[0]);
	}

	if (Unicode::strlen(names[1]) != 0) {
		Unicode::strncpy(name1Buffer, names[1], sizeof(names[1]));
		Unicode::snprintf(point1Buffer, NAME0_SIZE, "%d", points[1]);
	}

	if (Unicode::strlen(names[2]) != 0) {
		Unicode::strncpy(name2Buffer, names[2], sizeof(names[2]));
		Unicode::snprintf(point2Buffer, NAME0_SIZE, "%d", points[2]);
	}

	if (Unicode::strlen(names[3]) != 0) {
		Unicode::strncpy(name3Buffer, names[3], sizeof(names[3]));
		Unicode::snprintf(point3Buffer, NAME0_SIZE, "%d", points[3]);
	}

	if (Unicode::strlen(names[4]) != 0) {
		Unicode::strncpy(name4Buffer, names[4], sizeof(names[4]));
		Unicode::snprintf(point4Buffer, NAME0_SIZE, "%d", points[4]);
	}

}

void LeaderboardView::tearDownScreen()
{
    LeaderboardViewBase::tearDownScreen();
}
