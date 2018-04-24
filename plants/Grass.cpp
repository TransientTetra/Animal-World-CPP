#include "Grass.hpp"

Grass::Grass(World &world, struct Point position)
: Plant(world, position, 0)
{
	species = "Grass";
}

void Grass::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Grass(world, position);
}

void Grass::draw()
{
	std::cout << "\033[32m\u2618\033[0m";
}
