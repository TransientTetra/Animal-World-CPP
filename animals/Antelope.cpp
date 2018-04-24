#include "Antelope.hpp"
#include <random>

Antelope::Antelope(World &world, struct Point position)
: Animal(world, position, 4, 4)
{
	species = "Antelope";
}

void Antelope::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Antelope(world, position);
}

void Antelope::action()
{
	getOlder();

	struct Point destination = randomStep();
	destination.x += destination.x - position.x;
	destination.y += destination.y - position.y;
	wrapPosition(destination);
	if (world.getOrganism(destination) != nullptr)
		world.getOrganism(destination)->collision(*this);
	else
		position = destination;
}

void Antelope::fight(Organism &other)
{
	std::random_device r;
	std::mt19937 range(r());
	std::bernoulli_distribution chance(0.5);

	if (chance(range) && escape());
	else
		Organism::fight(other);
		
}

void Antelope::draw()
{
	std::cout << "\033[31;1mA\033[0m";
}
