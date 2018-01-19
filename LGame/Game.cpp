#include "Game.h"
#include "Scene.h"
#include <iostream>

using std::cin;
using std::cout;

Scene* Game::_scene = nullptr;
char Game::_input[] = "";
bool Game::_isRunning = true;

void Game::HandleInput()
{
	cin >> _input;
}

void Game::UpdateGamePlay()
{
	cout << _input << "\n";
}

void Game::Render()
{
	int numberOfMonsters = 0;
	auto monsters = _scene->GetMonsters();
	for (int i = 0; i < _scene->GetMaximumMonsterCount(); i++)
	{
		auto monster = monsters[i];
		if (monster.IsValid())
		{
			cout << monster.GetType() << '\n';
			numberOfMonsters++;
		}
	}
	cout << "There are " << numberOfMonsters << " monsters in the scene.\n";
}

void Game::Initialize()
{
	_scene = new Scene(32);

	while (_isRunning)
	{
		Render();
		HandleInput();
		UpdateGamePlay();
	}
}

void Game::Stop()
{
	_isRunning = false;
}
