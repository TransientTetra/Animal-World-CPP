#include "Human.hpp"

Human::Human(World &world, struct Point position)
: Animal(world, position, 5, 4)
{}

void Human::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Human(world, position);
}

void Human::draw()
{
	std::cout << "\033[37;1m\u263a\033[0m";
}
