#pragma once//Le indica al Precompilador que esta clase solo quiero que me la incluyas una vez, 
//ayuda a que no de problemas de herencias, etc.
#include "ConsoleUtils.h"
#include "Map.h"
#include <stdlib.h> //Añadimos libreria de numeros random (?)
#include <time.h> //Incluimos libreria Random
#include "TimeManager.h"

class Enemy
{
	/*int x;
	int y;*///No hace falta ponerlo pq ponemos position.

private: //Todo lo que sea privado se pone a partir de aquí y solamente la propia clase podrá acceder a ello(así se hace en C++)
	COORD spawn; //Donde aparece el enemigo una vez lo matan.
	COORD position; //Vector2 de la consola en C++ (int x / int y).
	COORD direction; //Se van a sumar/restar coordenadas de la posición.

	char character = 'X'; //Qué vamos a imprimir
	float powerup_countdown = 0;
	const float powerup_countdown_time = 15;
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::DARK_RED;//Guardar color de la letra (X).
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;//Guardar color del fondo de la letra.

	ConsoleUtils::CONSOLE_COLOR foreground_attack = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR foreground_powerUp = ConsoleUtils::CONSOLE_COLOR::CYAN;

	void RandomDirection(); //Creamos una funcion del enemigo para que decida de forma aleatoria hacia donde va a ir.

public: //Todo lo que sea público se pone a partir de aquí(así se hace en C++)

	enum ENEMY_STATE{ENEMY_NONE, ENEMY_KILLED, ENEMY_DEAD}; // Declaramos un estado que la clase enemy devolvera a main.

	Enemy(); //Creamos constructor que tiene el mismo nombre que la clase.
	Enemy(COORD _spawn); //Funcion de constructor a la que le pasamos la coordenada de donde queremos que aparezca el enemigo en el mapa.
	void Draw();
	void PowerUpPicked();
	ENEMY_STATE Update(Map* _map, COORD _player); //Creamos funcion de Actualizado

	/*PARA CREAR LA FUNCION A PARTIR DEL PROTOTIPO:(ejemplo void Draw();) 
	Preparamos la funcion de Draw, solo ponemos el prototipo, no hay que pasarle nada,
	ponemos cursor encima de la palabra DRAW y pulsamos ALT y luego ENTER.*/
};

