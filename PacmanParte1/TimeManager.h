#pragma once
#include <chrono>

/*static: variable globalpara todas las 
instancias de esta clase, siempre es la misma para todas*/
/*unsigned: (ejemplo unsigned int) -- el int no puede guardar valores negativos*/
class TimeManager
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
public:
	unsigned int frameCount; //Contador de fotogramas
	float time; //Contador de tiempo
	float deltaTime; //nos devolverá cuanto ha tardado en hacer un fotograma

	static TimeManager& getInstance();

	void NextFrame();
};

