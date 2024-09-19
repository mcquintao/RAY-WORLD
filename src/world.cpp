#include "raylib.h"

#define WORLD_GRID 30
#define CELL_SIZE 20

class World
{

private:

    int worldMap[WORLD_GRID][WORLD_GRID] = {0};

public:
    World()
    {
    }
    void draw(Vector2 cameraPos, int x, int y)
    {

        for (int i = 0; i < WORLD_GRID; i++)
        {
            for (int j = 0; j < WORLD_GRID; j++)
            {
                if (i == x && j == y)
                {
                    DrawRectangle(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE-1, GREEN);
                }
                else
                {
                    DrawRectangle(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE -1, RED);
                }

                // DrawText(TextFormat("%d", i + WORLD_GRID*j), i * 20, j * 20, 3, WHITE);
            }
        }
    }
};