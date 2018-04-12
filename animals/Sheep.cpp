#include "Sheep.hpp"

Sheep::Sheep(World &world, struct Point position)
: Animal(world, position, 4, 4)
{
	
}

void Sheep::action()
{
	Animal::action();
}

void Sheep::collision(Organism &other)
{
	Animal::collision(other);
}

void Sheep::draw()
{
	std::cout << "\033[37;1mS\033[0m";
}
