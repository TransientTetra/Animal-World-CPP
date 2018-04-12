#ifndef SHEEP_H
#define SHEEP_H

#include "../Animal.hpp"

class Sheep : public Animal
{
private:

public:
	Sheep(World &world, struct Point position);

	void action() override;
	void collision(Organism &other) override;
	void draw() override;
};
#endif
