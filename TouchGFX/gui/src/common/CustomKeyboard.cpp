#include <gui/common/CustomKeyboard.hpp>
#include <string.h>

CustomKeyboard::CustomKeyboard() : keyboard(),
    backspacePressed(this, &CustomKeyboard::backspacePressedHandler)
{
    layout.callbackAreaArray[0].callback = &backspacePressed;

    keyboard.setLayout(&layout);
    keyboard.setPosition(0, 0, 224, 232);
    keyboard.setTextIndentation();

    //Allocate the buffer associated with keyboard.
    memset(buffer, 0, sizeof(buffer));
    keyboard.setBuffer(buffer, BUFFER_SIZE);

    setKeyMappingList();
    add(keyboard);
}

void CustomKeyboard::setKeyMappingList()
{
  
    keyboard.setKeymappingList(&keyMappingListAlphaLower);
}

void CustomKeyboard::backspacePressedHandler()
{
    uint16_t pos = keyboard.getBufferPosition();
    if (pos > 0) {
        //Delete the previous entry in the buffer and decrement the position.
        buffer[pos - 1] = 0;
        keyboard.setBufferPosition(pos - 1);
    }
}

void CustomKeyboard::setTouchable(bool touch)
{
    Container::setTouchable(touch);
    keyboard.setTouchable(touch);
}
