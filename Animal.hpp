#ifndef ANIMAL_H
#define ANIMAL_H

#include "Organism.hpp"

class Animal : public Organism
{
protected:

public:
	using Organism::Organism;
	
	virtual void action() override;
	virtual void move(int dx, int dy);
	virtual void collision(Organism &other) override;
	virtual void draw() = 0;
};
#endif
