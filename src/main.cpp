#include <main.h>
// These are 'flexible' lines that can be changed
#define gridSquareSize 20

//TFT color codes
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

int *args = (int *)malloc(6);

#define rightButton 14
#define downButton 15
#define leftButton 16
#define rotButton 17
#define holdButton 18
#define pauseButton 19



Tetris game;


int main()
{
    stdio_init_all();
    //sleep_ms(1000);
    
    
    printf("HX8357D Test!\n");

    
    game.setButtons(downButton, rightButton, leftButton, rotButton, holdButton, pauseButton);
    game.startGame();
    

    while(true)
        if (!gpio_get(begin_pin)){
            game.moveTetrimino(down);
            while(!gpio_get(begin_pin));
            //sleep_ms(100);
        }
}
