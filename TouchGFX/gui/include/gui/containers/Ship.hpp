#ifndef SHIP_HPP
#define SHIP_HPP

#include <gui_generated/containers/ShipBase.hpp>

class Ship : public ShipBase
{
public:
	enum State {
		OOB,
		ALIVE,
		IMMUNE,
		DEAD
	};

    Ship();
    virtual ~Ship() {}
    virtual void initialize();
    virtual void handleTickEvent();

    void setState(State state);
    State getState();

    uint8_t getLives();
protected:
    uint32_t tickCounter;
    State state;
    uint8_t lives;

    //Reset ship to default state
    void reset();
};

#endif // SHIP_HPP
