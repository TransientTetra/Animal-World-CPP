#include "Guarana.hpp"

Guarana::Guarana(World &world, struct Point position)
: Plant(world, position, 0)
{
	species = "Guarana";
}

void Guarana::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Guarana(world, position);
}

void Guarana::fight(Organism &other)
{
	std::cout << "\033[34m";
	other.name();
	std::cout << " has eaten guarana and gained 3 to it's power!" << std::endl;
	std::cout << "\033[0m";
	other.getPower() += 3;
	die();
}

void Guarana::draw()
{
	std::cout << "\033[31;1m\u2698\033[0m";
}
