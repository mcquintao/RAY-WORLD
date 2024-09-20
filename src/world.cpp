#include "raylib.h"
#include "raymath.h"
#include "constants.h"
#include "stdio.h"

struct Grid
{
    int x;
    int y;
};

class World
{

private:
    // int worldMap[WORLD_GRID][WORLD_GRID] = {0};

    Grid selectTiles[100] = {};

    int selectTileSize = 0;

    void removeTile(int i)
    {

        if (i == selectTileSize -1)
        {
            selectTiles[i] = (Grid){0, 0};
            selectTileSize--;
            return;
        }
        else
        {
            Grid lastTile = selectTiles[selectTileSize - 1];
            // selectTiles[selectTileSize] = Vector2Zero();
            selectTiles[i] = lastTile;
            selectTileSize--;
            return;
        }
    }

    void addTile(Grid tile)
    {
        selectTiles[selectTileSize] = tile;
        selectTileSize++;
    }

public:
    World()
    {
    }

    void clickTile(int xGrid, int yGrid)
    {
        Grid tile = (Grid){xGrid, yGrid};
        printf("tileX: %d, tileY: %d\n", tile.x, tile.y);
        //  printf("Teste");
        for (int i = 0; i < selectTileSize; i++)
        {
            if (tile.x == selectTiles[i].x && tile.y == selectTiles[i].y)
            {
                removeTile(i);
                return;
            }
        }
        addTile(tile);
        printselectTiles();
    }

    void printselectTiles()
    {
        for (int i = 0; i < selectTileSize; i++)
        {
            printf("X: %d, Y: %d\n", (int)selectTiles[i].x, (int)selectTiles[i].y);
        }
    }

    void draw(Vector2 cameraPos, int x, int y)
    {

        for (int i = (cameraPos.x - SCREEN_WIDTH / 2 - CELL_SIZE) / CELL_SIZE; i < (cameraPos.x + SCREEN_WIDTH / 2) / CELL_SIZE; i++)
        {

            for (int j = (cameraPos.y - SCREEN_WIDTH / 2 - CELL_SIZE) / CELL_SIZE; j < (cameraPos.y + SCREEN_WIDTH / 2) / CELL_SIZE; j++)
            {

                if (i == x && j == y)
                {
                    DrawRectangle(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1, GREEN);
                }
                else
                {
                    DrawRectangle(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1, RED);
                }
                // DrawText(TextFormat("(%d, %d)", i, j), i * 20, j * 20, 3, WHITE);
            }
        }
        for (int i = 0; i < selectTileSize; i++)
        {
            DrawRectangle(selectTiles[i].x * CELL_SIZE, selectTiles[i].y * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1, BLUE);
        }
    }
};