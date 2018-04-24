#include "Animal.hpp"
#include <random>
#include <algorithm>
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

bool Animal::escape()
{
	short int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int order[4] = {0, 1, 2, 3};
	std::random_device r;
	std::mt19937 range(r());
	std::shuffle(&order[0], &order[3], range);
	for (int i = 0; i < 4; ++i)
	{
		struct Point temp(position.x + d[order[i]][0], position.y + d[order[i]][1]);
		wrapPosition(temp);

		if (world.getOrganism(temp) == nullptr)
		{
			position = temp;
			return true;
		}
	}
	return false;
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
