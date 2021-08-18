#include "tetrisController.h"

TetrisController::TetrisController(int downButton, int rightButton, int leftButton, int rotButton, int holdButton, int pauseButton):
                                     downButton(downButton), rightButton(rightButton), leftButton(leftButton), rotButton(rotButton),
                                     holdButton(holdButton), pauseButton(pauseButton)
{
    inputPinsMask |= (1 << downButton) | (1 << rightButton) | (1 << leftButton) | (1 << rotButton) | (1 << holdButton) | (1 << pauseButton);
}
void TetrisController::initPins()
{
    gpio_init_mask(inputPinsMask);
    gpio_set_dir_in_masked(inputPinsMask);

    gpio_pull_up(downButton);
    gpio_pull_up(rightButton);
    gpio_pull_up(leftButton);
    gpio_pull_up(rotButton);
    gpio_pull_up(holdButton);
    gpio_pull_up(pauseButton);
}

int TetrisController::whichPressed()
{
    int button;

    button = 0;

    //printf("which one\n");
    
    if (!gpio_get(downButton)){
		printf("Pressed down\n");
        button = downButton;
    } else if (!gpio_get(rightButton)){
		printf("Pressed right\n");
        button = rightButton;
    } else if (!gpio_get(leftButton)){
		printf("Pressed left\n");
        button = leftButton;
    } else if (!gpio_get(rotButton)){
		printf("Pressed rot\n");
        button = rotButton;
    } else if (!gpio_get(pauseButton)){
		printf("Pressed pause\n");
        button = pauseButton;
    } else if (!gpio_get(holdButton)){
		printf("Pressed hold\n");
        button = holdButton;
    }

    //printf("pressed %d\n", button);

    if (button)
        while(!gpio_get(button));
    else
        return 0;

    

    return button;
}