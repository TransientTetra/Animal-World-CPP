#include "Organism.hpp"
#include <random>
#include <algorithm>

Organism::Organism(World &world, struct Point position, int power, int initiative)
: world(world), position(position), power(power), initiative(initiative), age(0)
{}

void Organism::die()
{
	world.removeOrganism(position);
}

void Organism::getOlder()
{++age;}

void Organism::fight(Organism &other)
{
	std::cout << "\033[31m";
	name();
	std::cout << " has been attacked by a ";
	other.name();
	std::cout << "." << std::endl;
	if (power > other.getPower())
	{
		name();
		other.die();
	}
	else
	{
		other.name();
		die();
	}
	std::cout << " has won!" << std::endl;
	std::cout << "\033[0m";
}

bool Organism::reproduce()
{
	short int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int order[4] = {1, 2, 3, 0};
	std::random_device r;
	std::mt19937 range(r());
	std::shuffle(&order[0], &order[3], range);
	for (int i = 0; i < 4; ++i)
	{
		struct Point temp(position.x + d[order[i]][0], position.y + d[order[i]][1]);
		wrapPosition(temp);

		if (world.getOrganism(temp) == nullptr)
		{
			std::cout << "\033[36;1m";
			name();
			std::cout << " has reproduced!" << std::endl;
			std::cout << "\033[0m";
			createNew(world.getFree(), temp);
			return true;
		}
	}

	return false;
}

struct Point Organism::randomStep()
{
	std::random_device r;
	std::mt19937 range(r());
	std::uniform_int_distribution<int> uni(0, 3);

	int randomDirection = uni(range);
	struct Point destination(position.x, position.y);
	int dx = 0;
	int dy = 0;

	switch (randomDirection)
	{
		case 0:
			dx = 1;
			break;
		case 1:
			dx = -1;
			break;
		case 2:
			dy = 1;
			break;
		case 3:
			dy = -1;
			break;
	}

	destination.x += dx;
	destination.y += dy;

	wrapPosition(destination);

	return destination;
}

void Organism::wrapPosition(struct Point &position)
{
	if (position.x > world.getHeight() - 1)
		position.x -= world.getHeight();
	if (position.y > world.getWidth() - 1)
		position.y -= world.getWidth();
	if (position.x < 0)
		position.x += world.getHeight();
	if (position.y < 0)
		position.y += world.getWidth();
}

struct Point &Organism::getPosition()
{
	return position;
}

std::string Organism::getName()
{
	return species;
}

int &Organism::getPower()
{
	return power;
}

int &Organism::getAge()
{
	return age;
}

int Organism::getInitiative()
{
	return initiative;
}

void Organism::name()
{
	std::cout << species;
}
