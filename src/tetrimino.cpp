#include "tetrimino.h"


Tetrimino::Tetrimino(shape type = I, rotation orientation = zero_rad,
                     int centerXPosGrid = 0, int centerYPosGrid = 0, int *squareLocations = NULL):
                     type(type), orientation(orientation), centerXPosGrid(centerXPosGrid),
                     centerYPosGrid(centerYPosGrid), squareLocations(squareLocations)
{
}

Tetrimino::~Tetrimino()
{
    free(squareLocations);
}


//Extremely hacky no way but to brute force this as far as I know
//Patterns are exploited where I see them
int *Tetrimino::setLocations()
{
    bool isHorz = (orientation%2 == 0);

    switch(type){
    case I:
        switch(orientation){
        case zero_rad: //Horizontal above the center point
            squareLocations[0] = centerXPosGrid - 2;
            squareLocations[1] = centerYPosGrid - 1;
            break;
        case half_rad: //Vertical to the left of center point
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid - 3;
            break;
        case one_rad: //Horizontal below the center point
            squareLocations[0] = centerXPosGrid - 2;
            squareLocations[1] = centerYPosGrid;
            break;
        case three_halves_rad: //Vertical to the right of the center point
            squareLocations[0] = centerXPosGrid;
            squareLocations[1] = centerYPosGrid - 3;
            break;
        }
        for (int i = 2; i < SQUARES_IN_TETRIMINO*2; i++) //Even 
            squareLocations[i] = squareLocations[i - 2] + (isHorz  != (i%2));
        break;

    case J:
        //Do stray square then line
        switch(orientation){
            case zero_rad: //Horizontal above the center point
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid - 1;
            break;
        case half_rad: //Vertical to the left of center point
            squareLocations[0] = centerXPosGrid + 1;
            squareLocations[1] = centerYPosGrid - 1;
            break;
        case one_rad: //Horizontal below the center point
            squareLocations[0] = centerXPosGrid + 1;
            squareLocations[1] = centerYPosGrid + 1;
            break;
        case three_halves_rad: //Vertical to the right of the center point
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid + 1;
            break;
        }
        goto three_square_line;

        
    case L:
        switch(orientation){
            case zero_rad: //Horizontal above the center point
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid - 1;
            break;
        case half_rad: //Vertical to the left of center point
            squareLocations[0] = centerXPosGrid + 1;
            squareLocations[1] = centerYPosGrid - 1;
            break;
        case one_rad: //Horizontal below the center point
            squareLocations[0] = centerXPosGrid + 1;
            squareLocations[1] = centerYPosGrid + 1;
            break;
        case three_halves_rad: //Vertical to the right of the center point
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid + 1;
            break;
        }
        goto three_square_line;

        
    case O:
        squareLocations[0] = centerXPosGrid - 1;
        squareLocations[1] = centerYPosGrid - 1;
        squareLocations[2] = centerXPosGrid;
        squareLocations[3] = centerYPosGrid - 1;
        squareLocations[4] = centerXPosGrid - 1;
        squareLocations[5] = centerYPosGrid;
        squareLocations[6] = centerXPosGrid;
        squareLocations[7] = centerYPosGrid;
        break;

    case S:
        switch (orientation){
        case zero_rad:
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid;
            squareLocations[4] = centerXPosGrid;
            squareLocations[5] = centerYPosGrid-1;
            squareLocations[6] = centerXPosGrid+1;
            squareLocations[7] = centerYPosGrid-1;
            break;
        case half_rad:
            squareLocations[0] = centerXPosGrid;
            squareLocations[1] = centerYPosGrid - 1;
            squareLocations[4] = centerXPosGrid + 1;
            squareLocations[5] = centerYPosGrid;
            squareLocations[6] = centerXPosGrid + 1;
            squareLocations[7] = centerYPosGrid + 1;
            break;
        case one_rad:
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid + 1;
            squareLocations[4] = centerXPosGrid;
            squareLocations[5] = centerYPosGrid + 1;
            squareLocations[6] = centerXPosGrid + 1;
            squareLocations[7] = centerYPosGrid;
            break;
        case three_halves_rad:
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid - 1;
            squareLocations[4] = centerXPosGrid - 1;
            squareLocations[5] = centerYPosGrid;
            squareLocations[6] = centerXPosGrid;
            squareLocations[7] = centerYPosGrid + 1;
            break;
        }
        squareLocations[2] = centerXPosGrid;
        squareLocations[3] = centerYPosGrid;
        break;
    case Z:
    switch(orientation){
        case zero_rad:
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid - 1;
            squareLocations[4] = centerXPosGrid;    
            squareLocations[5] = centerYPosGrid - 1;
            squareLocations[6] = centerXPosGrid + 1;
            squareLocations[7] = centerYPosGrid;
            break;
        case half_rad:
            squareLocations[0] = centerXPosGrid + 1;
            squareLocations[1] = centerYPosGrid - 1;
            squareLocations[4] = centerXPosGrid + 1;
            squareLocations[5] = centerYPosGrid;
            squareLocations[6] = centerXPosGrid;
            squareLocations[7] = centerYPosGrid + 1;
            break;
        case one_rad:
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid;
            squareLocations[4] = centerXPosGrid;
            squareLocations[5] = centerYPosGrid + 1;
            squareLocations[6] = centerXPosGrid + 1;
            squareLocations[7] = centerYPosGrid + 1;
            break;
        case three_halves_rad:
            squareLocations[0] = centerXPosGrid;
            squareLocations[1] = centerYPosGrid - 1;
            squareLocations[4] = centerXPosGrid - 1;
            squareLocations[5] = centerYPosGrid;
            squareLocations[6] = centerXPosGrid - 1;
            squareLocations[7] = centerYPosGrid + 1;
            break;
        }
        squareLocations[2] = centerXPosGrid;
        squareLocations[3] = centerYPosGrid;
        break;
    case T:
        switch(orientation){
        case zero_rad:
            squareLocations[0] = centerXPosGrid;
            squareLocations[1] = centerYPosGrid - 1;
            break;
        case half_rad:
            squareLocations[0] = centerXPosGrid + 1;
            squareLocations[1] = centerYPosGrid;
            break;
        case one_rad:
            squareLocations[0] = centerXPosGrid;
            squareLocations[1] = centerYPosGrid + 1;
            break;
        case three_halves_rad:
            squareLocations[0] = centerXPosGrid - 1;
            squareLocations[1] = centerYPosGrid;
            break;
        }
        goto three_square_line;
    }
    
    return squareLocations;

three_square_line:  //Lesser of two evils
    squareLocations[2] = centerXPosGrid - isHorz;
    squareLocations[3] = centerYPosGrid - !isHorz;

    for (int i = 4; i < SQUARES_IN_TETRIMINO*2; i++)
        squareLocations[i] = squareLocations[i - 2] + (isHorz != (i%2));
    return squareLocations;
}