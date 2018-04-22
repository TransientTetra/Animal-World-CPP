#ifndef TURTLE_H
#define TURTLE_H

#include "../Animal.hpp"

class Turtle : public Animal
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Turtle(World &world, struct Point position);

	void draw() override;
	void action() override;
	void collision(Organism &other) override;
};
#endif
