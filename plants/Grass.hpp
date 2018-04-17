#ifndef GRASS_H
#define GRASS_H

#include "../Plant.hpp"

class Grass : public Plant
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Grass(World &world, struct Point position);

	void collision(Organism &other) override;
	void draw() override;
};

#endif
