/*
 *          PLAYGRID CLASS TO HELP DRAWING THE TETRIMINOS

 * playGrid class is going to be the canvas of the tetris game
 * 
 * The goal it to have a fixed number of squares in which to draw the 
 * squares of the tetriminos
 * 
 * The canvas itself would have the exact number of available squares
 * given the number of pixels on the screen and the desired side length of
 * the squares
 * 
 * The canvas would also keep track of the number of squares and which 
 * square is available and which is not
 * 
 * The point is to give the game the tools to effeciently draw and erase 
 * the tetriminos without bothering the screen too much
//  */


#ifndef PLAYGRID_H
#define PLAYGRID_H
#include "HX8357_interface.h"
#include "wizio.h"

#define bitsInByte 8

#define RD_PIN 11
#define RST_PIN 10
#define CS_PIN 12
#define WR_PIN 27
#define DC_PIN 26  // AKA RS pin
#define gridSquareSize 20
#define SQUARES_IN_TETRIMINO 4

enum squareStatus {
    empty,
    inactive,
    active
};


class playGrid{
public:
    playGrid(int squareLengthPixels, int gridWidthPixels, 
        int gridHeightPixels, int beginningXPos, int beginningYPos, bool showGrid);

    void drawGrid(uint16_t color);

    void fillSquare(uint16_t color, int xGridCoord, int yGridCoord);
    bool isSpaceAvailable(int *newLocations);
    bool isHittingBottom(int *newLocations);
    bool isHittingSide(int *newLocations);
    void deactivate(int *newLocations);
    int getNumSquaresHorz(), getNumSquaresVert();
private:
    int squareLengthPixels,
    numSquaresHorz, 
    numSquaresVert,
    gridWidthPixels, 
    gridHeightPixels,
    beginningXPos, 
    beginningYPos,
    currentSquare;

    bool showGrid;

    uint8_t *squareStatusArray;
    uint64_t tickPeriodMillis;
    HX_8357_8Bit *tft;
};

#endif //PLAYGRID_H