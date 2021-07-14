#ifndef TETRISCONTROLLER_H
#define TETRISCONTROLLER_H
#include <stdlib.h>
#include <wizio.h>
#include "playGrid.h"



enum input{
    in_down, in_right, in_left, in_rot, in_hold, in_pause
};

class TetrisController {
public:
    TetrisController(int downButton, int rightButton, int leftButton, int rotButton, int holdButton, int pauseButton);
    void initPins();
    int whichPressed();
    int downButton, rightButton, leftButton, rotButton, holdButton, pauseButton;
private:
    uint32_t inputPinsMask;
};
#endif //TETRISCONTROLLER_H