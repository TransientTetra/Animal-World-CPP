#include "Grass.hpp"

Grass::Grass(World &world, struct Point position)
: Plant(world, position, 0)
{

}

void Grass::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Grass(world, position);
}

void Grass::collision(Organism &other)
{
	Plant::collision(other);
}

void Grass::draw()
{
	std::cout << "\033[32mg\033[0m";
}
