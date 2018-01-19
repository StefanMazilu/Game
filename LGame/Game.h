#pragma once

class Scene;


class Game
{
	static bool _isRunning;
	static char _input[32];
	static Scene* _scene;

	static void HandleInput();
	static void UpdateGamePlay();
	static void Render();

public:

	static void Initialize();
	static void Stop();
};
