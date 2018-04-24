#include "Belladonna.hpp"

Belladonna::Belladonna(World &world, struct Point position)
: Plant(world, position, 99)
{
	species = "Belladonna";
}

void Belladonna::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Belladonna(world, position);
}

void Belladonna::fight(Organism &other)
{
	std::cout << "\033[34m";
	other.name();
	std::cout << " has been poisoned by a belladonna and died!" << std::endl; 
	std::cout << "\033[0m";
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
