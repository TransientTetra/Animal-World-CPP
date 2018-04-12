#include "Animal.hpp"
#include <random>
#include <typeinfo>

void Animal::action()
{
	std::random_device r;
	std::mt19937 range(r());
	std::uniform_int_distribution<int> uni(0, 3);

	int randomDirection = uni(range);
	switch (randomDirection)
	{
		case 0:
			move(1, 0);
			break;
		case 1:
			move(-1, 0);
			break;
		case 2:
			move(0, 1);
			break;
		case 3:
			move(0, -1);
			break;
	}
}

void Animal::move(int dx, int dy)
{
	//if (position.x == 0 && dx < 0)
	//{
		//if (world.getOrganism(world.getHeight() - 1, position.y) == nullptr)
			//position.x = world.getHeight() - 1;
		//else
			//;
		//dx = 0;
	//}
	//else if (position.x == world.getHeight() - 1 && dx > 0)
	//{
		//if (world.getOrganism(0, position.y) == nullptr)
			//position.x = 0;
		//else
			//;
		//dx = 0;
	//}
//
	//if (position.y == 0 && dy < 0)
	//{
		//if (world.getOrganism(position.x, world.getWidth() - 1) == nullptr)
			//position.y = world.getWidth() - 1;
		//else
			//;
		//dy = 0;
	//}
	//else if (position.y == world.getWidth() - 1 && dy > 0)
	//{
		//if (world.getOrganism(position.x, 0) == nullptr)
			//position.y = 0;
		//else
			//;
		//dy = 0;
	//}
	//
	position.x += dx;
	position.y += dy;

	if (position.x > world.getHeight() - 1)
		position.x = 0;
	if (position.y > world.getWidth() - 1)
		position.y = 0;
	if (position.x < 0)
		position.x = world.getHeight() - 1;
	if (position.y < 0)
		position.y = world.getWidth() - 1;
}

void Animal::collision(Organism &other)
{
	if (typeid(*this).hash_code() == typeid(other).hash_code())
	{
		std::cerr << "collision" << std::endl;
	}
	else
		std::cerr << "inni" << std::endl;
}
