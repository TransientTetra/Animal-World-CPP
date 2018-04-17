#include "Wolf.hpp"

Wolf::Wolf(World &world, struct Point position)
: Animal(world, position, 9, 5)
{

}

void Wolf::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Wolf(world, position);
}

void Wolf::draw()
{
	std::cout << "\033[30;1mW\033[0m";
}
