#ifndef HUMAN_H
#define HUMAN_H

#include "../Animal.hpp"

class Human : public Animal
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Human(World &world, struct Point position);

	void draw() override;
};
#endif
