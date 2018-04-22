#include <iostream>
#include <chrono>
#include <thread>

#include "Organism.hpp"
#include "World.hpp"
#include "Animal.hpp"

int main (int argc, char *argv[])
{
	int width = 15;
	int height = 15;

	World world(width, height);

	while (1)
	{
		world.performTurn();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	return 0;
}
