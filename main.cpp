#include <iostream>

#include "Organism.hpp"
#include "World.hpp"
#include "Animal.hpp"
#include "animals/Sheep.hpp"

int main (int argc, char *argv[])
{
	World world(20, 20);
	struct Point position;
	position.x = position.y = 0;
	Sheep sheep(world, position);

	sheep.foo();
	return 0;
}
