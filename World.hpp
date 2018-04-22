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
	int width;
	int height;
	int **idArray;

	void drawWorld();
	void drawInterface();
	void fillIdArray();
	void sortOrganisms();
public:
	Organism **organisms;
	World(int width, int height);
	~World();

	void performTurn();
	void update();
	int getWidth();
	int getHeight();
	Organism *getOrganism(struct Point position);
	Organism **getFree();
	void removeOrganism(struct Point position);
};
#endif
