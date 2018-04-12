#include "World.hpp"
#include "Organism.hpp"
#include "animals/Sheep.hpp"
#include "animals/Wolf.hpp"
#include "plants/Grass.hpp"

World::World(int width, int height)
: width(width), height(height)
{
	organisms = new Organism*[width * height];
	for (int i = 0; i < width * height; ++i)
	{
		organisms[i] = nullptr;
	}

	//tu losowanie init spawn
	organisms[1] = new Sheep(*this, Point(0, 0));
	organisms[2] = new Sheep(*this, Point(1, 1));

	idArray = new int*[height];
	for (int i = 0; i < height; ++i)
		idArray[i] = new int[width];

}

World::~World()
{
	for (int i = 0; i < width * height; ++i)
		delete organisms[i];
	delete[] organisms;

	for (int i = 0; i < height; ++i)
		delete idArray[i];
	delete[] idArray;
}

int World::getWidth()
{
	return width;
}

int World::getHeight()
{
	return height;
}

Organism *World::getOrganism(int x, int y)
{
	if (idArray[x][y] != -1)
		return organisms[idArray[x][y]];
	else return nullptr;
}

void World::fillIdArray()
{
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			idArray[i][j] = -1;

	for (int i = 0; i < width * height; ++i)
	{
		if (organisms[i] != nullptr)
		{
			idArray[organisms[i]->getPosition().x][organisms[i]->getPosition().y] = i;
		}
	}
}

void World::drawWorld()
{
	fillIdArray();

	std::cout << "Mikołaj Sperkowski 171725" << std::endl;

	for (int i = 0; i < width + 2; ++i)
		std::cout << '#';
	std::cout << std::endl;

	for (int i = 0; i < height; ++i)
	{
		std::cout << '#';
		for (int j = 0; j < width; ++j)
		{
			if (idArray[i][j] > -1)
				organisms[idArray[i][j]]->draw();
			else
				std::cout << ' ';
		}
		std::cout << '#';
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 2; ++i)
		std::cout << '#';
	std::cout << std::endl;
}

void World::sortOrganisms()
{
	for (int i = 0; i < width * height - 1; ++i)
	{
		if (organisms[i] == nullptr && organisms[i + 1] != nullptr)
		{
			organisms[i] = organisms[i + 1];
			organisms[i + 1] = nullptr;
			i = 0;
		}
	}
	bool chckSort = true;
	while (chckSort)
	{
		chckSort = false;
		for (int i = 0; i < width * height - 1; ++i)
		{
			if (organisms[i] != nullptr && organisms[i + 1] != nullptr)
			{
				bool swap = false;
				if (organisms[i]->getInitiative() < organisms[i + 1]->getInitiative())
					swap = true;
				else if (organisms[i]->getInitiative() == organisms[i + 1]->getInitiative())
					if (organisms[i]->getAge() < organisms[i + 1]->getAge())
						swap = true;
				if (swap)
				{
					chckSort = true;

					Organism *temp = organisms[i];
					organisms[i] = organisms[i + 1];
					organisms[i + 1] = temp;
				}
			}
		}
	}
}

void World::performTurn()
{
	std::cout << std::endl;
	sortOrganisms();
	for (int i = 0; i < width * height; ++i)
	{
		if (organisms[i] != nullptr)
		{
			organisms[i]->action();
		}
	}
//	fillIdArray();

	drawWorld();
}
