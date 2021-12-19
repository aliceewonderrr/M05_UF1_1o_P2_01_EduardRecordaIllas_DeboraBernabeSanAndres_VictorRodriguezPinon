#pragma once
#include "ConsoleUtils.h"
#include "Map.h"
#include "Enemy.h"
#include <vector>

enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
class Player
{
private:
	COORD spawn; 
	COORD direction;
	char player_char = char(1);
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::YELLOW;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;
public:
	COORD position;
	int points = 0;
	Player(COORD _spawn);
	void Update(Map* _map, USER_INPUTS input, std::vector<Enemy>* enemies);
	void Draw();

};

