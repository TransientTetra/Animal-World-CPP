#include <random>
#include <typeinfo>
#include <fstream>
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
	allocOrganisms();
	randSpawn();

	fillIdArray();
}

void World::allocOrganisms()
{
	organisms = new Organism*[width * height];
	for (int i = 0; i < width * height; ++i)
	{
		organisms[i] = nullptr;
	}

	idArray = new int*[height];
	for (int i = 0; i < height; ++i)
		idArray[i] = new int[width];
}

World::~World()
{
	deleteWorld();
}

void World::deleteWorld()
{
	for (int i = 0; i < width * height; ++i)
		delete organisms[i];
	delete[] organisms;

	for (int i = 0; i < height; ++i)
		delete idArray[i];
	delete[] idArray;
}

void World::randSpawn()
{
	int index = 0;
	bool isHuman = false;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::random_device r;
			std::mt19937 range(r());
			std::bernoulli_distribution chance(0.15);
			if (chance(r))
			{
				std::uniform_int_distribution<int> uni(0, 9);
				switch (uni(range))
				{
					case 0:
						organisms[index] = new Grass(*this, Point(i, j));
						break;
					case 1:
						organisms[index] = new Dandelion(*this, Point(i, j));
						break;
					case 2:
						organisms[index] = new Guarana(*this, Point(i, j));
						break;
					case 3:
						organisms[index] = new Belladonna(*this, Point(i, j));
						break;
					case 4:
						organisms[index] = new Hogweed(*this, Point(i, j));
						break;
					case 5:
						organisms[index] = new Wolf(*this, Point(i, j));
						break;
					case 6:
						organisms[index] = new Sheep(*this, Point(i, j));
						break;
					case 7:
						organisms[index] = new Fox(*this, Point(i, j));
						break;
					case 8:
						organisms[index] = new Antelope(*this, Point(i, j));
						break;
					case 9:
						organisms[index] = new Turtle(*this, Point(i, j));
						break;
				}
				++index;
			}
			else if (!isHuman)
			{
				organisms[index] = new Human(*this, Point(i, j));
				isHuman = true;
				++index;
			}
		}
	}
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

void World::drawWorld(int turnNumber)
{
	fillIdArray();

	std::cout << "\033[35m";
	std::cout << "Mikołaj Sperkowski 171725" << std::endl;
	std::cout << "\033[32m";
	std::cout << "It is turn number " << turnNumber << std::endl;
	std::cout << "\033[0m";

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

char World::getInput()
{
	system("stty raw");
	char key = getchar();
	if (key == '\033')
	{
		getchar();
		key = getchar();
	}
	system("stty cooked");
	switch(key)
	{
		case 'A':
			return 'u';
		case 'B':
			return 'd';
		case 'C':
			return 'r';
		case 'D':
			return 'l';
		case 'q':
		case 'Q':
			return 'q';
		case 'p':
		case 'P':
			return 'p';
		case 'S':
		case 's':
			return 's';
		case 'L':
		case 'l':
			return 'f';
		case 'N':
		case 'n':
			return 'n';
		default:
			return 'i';
	}
}

void World::saveToFile()
{
	std::string filename;
	std::cout << "What filename to save as?" << std::endl;
	std::cin >> filename;
	filename.append(".wsf");
	filename.insert(0, "./saves/");

	std::ofstream file(filename);

	file << width << ' ' << height << ' ';
	for (int i = 0; i < height * width; ++i)
	{
		if (organisms[i] != nullptr)
		{
			file << organisms[i]->getName() << ' ';
			file << organisms[i]->getPosition().x << ' ' << organisms[i]->getPosition().y << ' ';
			file << organisms[i]->getAge() << ' ' << organisms[i]->getPower() << ' ';
		}
	}
	file << "END";

	file.close();
}

void World::loadFile()
{
	deleteWorld();
	int width, height;
	std::string filename;
	std::cout << "What file to open?" << std::endl;
	std::cin >> filename;
	filename.append(".wsf");
	filename.insert(0, "./saves/");

	std::ifstream file(filename);

	file >> width;
	file >> height;

	this->width = width;
	this->height = height;
	allocOrganisms();

	int index = 0;
	while (1)
	{
		std::string type;
		int power, age, x, y;
		file >> type;
		if (type == "END") break;

		file >> x;
		file >> y;
		struct Point position(x, y);
		file >> power;
		file >> age;

		if (type == "Grass")
		{
			organisms[index] = new Grass(*this, position);
		}
		else if (type == "Dandelion")
		{
			organisms[index] = new Dandelion(*this, position);
		}
		else if (type == "Guarana")
		{
			organisms[index] = new Guarana(*this, position);
		}
		else if (type == "Belladonna")
		{
			organisms[index] = new Belladonna(*this, position);
		}
		else if (type == "Hogweed")
		{
			organisms[index] = new Hogweed(*this, position);
		}
		else if (type == "Wolf")
		{
			organisms[index] = new Wolf(*this, position);
		}
		else if (type == "Sheep")
		{
			organisms[index] = new Sheep(*this, position);
		}
		else if (type == "Fox")
		{
			organisms[index] = new Fox(*this, position);
		}
		else if (type == "Turtle")
		{
			organisms[index] = new Turtle(*this, position);
		}
		else if (type == "Antelope")
		{
			organisms[index] = new Antelope(*this, position);
		}
		else if (type == "Human")
		{
			organisms[index] = new Human(*this, position);
		}
		organisms[index]->getPower() = power;
		organisms[index]->getAge() = age;
	
		++index;
	}

	file.close();
	fillIdArray();
}

void World::simulate()
{
	getchar();
	int turnNumber = 0;
	int powerCounter = 0;
	system("clear");
	drawWorld(turnNumber);

	while (1)
	{
		char input = getInput();
		if (input == 'i')
			continue;
		if (input == 'q')
		{
			system("clear");
			return;
		}
		if (input == 's')
		{
			system("clear");
			saveToFile();
			system("clear");
			drawWorld(turnNumber);
			continue;
		}
		if (input == 'f')
		{
			system("clear");
			loadFile();
			turnNumber = 0;
			powerCounter = 0;
			system("clear");
			drawWorld(turnNumber);
			continue;
		}
		if (input == 'p' && powerCounter > 0)
			input = 'n';
		if (input == 'p' && powerCounter == 0)
		{
			powerCounter = 11;
		}
		system("clear");
		
		sortOrganisms();
		for (int i = 0; i < width * height; ++i)
		{
			if (organisms[i] != nullptr)
			{
				if (Human *v = dynamic_cast<Human*>(organisms[i]))
				{
					v->toDo(input);
					if (powerCounter == 5)
						v->getSuperpower() = false;

				}
				organisms[i]->action();
				fillIdArray();
			}
		}
		if (powerCounter > 0)
			--powerCounter;
		++turnNumber;

		if (powerCounter > 5)
			std::cout << powerCounter - 5 << " turns of invincibility remaining" << std::endl;
		if (powerCounter > 0 && powerCounter <= 5)
			std::cout << powerCounter << " turns until power can be used again" << std::endl;

		drawWorld(turnNumber);
	}
	return;
}
