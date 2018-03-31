#ifndef SHEEP_H
#define SHEEP_H

#include "../Animal.hpp"
#include <iostream>

class Sheep : public Animal
{
private:

public:
	Sheep(World &world, struct Point position);

	void action() override;
	void collision() override;
	void draw() override;
	void foo() {std::cout << power << " " << initiative << std::endl;}
};
#endif
