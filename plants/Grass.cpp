#include "Grass.hpp"

Grass::Grass(World &world, struct Point position)
: Plant(world, position, 0)
{

}

void Grass::action()
{

}

void Grass::collision(Organism &other)
{

}

void Grass::draw()
{
	std::cout << "\033[32mg\033[0m";
}
