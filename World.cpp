#include "World.hpp"
#include "animals/Sheep.hpp"
#include "animals/Wolf.hpp"
#include "animals/Human.hpp"
#include "animals/Fox.hpp"
#include "animals/Turtle.hpp"
#include "animals/Antelope.hpp"
#include "plants/Grass.hpp"
#include "plants/Dandelion.hpp"
#include "plants/Guarana.hpp"
#include "plants/Belladonna.hpp"
#include "plants/Hogweed.hpp"


World::World(int width, int height)
: width(width), height(height)
{
	organisms = new Organism*[width * height];
	for (int i = 0; i < width * height; ++i)
	{
		organisms[i] = nullptr;
	}

	//tu losowanie init spawn
	organisms[0] = new Sheep(*this, Point(0, 1));
	organisms[1] = new Sheep(*this, Point(3, 1));
	//organisms[2] = new Wolf(*this, Point(11, 11));
	//organisms[3] = new Wolf(*this, Point(10, 10));
//	organisms[4] = new Grass(*this, Point(10, 15));
	//organisms[5] = new Dandelion(*this, Point(5, 20));
	//organisms[6] = new Guarana(*this, Point(15, 5));
//	organisms[7] = new Belladonna(*this, Point(5, 20));
//	organisms[8] = new Hogweed(*this, Point(15, 20));
//	organisms[9] = new Fox(*this, Point(2, 2));
	//organisms[10] = new Fox(*this, Point(3, 3));
	//organisms[11] = new Turtle(*this, Point(3, 3));
	organisms[12] = new Antelope(*this, Point(4, 4));
	//organisms[13] = new Antelope(*this, Point(5, 5));


	idArray = new int*[height];
	for (int i = 0; i < height; ++i)
		idArray[i] = new int[width];
	fillIdArray();
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

Organism *World::getOrganism(struct Point position)
{
	if (idArray[position.x][position.y] != -1)
		return organisms[idArray[position.x][position.y]];
	else return nullptr;
}

Organism **World::getFree()
{
	for (int i = 0; i < width * height; ++i)
		if (organisms[i] == nullptr)
			return &organisms[i];
	return nullptr;
}

void World::removeOrganism(struct Point position)
{
	delete organisms[idArray[position.x][position.y]];
	organisms[idArray[position.x][position.y]] = nullptr;
	fillIdArray();
	sortOrganisms();
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

void World::update()
{
	sortOrganisms();
	fillIdArray();
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
			fillIdArray();
		}
	}

	drawWorld();
}
