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

void Plant::fight(Organism &other)
{
	std::cout << "\033[34m";
	other.name();
	std::cout << " is trying to eat a ";
	name();
	std::cout << "!" << std::endl;
	if (power > other.getPower())
	{
		other.name();
		std::cout << " has been poisoned and died!" << std::endl;
		other.die();
	}
	else
	{
		other.name();
		std::cout << " has eaten ";
		name();
		std::cout << "!" <<std::endl;
		die();
	}

	std::cout << "\033[0m";
}

void Plant::collision(Organism &other)
{
	fight(other);
}
