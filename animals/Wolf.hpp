#ifndef WOLF_H
#define WOLF_H

#include "../Animal.hpp"

class Wolf : public Animal
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Wolf(World &world, struct Point position);

	void draw() override;
};
#endif
