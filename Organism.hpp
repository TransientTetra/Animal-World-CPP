#ifndef ORGANISM_H
#define ORGANISM_H

#include "World.hpp"

class Organism
{
protected:
	int power;
	int initiative;
	struct Point position;
	World &world;
public:
	Organism(World &world, struct Point position, int power, int initiative);

	virtual void action() = 0;
	virtual void collision() = 0;
	virtual void draw() = 0;
};

#endif
