#include "Plant.hpp"
#include <random>

Plant::Plant(World &world, struct Point position, int power)
: Organism(world, position, power, 0)
{

}

void Plant::action()
{
	getOlder();

	std::random_device r;
	std::mt19937 range(r());
	std::bernoulli_distribution chance(0.01);

	if (age >= 10 && chance(r))
		reproduce();
}

void Plant::collision(Organism &other)
{
	fight(other);
}
