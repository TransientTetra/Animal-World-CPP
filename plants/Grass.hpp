#ifndef GRASS_H
#define GRASS_H

#include "../Plant.hpp"

class Grass : public Plant
{
private:

public:
	Grass(World &world, struct Point position);

	void action() override;
	void collision(Organism &other) override;
	void draw() override;
};

#endif
