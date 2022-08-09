#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/Unicode.hpp>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void saveHighScore();
    void getNames(touchgfx::Unicode::UnicodeChar names[5][6]);
    void getPoints(uint32_t points[5]);
    void getHighScore(touchgfx::Unicode::UnicodeChar names[5][6], uint32_t points[5]);

    void updateName(touchgfx::Unicode::UnicodeChar n[6]);
    void updatePoint(uint32_t p);

protected:
    ModelListener* modelListener;
    touchgfx::Unicode::UnicodeChar name[6];
    uint32_t point;
};

#endif // MODEL_HPP
