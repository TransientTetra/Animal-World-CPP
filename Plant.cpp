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
	std::uniform_int_distribution<int> uni(1, 100);

	int chance = uni(range);
	if (age >= 10 && chance == 1)
		reproduce();
}

void Plant::collision(Organism &other)
{
	fight(other);
}
