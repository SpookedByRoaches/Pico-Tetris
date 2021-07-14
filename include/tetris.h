#ifndef TETRIS_H
#define TETRIS_H

#include "playGrid.h"
#include "tetrimino.h"
#include "tetrisController.h"

#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

#define ADC_SEED 25



enum MovementDirection{
    left = -1, 
    down = 0,
    right = 1
};

class Tetris{
public:
    Tetris();
    void startGame();

    void placeTetrimino(shape type);

    void rotateTetrimino();
    void moveTetrimino(enum MovementDirection direction);
    void drawTetrimino(int color, Tetrimino *drawTarget);
    void generateTetrimino();
    void setButtons(int downButton, int rightButton, int leftButton, int rotButton, int holdButton, int pauseButton);
    void pollInput();

    Tetrimino *piece;

private:
    int numTetriminos;
    uint64_t tickPeriodMicros;
    shape nextShape;
    playGrid *grid;
    TetrisController *controller;
};

#endif //TETRIS_H