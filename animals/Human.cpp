#include "Human.hpp"

Human::Human(World &world, struct Point position)
: Animal(world, position, 5, 4), superpower(false), doing('n')
{
	species = "Human";
}

bool &Human::getSuperpower()
{return superpower;}

void Human::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Human(world, position);
}

void Human::toDo(char com)
{
	doing = com;
}

void Human::die()
{
	if (superpower)
	{
		escape();
	}
	else
		Organism::die();
}

void Human::action()
{
	getOlder();
	int dx = 0;
	int dy = 0;
	switch(doing)
	{
		case 'u':
			--dx;
			break;
		case 'd':
			++dx;
			break;
		case 'l':
			--dy;
			break;
		case 'r':
			++dy;
			break;
		case 'p':
			superpower = true;
			break;
	}
	if (dx != 0 || dy != 0)
	{
		struct Point destination = position;
		destination.x += dx;
		destination.y += dy;

		wrapPosition(destination);
		if (world.getOrganism(destination) != nullptr)
			world.getOrganism(destination)->collision(*this);
		else
			position = destination;
	}
}

void Human::draw()
{
	std::cout << "\033[34;1m\u263a\033[0m";
}
