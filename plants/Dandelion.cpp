#include "Dandelion.hpp"

Dandelion::Dandelion(World &world, struct Point position)
: Plant(world, position, 0)
{
	species = "Dandelion";
}

void Dandelion::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Dandelion(world, position);
}

void Dandelion::action()
{
	Plant::action();
	Plant::action();
	--age;
	Plant::action();
	--age;
}

void Dandelion::draw()
{
	std::cout << "\033[33;1m\u26b5\033[0m";
}
