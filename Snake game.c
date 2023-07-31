#include "Snake game.h"

void setup()
{
    gameover = 0;

    x = HEIGHT / 2;
    y - WIDTH / 2;

label:
    axleX = rand() % 20;
    if (axleX == 0)
        goto label;
label2:
    axleY = rand() % 20;
    if (axleY == 0)
        goto label2;
    score = 0;
}

void draw()
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (i == 0 || i == WIDTH - 1 || j == 0 || j == HEIGHT - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                    printf("0");
                else if (i == axleX && j == axleY)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("score = %d", score);
    printf("\n");
    printf("Press X to quit");
}

void input() 
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void movement()
{
    _sleep(0.01);
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    if (x < 0 || x > HEIGHT || y < 0 || y > WIDTH)
        gameover = 1;

    if (x == axleX && y == axleY) {
    label3:
        axleX = rand() % 20;
        if (axleX == 0)
            goto label3;

    label4:
        axleY = rand() % 20;
        if (axleY == 0)
            goto label4;
        score += 10;
    }
}

int main()
{

    setup();

    while (!gameover) {
        draw();
        input();
        movement();
    }

    return 0;
}
