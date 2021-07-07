#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <stdlib.h>

#define SQUARES_IN_TETRIMINO 4

enum shape {
    I, J, L, O, S, T, Z
};

enum rotation{
    zero_rad, half_rad, one_rad, three_halves_rad
};

class Tetrimino
{
public:
    Tetrimino(shape type, rotation orientation, int centerXPosGrid, int centerYPosGrid, int *squareLocations);
    ~Tetrimino();
    shape type;
    rotation orientation;
    int centerXPosGrid;
    int centerYPosGrid;
    int *squareLocations;

    int *setLocations();
    int copyLocations(int *newLocs);
};

#endif //TETRIMINO_H