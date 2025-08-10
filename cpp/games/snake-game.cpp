#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
// for the map:
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY; // for the pos
int score;

enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir; // snake direction

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height; // generates random pos for fruit
    score = 0;
}

void Draw()
{
    system("cls"); // or "clear"
    for (int i = 0; i < width + 2; i++)
        cout << "#"; // top wall
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0) // L wall
                cout << "#";

            if (i == y && j == x)
                cout << "O"; // snake head
            else if (i == fruitY && j == fruitX)
                cout << "*"; // fruit
            else
                cout << " "; // empty space

            if (j == width - 1) // R wall
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#"; // bottom wall
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit()) // keyboard hit
    {
        switch (_getch()) // reads char from keyboard
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // if snake hits wall → game over
    if (x >= width || x < 0 || y >= height || y < 0)
        gameOver = true;

    // if snake eats fruit
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100); // delay
    }
    return 0;
}
