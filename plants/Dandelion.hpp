#ifndef DANDELION_H
#define DANDELION_H

#include "../Plant.hpp"

class Dandelion : public Plant
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Dandelion(World &world, struct Point position);

	void action() override;
	void draw() override;
};
#endif
