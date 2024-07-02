#include <raylib.h>
#include <iostream>

int main(){
    std::cout << "Starting game...." << std::endl;
    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width,screen_height,"Pong");
    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        
        // updating
        ball.update();
        player.Update();
        cpu.Update(ball.y);

        // collision detection
        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y}, ball.radius, Rectangle{player.x,player.y, player.width, player.height})){
            ball.speed_x *= -1;
        }
        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y}, ball.radius, Rectangle{cpu.x,cpu.y, cpu.width, cpu.height})){
            ball.speed_x *= -1;
        }

        // Drawing
        ClearBackground(dark_green);
        DrawRectangle(screen_width/2, 0, screen_width/2, screen_height,green);
        DrawCircle(screen_width/2, screen_height/2, 150, light_green);
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
        player.Draw();
        cpu.Draw();
        ball.Draw();
        DrawText(TextFormat("%i",cpu_score),screen_width/4 -20,25,80,WHITE);
        DrawText(TextFormat("%i",player_score),3*screen_width/4 -20,25,80,WHITE);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
