#include "Organism.hpp"

Organism::Organism(World &world, struct Point position, int power, int initiative)
: world(world), position(position), power(power), initiative(initiative), age(0)
{

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

int Organism::getAge()
{
	return age;
}

int Organism::getInitiative()
{
	return initiative;
}
