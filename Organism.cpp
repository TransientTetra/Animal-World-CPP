#include "Organism.hpp"

Organism::Organism(World &world, struct Point position, int power, int initiative)
: world(world), position(position), power(power), initiative(initiative), age(0)
{

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
