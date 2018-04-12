#include "Wolf.hpp"

Wolf::Wolf(World &world, struct Point position)
: Animal(world, position, 9, 5)
{

}

void Wolf::action()
{
	Animal::action();
}

void Wolf::collision(Organism &other)
{
	Animal::collision(other);
}

void Wolf::draw()
{
	std::cout << "\033[30;1mW\033[0m";
}
