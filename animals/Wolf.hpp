#ifndef WOLF_H
#define WOLF_H

#include "../Animal.hpp"

class Wolf : public Animal
{
private:

public:
	Wolf(World &world, struct Point position);

	void action() override;
	void collision(Organism &other) override;
	void draw() override;
};
#endif
