#include "Turtle.hpp"
#include <random>

Turtle::Turtle(World &world, struct Point position)
: Animal(world, position, 2, 1)
{}

void Turtle::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Turtle(world, position);
}

void Turtle::action()
{
	std::random_device r;
	std::mt19937 range(r());
	std::bernoulli_distribution chance(0.25);

	if (chance(r))
		Animal::action();
	else
		getOlder();
}

void Turtle::collision(Organism &other)
{
	if (other.getPower() >= 5 || typeid(*this).hash_code() == typeid(other).hash_code())
	{
		Animal::collision(other);
	}
	else
	{
		int dx = other.getPosition().x - position.x;
		int dy = other.getPosition().y - position.y;

		other.getPosition().x += dx;
		other.getPosition().y += dy;

		other.wrapPosition(other.getPosition());
	}
}

void Turtle::draw()
{
	std::cout << "\033[32mT\033[0m";
}
