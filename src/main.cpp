#include <raylib.h>

int cpu_score = 0;
int player_score = 0;

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

    if (x + radius >= GetScreenWidth()) {
      cpu_score++;
      ResetBall();
    }

    if (x - radius <= 0) {
      player_score++;
      ResetBall();
    }
  }

  void ResetBall() {
    x = GetScreenWidth() / 2.0;
    y = GetScreenHeight() / 2.0;

    int speed_choices[2] = {1, -1};
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];
  }
};

class Paddle {
public:
  float x, y;
  int speed;
  float height, width;

  void Draw() { DrawRectangle(x, y, width, height, WHITE); }

  void Update() {
    if (IsKeyDown(KEY_UP)) {
      y -= speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
      y += speed;
    }

    LimitMovement();
  }

protected:
  void LimitMovement() {
    if (y <= 0) {
      y = 0;
    }
    if (y >= GetScreenHeight() - height) {
      y = GetScreenHeight() - height;
    }
  }
};

class CpuPaddle : public Paddle {
public:
  void Update(float ball_y) {
    if (y + height / 2.0 > ball_y) {
      y -= speed;
    }
    if (y + height / 2.0 <= ball_y) {
      y += speed;
    }

    LimitMovement();
  }
};

Ball ball;
Paddle player;
CpuPaddle cpu;

int main() {

  const int screen_width = 1280;
  const int screen_height = 800;

  InitWindow(screen_width, screen_height, "My Pong Game!");
  SetTargetFPS(60);

  ball.radius = 20;
  ball.x = screen_width / 2.0;
  ball.y = screen_height / 2.0;
  ball.speed_x = 7;
  ball.speed_y = 7;

  player.height = 120;
  player.width = 25;
  player.x = screen_width - 35;
  player.y = screen_height / 2.0 - 60;
  player.speed = 6;

  cpu.height = 120;
  cpu.width = 25;
  cpu.x = 10;
  cpu.y = screen_height / 2.0 - 60;
  cpu.speed = 6;

  while (WindowShouldClose() == false) {
    BeginDrawing();

    ball.Update();
    player.Update();
    cpu.Update(ball.y);

    if (CheckCollisionCircleRec(
            Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{player.x, player.y, player.width, player.height})) {
      ball.speed_x *= -1;
    }

    if (CheckCollisionCircleRec(
            Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})) {
      ball.speed_x *= -1;
    }
    ClearBackground(BLACK);
    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

    ball.Draw();
    cpu.Draw();
    player.Draw();

    DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80,
             WHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
