#ifndef WORLD_H
#define WORLD_H


class Organism;

struct Point
{
	int x;
	int y;

	Point(int x, int y) {this->x = x, this->y = y;}
};

class World
{
private:
	Organism **organisms;
	int **idArray;
	int width;
	int height;

	void drawWorld();
	void drawInterface();
	void fillIdArray();
	void sortOrganisms();
public:
	World(int width, int height);
	~World();

	void performTurn();
	int getWidth();
	int getHeight();
	Organism *getOrganism(struct Point position);
};
#endif
