#include "Enemy.h" //Este .cpp va a tener las funciones desarrolladas del Enemy.h.

void Enemy::RandomDirection()
{
	direction = { 0, 0 }; //1º seteamos direccion a 0,0.
	int random = rand() % 4; //Le decimos que tenga 4 opciones; arriba, abajo, izq, dcha.
	switch (random) //Usamos un switch para decidir en que direccion va a ir:
	{
	case 0:
		direction.X = 1;
		break;
	case 1:
		direction.X = -1;
		break;
	case 2:
		direction.Y = 1;
		break;
	case 3:
		direction.Y = -1;
		break;
	}
}

Enemy::Enemy()
{			    //x //y
	spawn = { 0,0 };
	position = spawn; //Definimos variables que tiene la clase
	direction = { 0, 0 }; //Definimos variables que tiene la clase
}

Enemy::Enemy(COORD _spawn)
{
	spawn = _spawn;
	position = _spawn; //Ponemos posicion igual al Spawn
	direction = { 0, 0 }; //No tocamos la direccion
}

void Enemy::Draw()
{
	ConsoleUtils::Console_SetPos(position); //Colocamos el cursor donde vamos a dibujar el enemigo (de la consola) en la posicion del enemigo.
	ConsoleUtils::Console_SetColor(foreground, background); //Antes de imprimir cambiamos el color del enemigo.
	std::cout << enemy_char; //Imprimimos caracter
}

void Enemy::PowerUpPicked()
{
	powerup_countdown = TimeManager::getInstance().time + powerup_countdown_time;
}

Enemy::ENEMY_STATE Enemy::Update(Map* _map, COORD _player) //* --> Puntero
{	
	RandomDirection(); //Llamamos a la función para que vaya en una direccion aleatoria.
	COORD newPosition = position; //Creamos posicion temporal para el enemigo
	//newPosition = posición temporal /position = posición actual.
	newPosition.X += direction.X; //Sumamos la direccion para que se mueva
	newPosition.Y += direction.Y; //Lo mismo 
	
	//TELETRANSPORTE

	if (newPosition.X < 0)
	{
		newPosition.X = _map->Width - 1;
	}
	newPosition.X %= _map->Width;
	if (newPosition.Y < 0)
	{
		newPosition.Y = _map->Height - 1;
	}
	newPosition.Y %= _map->Height;

	//COLISION PAREDES
	//Copiamos y pegamos el switch del archivo "main.cpp" y lo modificamos
	switch (_map->GetTile(newPosition.X, newPosition.Y))
	{
	case Map::MAP_TILES::MAP_WALL:
		newPosition = position; //Reinicia la posicion temporal a la posicion actual pq invalidamos el movimiento del enemigo.
		break;
	}
	position = newPosition; //Aplicamos la posicion temporal a la posicion actual.

	ENEMY_STATE state = ENEMY_STATE::ENEMY_NONE;
	if (position.X == _player.X && position.Y == _player.Y) 
	{
		if (powerup_countdown <= TimeManager::getInstance().time) 
		{
			state = ENEMY_STATE::ENEMY_DEAD;
		}
		else 
		{
			position = spawn;
			state = ENEMY_STATE::ENEMY_KILLED;
		}
	}
	if (powerup_countdown <= TimeManager::getInstance().time) 
	{
		foreground = foreground_attack;
	}
	else
	{
		foreground = foreground_powerUp;
	}
	return state;

}
