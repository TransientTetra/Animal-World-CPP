#include "Guarana.hpp"

Guarana::Guarana(World &world, struct Point position)
: Plant(world, position, 0)
{}

void Guarana::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Guarana(world, position);
}

void Guarana::fight(Organism &other)
{
	other.getPower() += 3;
	die();
}

void Guarana::draw()
{
	std::cout << "\033[31;1m\u2698\033[0m";
}
