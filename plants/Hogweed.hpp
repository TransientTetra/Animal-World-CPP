#ifndef HOGWEED_H
#define HOGWEED_H

#include "../Plant.hpp"

class Hogweed : public Plant
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Hogweed(World &world, struct Point position);

	void fight(Organism &other) override;
	void action() override;
	void draw() override;
};
#endif
