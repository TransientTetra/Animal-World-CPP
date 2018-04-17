#include "Organism.hpp"
#include <random>
#include <algorithm>

Organism::Organism(World &world, struct Point position, int power, int initiative)
: world(world), position(position), power(power), initiative(initiative), age(0)
{

}

void Organism::die()
{
	world.removeOrganism(position);
}

void Organism::getOlder()
{++age;}

void Organism::fight(Organism &other)
{
	if (power > other.getPower())
		other.die();
	else
		die();
}

bool Organism::reproduce()
{
	short int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	std::random_device r;
	std::mt19937 range(r());
	std::shuffle(d[0], d[3], range);
	for (int i = 0; i < 4; ++i)
	{
		struct Point temp(position.x + d[i][0], position.y + d[i][1]);
		wrapPosition(temp);

		if (world.getOrganism(temp) == nullptr)
		{
			createNew(world.getFree(), temp);
			return true;
		}
	}

	return false;
}

void Organism::wrapPosition(struct Point &position)
{
	if (position.x > world.getHeight() - 1)
		position.x = 0;
	if (position.y > world.getWidth() - 1)
		position.y = 0;
	if (position.x < 0)
		position.x = world.getHeight() - 1;
	if (position.y < 0)
		position.y = world.getWidth() - 1;
}

struct Point Organism::getPosition()
{
	return position;
}

int& Organism::getPower()
{
	return power;
}

int Organism::getAge()
{
	return age;
}

int Organism::getInitiative()
{
	return initiative;
}
