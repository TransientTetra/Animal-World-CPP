#include "Hogweed.hpp"
#include "../Animal.hpp"

Hogweed::Hogweed(World &world, struct Point position)
: Plant(world, position, 10)
{}

void Hogweed::createNew(Organism **ptr, struct Point position)
{
	*ptr = new Hogweed(world, position);
}

void Hogweed::fight(Organism &other)
{
	if (other.getPower() >= power)
	{
		other.die();
		die();
	}
	else
		other.die();
}

void Hogweed::action()
{
	Plant::action();
	short int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	for (int i = 0; i < 4; ++i)
	{
		struct Point temp(position.x + d[i][0], position.y + d[i][1]);
		wrapPosition(temp);
		if (world.getOrganism(temp) != nullptr)
		{
			if(Animal *v = dynamic_cast<Animal*>(world.getOrganism(temp)))
				v->die();
			world.update();
		}
	}
}

void Hogweed::draw()
{
	std::cout << "\033[36m\u269a\033[0m";
}
