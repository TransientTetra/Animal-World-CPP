#ifndef FOX_H
#define FOX_H

#include "../Animal.hpp"

class Fox : public Animal
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Fox(World &world, struct Point position);

	void draw() override;
	void action() override;
};
#endif
