#ifndef SHIP_HPP
#define SHIP_HPP

#include <gui_generated/containers/ShipBase.hpp>

class Ship : public ShipBase
{
public:
    Ship();
    virtual ~Ship() {}
    virtual void initialize();
    virtual void handleTickEvent();
protected:
    int16_t localX;
    int16_t localY;
};

#endif // SHIP_HPP
