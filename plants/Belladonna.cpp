#include "Belladonna.hpp"

Belladonna::Belladonna(World &world, struct Point position)
: Plant(world, position, 99)
{}

void Belladonna::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Belladonna(world, position);
}

void Belladonna::fight(Organism &other)
{
	if (other.getPower() >= power)
	{
		other.die();
		die();
	}
	else
		other.die();
}

void Belladonna::draw()
{
	std::cout << "\033[35m\u260c\033[0m";
}
