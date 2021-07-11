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

#define begin_pin 15
#define ADC_SEED 26

Tetris game;


int main()
{
    stdio_init_all();
    sleep_ms(1000);
    gpio_init(begin_pin);
    
    adc_init();
    adc_gpio_init(ADC_SEED);
    adc_select_input(0);
    gpio_set_dir(begin_pin, GPIO_IN);

    gpio_pull_up(begin_pin);

    printf("HX8357D Test!\n");

    uint32_t seed = adc_read();
    srand(seed);

    
    printf("Random seed = %lu\n", seed);

    game.startGame();
    game.placeTetrimino(J);

    while(true)
        if (!gpio_get(begin_pin)){
            game.moveTetrimino(down);
            while(!gpio_get(begin_pin));
            //sleep_ms(100);
        }
}

void loop() 
{
/*
  String myInput;
  String secondThing;
  //int color, argColor, argX, argY;
  

  
  while(Serial.available() > 0){
    myInput = Serial.readStringUntil(',');

    secondThing = Serial.readStringUntil('\n');

    if (myInput == "R")
      for (int i = 0; i < secondThing.toInt(); i++)
        game.moveTetrimino(right);

    else if(myInput == "D")
      for (int i = 0; i < secondThing.toInt(); i++)
        game.moveTetrimino(down);
      
    else if(myInput == "L") 
      for (int i = 0; i < secondThing.toInt(); i++)
        game.moveTetrimino(left);

    else if(myInput == "RT")
      for (int i = 0; i < secondThing.toInt(); i++)
        game.rotateTetrimino();
  }
  */
}
