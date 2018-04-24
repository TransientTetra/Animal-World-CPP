#ifndef ANTELOPE_H
#define ANTELOPE_H

#include "../Animal.hpp"

class Antelope : public Animal
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Antelope(World &world, struct Point position);

	void draw() override;
	void action() override;
	void fight(Organism &other) override;
};
#endif
