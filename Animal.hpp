#ifndef ANIMAL_H
#define ANIMAL_H

#include "Organism.hpp"

class Animal : public Organism
{
protected:

public:
	using Organism::Organism;
	
	virtual void action() override;
	virtual void collision() override;
	virtual void draw() = 0;
};
#endif
