#include <gui/Main_screen/MainView.hpp>
#include <gui/Main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::updatePoint(uint32_t p) {
	model->updatePoint(p);
}

void MainPresenter::getPoints(uint32_t points[5]) {
	model->getPoints(points);
}
