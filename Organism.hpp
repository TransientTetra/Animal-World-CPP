#ifndef ORGANISM_H
#define ORGANISM_H

#include "World.hpp"
#include <iostream>

class Organism
{
protected:
	int power;
	int age;
	int initiative;
	struct Point position;
	World &world;
public:
	Organism(World &world, struct Point position, int power, int initiative);

	virtual struct Point getPosition();
	virtual void action() = 0;
	virtual void collision(Organism &other) = 0;
	virtual void draw() = 0;
	virtual int getInitiative();
	virtual int getAge();
};

#endif
