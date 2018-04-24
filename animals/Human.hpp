#ifndef HUMAN_H
#define HUMAN_H

#include "../Animal.hpp"

class Human : public Animal
{
private:
	bool superpower;
	char doing;
	void createNew(Organism **ptr, struct Point position) override;

public:
	Human(World &world, struct Point position);

	void draw() override;
	void action() override;
	void die() override;
	void toDo(char com);

	bool &getSuperpower();
};
#endif
