#include <iostream>
#include <raylib.h>

using namespace std;

class Ball {
public:
  float x, y;
  int speed_x, speed_y;
  int radius;

  void Draw() { DrawCircle(x, y, radius, WHITE); }
  void Update() {
    x += speed_x;
    y += speed_y;

    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
      speed_y *= -1;
    }
    if (x + radius >= GetScreenWidth() || x - radius <= 0) {
      speed_x *= -1;
    }
  }
};

class Paddle {
public:
  float x, y;
  int speed;
  int height, width;

  void Draw() { DrawRectangle(x, y, width, height, WHITE); }

  void Update() {
    if (IsKeyDown(KEY_UP)) {
      y -= speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
      y += speed;
    }

    if (y <= 0) {
      y = 0;
    }
    if (y >= GetScreenHeight() - height) {
      y = GetScreenHeight() - height;
    }
  }
};

Ball ball;
Paddle player;

int main() {

  const int screen_width = 1280;
  const int screen_height = 800;

  InitWindow(screen_width, screen_height, "My Pong Game!");
  SetTargetFPS(60);

  ball.radius = 20;
  ball.x = screen_width / 2.0;
  ball.y = screen_height / 2.0;
  ball.speed_x = 7.0;
  ball.speed_y = 7.0;

  player.height = 120;
  player.width = 25;
  player.x = screen_width - 35;
  player.y = screen_height / 2.0 - 60;
  player.speed = 7;

  while (WindowShouldClose() == false) {
    BeginDrawing();

    ball.Update();
    player.Update();

    ClearBackground(BLACK);
    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
    ball.Draw();
    DrawRectangle(10, (screen_height / 2 - 60), 25, 120, WHITE);
    player.Draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
