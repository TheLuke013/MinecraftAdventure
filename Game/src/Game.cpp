#include <raylib.h>

int main()
{
	InitWindow(1024, 600, "Minecraft Adventure");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}