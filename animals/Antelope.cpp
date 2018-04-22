#include "Antelope.hpp"
#include <random>
#include <algorithm>

Antelope::Antelope(World &world, struct Point position)
: Animal(world, position, 4, 4)
{}

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

bool Antelope::escape()
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

void Antelope::fight(Organism &other)
{
	std::random_device r;
	std::mt19937 range(r());
	std::bernoulli_distribution chance(0.5);

	if (chance(range) && escape())
	else
		Organism::fight(other);
		
}

void Antelope::draw()
{
	std::cout << "\033[31;1mA\033[0m";
}
