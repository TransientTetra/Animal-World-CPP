#ifndef WORLD_H
#define WORLD_H

class Organism;

struct Point
{
	int x;
	int y;
};

class World
{
private:
	Organism *organisms;
	int width;
	int height;
public:
	World(int width, int height);
	~World();

	void drawWorld();
	void performTurn();
};
#endif
