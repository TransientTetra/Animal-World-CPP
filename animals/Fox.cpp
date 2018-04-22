#include "Fox.hpp"
#include <typeinfo>

Fox::Fox(World &world, struct Point position)
: Animal(world, position, 3, 7)
{}

void Fox::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Fox(world, position);
}

void Fox::action()
{
	getOlder();
	struct Point destination = randomStep();
	if (world.getOrganism(destination) != nullptr)
	{
		if (typeid(*this).hash_code() == typeid(world.getOrganism(destination)).hash_code() || world.getOrganism(destination)->getPower() <= power)
			world.getOrganism(destination)->collision(*this);
	}
	else
		position = destination;
}

void Fox::draw()
{
	std::cout << "\033[31mF\033[0m";
}
