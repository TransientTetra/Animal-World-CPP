#include "World.hpp"
#include <iostream>

int main (int argc, char *argv[])
{
	int width = 0;
	int height = 0;
	system("clear");
	std::cout << "Please give desired width of world:" << std::endl;
	std::cin >> width;
	std::cout << "Please give desired height of world:" << std::endl;
	std::cin >> height;

	World world(width, height);

	system("clear");
	world.simulate();
	return 0;
}
