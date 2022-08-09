#ifndef KEYBOARD_LAYOUT
#define KEYBOARD_LAYOUT

#include <touchgfx/widgets/Keyboard.hpp>
#include <touchgfx/hal/Types.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include "BitmapDatabase.hpp"

using namespace touchgfx;

/**
 * Array specifying the keys used in the CustomKeyboard.
 */
static const Keyboard::Key keyArray[35] =
{
    { 1, Rect(32 * 0, 46, 32, 20), BITMAP_KEYPRESSED_ID},
    { 2, Rect(32 * 1, 46, 32, 20), BITMAP_KEYPRESSED_ID},
    { 3, Rect(32 * 2, 46, 32, 20), BITMAP_KEYPRESSED_ID},
    { 4, Rect(32 * 3, 46, 32, 20), BITMAP_KEYPRESSED_ID},
    { 5, Rect(32 * 4, 46, 32, 20), BITMAP_KEYPRESSED_ID},
    { 6, Rect(32 * 5, 46, 32, 20), BITMAP_KEYPRESSED_ID},
    { 7, Rect(32 * 6, 46, 32, 20), BITMAP_KEYPRESSED_ID},


    { 8, Rect(32 * 0, 78, 32, 20), BITMAP_KEYPRESSED_ID},
    { 9, Rect(32 * 1, 78, 32, 20), BITMAP_KEYPRESSED_ID},
    {10, Rect(32 * 2, 78, 32, 20), BITMAP_KEYPRESSED_ID},
    {11, Rect(32 * 3, 78, 32, 20), BITMAP_KEYPRESSED_ID},
    {12, Rect(32 * 4, 78, 32, 20), BITMAP_KEYPRESSED_ID},
    {13, Rect(32 * 5, 78, 32, 20), BITMAP_KEYPRESSED_ID},
    {14, Rect(32 * 6, 78, 32, 20), BITMAP_KEYPRESSED_ID},

    {15, Rect(32 * 0, 110, 32, 20), BITMAP_KEYPRESSED_ID},
    {16, Rect(32 * 1, 110, 32, 20), BITMAP_KEYPRESSED_ID},
    {17, Rect(32 * 2, 110, 32, 20), BITMAP_KEYPRESSED_ID},
    {18, Rect(32 * 3, 110, 32, 20), BITMAP_KEYPRESSED_ID},
    {19, Rect(32 * 4, 110, 32, 20), BITMAP_KEYPRESSED_ID},
    {20, Rect(32 * 5, 110, 32, 20), BITMAP_KEYPRESSED_ID},
    {21, Rect(32 * 6, 110, 32, 20), BITMAP_KEYPRESSED_ID},

    {22, Rect(32 * 0, 142, 32, 20), BITMAP_KEYPRESSED_ID},
    {23, Rect(32 * 1, 142, 32, 20), BITMAP_KEYPRESSED_ID},
    {24, Rect(32 * 2, 142, 32, 20), BITMAP_KEYPRESSED_ID},
    {25, Rect(32 * 3, 142, 32, 20), BITMAP_KEYPRESSED_ID},
    {26, Rect(32 * 4, 142, 32, 20), BITMAP_KEYPRESSED_ID},
    {27, Rect(32 * 5, 142, 32, 20), BITMAP_KEYPRESSED_ID},
    {28, Rect(32 * 6, 142, 32, 20), BITMAP_KEYPRESSED_ID},

    {29, Rect(32 * 0, 174, 32, 20), BITMAP_KEYPRESSED_ID},
    {30, Rect(32 * 1, 174, 32, 20), BITMAP_KEYPRESSED_ID},
    {31, Rect(32 * 2, 174, 32, 20), BITMAP_KEYPRESSED_ID},
    {32, Rect(32 * 3, 174, 32, 20), BITMAP_KEYPRESSED_ID},
    {33, Rect(32 * 4, 174, 32, 20), BITMAP_KEYPRESSED_ID},
    {34, Rect(32 * 5, 174, 32, 20), BITMAP_KEYPRESSED_ID},
    {35, Rect(32 * 6, 174, 32, 20), BITMAP_KEYPRESSED_ID}
};

/**
 * Callback areas for the special buttons on the CustomKeyboard.
 */
static Keyboard::CallbackArea callbackAreas[2] =
{
    {Rect(128, 206, 48, 26), 0, BITMAP_CONTROLKEYPRESSED_ID},   //enter
    {Rect(176, 206, 48, 26), 0, BITMAP_CONTROLKEYPRESSED_ID}    //delete
};

/**
 * The layout for the CustomKeyboard.
 */
static const Keyboard::Layout layout =
{
	BITMAP_KEYBOARDLAYOUT_ID,
    keyArray,
    35,
    callbackAreas,
    2,
    Rect(70, 7, 85, 15),
    TypedText(T_ENTEREDTEXT),
    0xFFFFFF,
    Typography::NORMAL,
    0xFFFFFF
};

#endif
