#include <raylib.h>

int main() {
  // Initialize the window
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Hello, World! - Raylib");

  // Set the frame rate
  SetTargetFPS(60);

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Start drawing
    BeginDrawing();

    ClearBackground(RAYWHITE); // Set the background color to white

    // Draw the "Hello, World!" text
    DrawText("Hello, World!", 350, 200, 20, DARKGRAY);

    // End drawing
    EndDrawing();
  }

  // Close window and OpenGL context
  CloseWindow();

  return 0;
}
