#ifndef SHIP_HPP
#define SHIP_HPP

#include <gui_generated/containers/ShipBase.hpp>

class Ship : public ShipBase
{
public:
	enum State {
		ALIVE,
		DEAD
	};

    Ship();
    virtual ~Ship() {}
    virtual void initialize();
    virtual void handleTickEvent();

    void retreat();
    void setState(State state);
    State getState();
//    Rect getBodyArea();
protected:
    uint32_t tickCounter;
    State state;

    void reset();
};

#endif // SHIP_HPP
