#ifndef SHEEP_H
#define SHEEP_H

#include "../Animal.hpp"

class Sheep : public Animal
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Sheep(World &world, struct Point position);

	void draw() override;
};
#endif
