#include "playGrid.h"

playGrid::playGrid(int squareLengthPixels = 20, int gridWidthPixels = 320, 
        int gridHeightPixels = 480, int beginningXPos = 0, int beginningYPos = 0, bool showGrid = 1):
        squareLengthPixels(squareLengthPixels), gridWidthPixels(gridWidthPixels),
        gridHeightPixels(gridHeightPixels), beginningXPos(beginningXPos), beginningYPos(beginningYPos),
        showGrid(showGrid)
{
    numSquaresHorz = gridWidthPixels/squareLengthPixels;
    numSquaresVert = gridHeightPixels/squareLengthPixels;
    squareStatusArray = (uint8_t*) malloc(numSquaresHorz*numSquaresVert);
    showGrid = showGrid;
    tickPeriodMillis = 1500;

    tft = new HX_8357_8Bit(2, RST_PIN, RD_PIN, CS_PIN, WR_PIN, DC_PIN, 320, 480);
}

void playGrid::drawGrid(uint16_t color)
{
    tft->init();

    tft->fillScreen(BLACK);

    for (int i = beginningXPos; i < gridWidthPixels; i += squareLengthPixels)
        tft->drawFastVLine(i, beginningYPos, gridHeightPixels, color);
   
    for (int i = beginningYPos; i < gridHeightPixels; i += squareLengthPixels)
        tft->drawFastHLine(beginningXPos, i, gridWidthPixels, color);
}

void playGrid::fillSquare(uint16_t color, int xGridCoord, int yGridCoord)
{
    int gridOffset = showGrid*2;
    int startXPixel = xGridCoord*squareLengthPixels + beginningXPos+gridOffset;
    int startYPixel = yGridCoord*squareLengthPixels + beginningYPos+gridOffset;

    tft->fillRect(startXPixel, startYPixel, squareLengthPixels-gridOffset, squareLengthPixels-gridOffset, color);
    
    if(!color)
        squareStatusArray[xGridCoord + yGridCoord*numSquaresHorz] = empty;
    else
        squareStatusArray[xGridCoord + yGridCoord*numSquaresHorz] = active;
}

bool playGrid::isHittingSide(int *newLocations)
{
    for (int i = 0; i < SQUARES_IN_TETRIMINO*2; i += 2)
        if (newLocations[i] >= numSquaresHorz || (squareStatusArray[newLocations[i] + newLocations[i+1]*numSquaresHorz] == inactive) || newLocations[i] < 0)
         return true;

    return false;
}

bool playGrid::isHittingBottom(int *newLocations)
{
    for (int i = 0; i < SQUARES_IN_TETRIMINO*2; i += 2)
        if (newLocations[i+1] >= numSquaresVert || (squareStatusArray[newLocations[i] + newLocations[i+1]*numSquaresHorz] == inactive))
         return true;
         
    return false;
}

int playGrid::getNumSquaresVert()
{
    return numSquaresVert;
}

int playGrid::getNumSquaresHorz()
{
    return numSquaresHorz;
}

void playGrid::deactivate(int *newLocations)
{
    for (int i = 0; i < SQUARES_IN_TETRIMINO*2; i += 2)
        squareStatusArray[newLocations[i] + newLocations[i+1]*numSquaresHorz] = inactive;
}