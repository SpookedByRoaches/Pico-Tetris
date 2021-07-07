#include "tetris.h"



Tetris::Tetris()
{
    grid  = new playGrid(gridSquareSize, 320, 480,
                 0, 0, 1);
}

void Tetris::placeTetrimino(shape type)
{
    int yPosGrid = 1;

    int xPosGrid = (grid->getNumSquaresHorz())/2;

    int *squares = (int *)malloc(SQUARES_IN_TETRIMINO*2*sizeof(int));

    piece  = new Tetrimino(type, zero_rad, xPosGrid, yPosGrid, squares);    
    piece->setLocations();
    drawTetrimino(RED, piece);
}

void Tetris::drawTetrimino(int color, Tetrimino *drawTarget)
{
    for (int i = 0; i < SQUARES_IN_TETRIMINO*2; i += 2){
        if (!color){
            printf("Square");
            printf("%d", i/2);
            printf("(");
            printf("%d", drawTarget->squareLocations[i]);
            printf(", ");
            printf("%d", drawTarget->squareLocations[i+1]);
            printf(")\n");
        }
        grid->fillSquare(color, drawTarget->squareLocations[i], drawTarget->squareLocations[i+1]);
    }
}

void Tetris::startGame()
{
    grid->drawGrid(GREEN);
}

void Tetris::rotateTetrimino()
{
    Tetrimino *tempPiece;

    int *tempSquares = (int *)malloc(SQUARES_IN_TETRIMINO*2*sizeof(int));

    rotation orient = (rotation)(((int)piece->orientation + 1)%4);

    printf("Orientation = ");

    printf("%d\n", orient);

    tempPiece = new Tetrimino(piece->type, (rotation)(((int)piece->orientation + 1)%4), piece->centerXPosGrid, 
                                piece->centerYPosGrid, tempSquares);
    

    tempPiece->setLocations();

    if (!(grid->isHittingSide(tempPiece->squareLocations) || grid->isHittingBottom(tempPiece->squareLocations))){   
        drawTetrimino(BLACK, piece);

        drawTetrimino(RED, tempPiece);

        delete piece;

        piece = tempPiece;
    } 
    else {
        delete tempPiece;
    }
}

void Tetris::moveTetrimino(enum MovementDirection direction)
{
    int tempSquares[SQUARES_IN_TETRIMINO*2];

    for (int i = 0; i < SQUARES_IN_TETRIMINO*2; i += 2){
        tempSquares[i] = piece->squareLocations[i] + direction;

        tempSquares[i+1] = piece->squareLocations[i+1] + !direction;
    }

    printf("Moved ");
    printf("%d\n", direction);

    

    if (grid->isHittingSide(tempSquares) && direction != down){
        printf("Hit wall\n");

        drawTetrimino(BLACK, piece);

        delay(300);

        drawTetrimino(RED, piece);
    } else if(grid->isHittingBottom(tempSquares)) {
        printf("Hit bottom\n");

        drawTetrimino(BLACK, piece);

        delay(150);

        drawTetrimino(RED, piece);

        delay(150);

        drawTetrimino(BLACK, piece);

        delay(150);

        drawTetrimino(RED, piece);

        grid->deactivate(piece->squareLocations);

        delete piece;

        generateTetrimino();

        placeTetrimino(nextShape);
    } else {
        drawTetrimino(BLACK, piece);

        for (int i = 0; i < SQUARES_IN_TETRIMINO*2; i++)
            piece->squareLocations[i] = tempSquares[i];
        
        piece->centerXPosGrid += direction;

        piece->centerYPosGrid += !direction;
        drawTetrimino(RED, piece);
    }
}

void Tetris::generateTetrimino()
{
    nextShape = (shape)(random()%8);
}