#ifndef BELLADONNA_H
#define BELLADONNA_H

#include "../Plant.hpp"

class Belladonna : public Plant
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Belladonna(World &world, struct Point position);

	void fight(Organism &other) override;
	void draw() override;
};

#endif
