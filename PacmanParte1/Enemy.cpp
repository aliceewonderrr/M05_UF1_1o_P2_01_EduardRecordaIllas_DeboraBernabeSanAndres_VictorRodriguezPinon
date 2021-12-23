#include "Enemy.h" //Este .cpp va a tener las funciones desarrolladas del Enemy.h.

/*void Enemy::RandomDirection()
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
}*/

 void Enemy::MovementAlgorithm()
{	
	//Vectores de movimiento (para saber la dirección en la que se está moviendo)
	int Up[]{ 1 , 0 };	//si el resultado es este, se esta moviendo hacia arriba
	int Down[]{ -1 , 0 };	//si el resultado es este, se esta moviendo hacia abajo
	int Right[]{ 0 , 1 };	//si el resultado es este, se esta moviendo hacia derecha
	int Left[]{ 0 , -1 };	//si el resultado es este, se esta moviendo hacia izquierda


	int xyPos[2] = { position.X, position.Y };

	//Calculo de donde estan las paredes
	if (xyPos[position.X + 1, position.Y] == Map::MAP_TILES::MAP_WALL) { isWallUp = true; }
	
	
	if (xyPos[position.X - 1, position.Y] == Map::MAP_TILES::MAP_WALL) { isWallDown = true; };
	if (xyPos[position.X + 1, position.Y + 1] == Map::MAP_TILES::MAP_WALL) { isWallRight = true; }
	if (xyPos[position.X + 1, position.Y - 1] == Map::MAP_TILES::MAP_WALL) { isWallLeft = true; }

		//Una salida posible-------

	int order = 0;

	if (isWallUp == true && isWallRight == true && isWallLeft == true) { order=D; } //Solo salida por abajo
	if (isWallDown == true && isWallRight == true && isWallLeft == true) { order=U; } //Solo salida por arriba
	if (isWallUp == true && isWallDown == true && isWallLeft == true) { order = R; } //Solo salida por derecha
	if (isWallUp == true && isWallDown == true && isWallRight == true) { order = L; } //Solo salida por izquierda

	//Dos salidas posibles-------
	if (isWallUp == false && isWallDown == false && isWallRight == true && isWallLeft == true) { order = UD; } //Salida por arriba y por abajo
	if (isWallUp == false && isWallDown == true && isWallRight == false && isWallLeft == true) { order = UR; } //Salida por arriba y derecha
	if (isWallUp == false && isWallDown == true && isWallRight == true && isWallLeft == false) { order = UL; } //Salida por arriba e izquierda
	if (isWallUp == true && isWallDown == false && isWallRight == false && isWallLeft == true) { order = DR; } //Salida por abajo y derecha
	if (isWallUp == true && isWallDown == false && isWallRight == true && isWallLeft == false) { order = DL; } //Salida por abajo e izquierda
	if (isWallUp == true && isWallDown == true && isWallRight == false && isWallLeft == false) { order = LR; } //Salida por derecha e izquierda

	//Tres salidas posibles-------
	if (isWallUp == false && isWallDown == false && isWallRight == false && isWallLeft == true) { order = UDR; } //Salida por arriba, abajo y derecha
	if (isWallUp == false && isWallDown == false && isWallRight == true && isWallLeft == false) { order = UDL; } //Salida por arriba, abajo e izquierda
	if (isWallUp == false && isWallDown == true && isWallRight == false && isWallLeft == false) { order = URL; } //Salida por arriba, derecha e izquierda
	if (isWallUp == true && isWallDown == false && isWallRight == false && isWallLeft == false) { order=DRL; } //Salida por abajo, derecha e izquierda

	//Calculamos vector de movimiento que sigue-------
	COORD newPosition = position;

	int movX = newPosition.X - position.X; //Diferencia entre X acual y X anterior
	int movY = newPosition.Y - position.Y; //Diferencia entre Y actual e Y anterior
	int movXY[]{ movX, movY }; //Vector de movimiento que sigue


	//Actuamos en consecuencia--------

	int random = 0;

		if (movXY[0, 1] == Up[0, 1]) // +++ Que va a hacer en cada caso si actualmente se está moviendo hacia arriba:
		{
			switch (order)
			{
			case U: 
				direction.X = 1;
				break;
			case D: 
				direction.X = -1;
				break;
			case R: 
				direction.Y = 1;
				break;
			case L: 
				direction.Y = -1;
				break;
			case UD: 
				direction.X = 1;
				break;
			case UR: 
				random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = 1;
				break;
			case UL: 
				random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = -1;
				break;
			case DR: 
				random = rand() % 2;
				if (random == 1) direction.X = -1;
				else direction.Y = 1;
				break;
			case DL: 
				random = rand() % 2;
				if (random == 1) direction.X = -1;
				else direction.Y = -1;
				break;
			case LR: 
				random = rand() % 2;
				if (random == 1) direction.Y = 1;
				else direction.Y = -1;
				break;
			case UDR: 
				random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = 1;
				break;
			case UDL: 
				random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = -1;
				break;
			case URL: 
				random = rand() % 3;
				if (random == 1) direction.X = 1;
				else if (random == 2) direction.Y = 1;
				else direction.Y = -1;
				break;
			case DRL: 
				 random = rand() % 3;
				if (random == 1) direction.X = -1;
				else if (random == 2) direction.Y = 1;
				else direction.Y = -1;
				break;
			}

		}

		else if (movXY[0, 1] == Down[0, 1]) //+++ Que va a hacer en cada caso si actualmente se está moviendo hacia abajo:
		{
			switch (order)
			{
			case U: direction.X = 1;
				break;
			case D: direction.X = -1;
				break;
			case R: direction.Y = 1;
				break;
			case L: direction.Y = -1;
				break;
			case UD: direction.X = -1;
				break;
			case UR: random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = 1;
				break;
			case UL: random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = -1;
				break;
			case DR: random = rand() % 2;
				if (random == 1) direction.X = -1;
				else direction.Y = 1;
				break;
			case DL: random = rand() % 2;
				if (random == 1)direction.X = -1;
				else direction.Y = -1;
				break;
			case LR: random = rand() % 2;
				if (random == 1) direction.Y = 1;
				else direction.Y = -1;
				break;
			case UDR: random = rand() % 2;
				if (random == 1) direction.X = -1;
				else direction.Y = 1;
				break;
			case UDL: random = rand() % 2;
				if (random == 1) direction.X = -1;
				else direction.Y = -1;
				break;
			case URL: random = rand() % 3;
				if (random == 1) direction.X = 1;
				else if (random == 2) direction.Y = 1;
				else direction.Y = -1;
				break;
			case DRL: random = rand() % 3;
				if (random == 1) direction.X = -1;
				else if (random == 2) direction.Y = 1;
				else direction.Y = -1;
				break;
			}
		}

		else if (movXY[0, 1] == Right[0, 1])
		{
			switch (order)
			{
			case U: direction.X = 1;
				break;
			case D: direction.X = -1;
				break;
			case R: direction.Y = 1;
				break;
			case L: direction.Y = -1;
				break;
			case UD: random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.X = -1;
				break;
			case UR: random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = 1;
				break;
			case UL: random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = -1;
				break;
			case DR: random = rand() % 2;
				if (random == 1)direction.X = -1;
				else direction.Y = 1;
				break;
			case DL: random = rand() % 2;
				if (random == 1)direction.X = -1;
				else direction.Y = -1;
				break;
			case LR: direction.Y = 1;
				break;
			case UDR:random = rand() % 3;
				if (random == 1) direction.X = 1;
				else if (random == 2) direction.X = -1;
				else direction.Y = 1;
				break;
			case UDL:random = rand() % 3;
				if (random == 1) direction.X = 1;
				else if (random == 2) direction.X = -1;
				else direction.Y = -1;
				break;
			case URL: random = rand() % 3;
				if (random == 1) direction.X = 1;
				else if (random == 2) direction.Y = 1;
				break;
			case DRL: random = rand() % 3;
				if (random == 1) direction.X = -1;
				else if (random == 2) direction.Y = 1;
				break;
			}
		}
		else if (movXY[0, 1] == Left[0, 1])
		{
			switch (order)
			{
			case U: direction.X = 1;
				break;
			case D: direction.X = -1;
				break;
			case R: direction.Y = 1;
				break;
			case L: direction.Y = -1;
				break;
			case UD: random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.X = -1;
				break;
			case UR: random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = 1;
				break;
			case UL: random = rand() % 2;
				if (random == 1) direction.X = 1;
				else direction.Y = -1;
				break;
			case DR: random = rand() % 2;
				if (random == 1)direction.X = -1;
				else direction.Y = 1;
				break;
			case DL: random = rand() % 2;
				if (random == 1)direction.X = -1;
				else direction.Y = -1;
				break;;
			case LR: direction.Y = -1;
				break;
			case UDR:random = rand() % 3;
				if (random == 1) direction.X = 1;
				else if (random == 2) direction.X = -1;
				else direction.Y = 1;
				break;
			case UDL:random = rand() % 3;
				if (random == 1) direction.X = 1;
				else if (random == 2) direction.X = -1;
				else direction.Y = -1;
				break;
			case URL: random = rand() % 3;
				if (random == 1) direction.X = 1;
				else if (random == 2) direction.Y = -1;
				break;
			case DRL: random = rand() % 3;
				if (random == 1) direction.X = -1;
				else if (random == 2) direction.Y = -1;
				break;
			}

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
	MovementAlgorithm(); //Llamamos a la función para que vaya en una direccion aleatoria.
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
