#include "Sheep.hpp"

Sheep::Sheep(World &world, struct Point position)
: Animal(world, position, 4, 4)
{
}

void Sheep::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Sheep(world, position);
}

void Sheep::draw()
{
	std::cout << "\033[37;1mS\033[0m";
}
