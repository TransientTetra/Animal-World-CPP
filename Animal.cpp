#include "Animal.hpp"
#include <random>
#include <typeinfo>

void Animal::action()
{
	getOlder();

	struct Point destination = randomStep();

	if (world.getOrganism(destination) != nullptr)
		world.getOrganism(destination)->collision(*this);
	else
		position = destination;

}

void Animal::collision(Organism &other)
{
	if (typeid(*this).hash_code() == typeid(other).hash_code())
	{
		if (this->getAge() > 18 && other.getAge() > 18)
			if (!reproduce())
				other.reproduce();
	}
	else
	{
		fight(other);
	}

}
