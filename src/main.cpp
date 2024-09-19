#include "raylib.h"
#include "raymath.h"
#include "world.cpp"
#include "stdio.h"


#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500


int main(void)
{

    World world;
    int cameraSpeed = 150;
    int cameraSpeedMulti = 2;
    Vector2 cameraMovmentDIrection = (Vector2){0, 0};
    Vector2 mousePosition ;

    Camera2D camera = { 0 };
    camera.target = (Vector2){ 20*WORLD_GRID/2.0f, 20*WORLD_GRID/2.0f};
    camera.offset = (Vector2){ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
         
        mousePosition = GetMousePosition();
        int xGrid = (mousePosition.x + camera.target.x - SCREEN_WIDTH/2)/20;
        int yGrid = (mousePosition.y + camera.target.y - SCREEN_HEIGHT/2)/20;

        cameraMovmentDIrection = Vector2Zero();
        if (IsKeyDown(KEY_LEFT_SHIFT)) cameraSpeedMulti = 2;
        else cameraSpeedMulti = 1;

        if (IsKeyDown(KEY_D)) cameraMovmentDIrection = Vector2Add(cameraMovmentDIrection, (Vector2){1,0});
        if (IsKeyDown(KEY_A)) cameraMovmentDIrection = Vector2Add(cameraMovmentDIrection, (Vector2){-1,0});
        if (IsKeyDown(KEY_S)) cameraMovmentDIrection = Vector2Add(cameraMovmentDIrection, (Vector2){0,1});
        if (IsKeyDown(KEY_W)) cameraMovmentDIrection = Vector2Add(cameraMovmentDIrection, (Vector2){0,-1});

        cameraMovmentDIrection = Vector2Normalize(cameraMovmentDIrection);
        cameraMovmentDIrection = Vector2Scale(cameraMovmentDIrection, cameraSpeed * cameraSpeedMulti * GetFrameTime());

        camera.target = Vector2Add(camera.target, cameraMovmentDIrection);
        


      //  printf("X: %d, Y: %d\n", xGrid, yGrid);


        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        BeginMode2D(camera);
        world.draw(camera.target, xGrid, yGrid);
        EndMode2D();
        DrawText(TextFormat("FPS: %.2f", 1/GetFrameTime()), 0, 0, 30, BLACK);
        EndDrawing();

    }

    CloseWindow();
    return 0;
}