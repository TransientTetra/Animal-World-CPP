#ifndef GUARANA_H
#define GUARANA_H

#include "../Plant.hpp"

class Guarana : public Plant
{
private:
	void createNew(Organism **ptr, struct Point position) override;

public:
	Guarana(World &world, struct Point position);

	void draw() override;
	void fight(Organism &other) override;
};
#endif
