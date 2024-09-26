#include <iostream>
#include <raylib.h>

using namespace std;

int main() {

  const int width = 1290;
  const int height = 800;

  InitWindow(width, height, "My Pong Game!");
  SetTargetFPS(60);

  while (WindowShouldClose() == false) {
    BeginDrawing();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
