#ifndef ANIMAL_H
#define ANIMAL_H

#include "Organism.hpp"

class Animal : public Organism
{
protected:
	virtual bool escape();
public:
	using Organism::Organism;
	
	virtual void action() override;
	virtual void collision(Organism &other) override;
};
#endif
