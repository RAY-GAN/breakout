#include "Level.h"

using namespace gm;
using namespace sf;
using namespace std;

Level::Level() {

}

Level::Level(BrickType* type1, BrickType* type2, Ball* ball) {

	this->ball = ball;

	int row = 5;
	int col = 5;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Vector2f position = Vector2f(78 * (j+1), 28 * (i+1));
			Vector2f size = Vector2f(78, 28);

		
			int r;
			r = rand();
			if (r % 2 == 0) {
				bricks.push_back(unique_ptr<Brick>(new Brick(position,size,type1)));
			}
			else {
				bricks.push_back(unique_ptr<Brick>(new Brick(position, size,type2)));
			}

			
		}
	}

}

void Level::update(RenderWindow& window, float deltaTime) {

	for (int i = 0; i < bricks.size();)
	{
		Brick* b = bricks[i].get();
		b->update(window,deltaTime);

		if (b->collide(Vector2f(Mouse::getPosition(window)))) {
			b->setFillColor(Color::Green);
		}
		else {
			b->setFillColor(Color::White);
		}



		if (ball->collide(b->getCollider())) {
			ball->Bounce(b, false);
			b->setHealth(b->getHealth() - 1);
			if (b->getHealth() == 1) {
				b->setType(normal);
			}
			else if (b->getHealth()<=0) {
				ball->score += 100;
				bricks.erase(bricks.begin() + i);
				continue;
			}
		}
		i++;
	}

}

void Level::render(RenderWindow& window, float deltaTime) {

	for (int i = 0; i < bricks.size(); ++i)
	{
		bricks[i]->render(window,deltaTime);
	}

}

vector<unique_ptr<Brick>>* Level::getBricks() {

	return &bricks;
}

void Level::reset(BrickType* type1, BrickType* type2) {

	while (bricks.size() > 0) {

		bricks.erase(bricks.begin());
	}

	int row = 5;
	int col = 5;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Vector2f position = Vector2f(78 * (j+1), 28 * (i+1));
			Vector2f size = Vector2f(78, 28);


			int r;
			r = rand();
			if (r % 2 == 0) {
				bricks.push_back(unique_ptr<Brick>(new Brick(position, size, type1)));
			}
			else {
				bricks.push_back(unique_ptr<Brick>(new Brick(position, size, type2)));
			}


		}
	}

}

Level::~Level() {
	
	while (bricks.size() > 0) {

		bricks.erase(bricks.begin());
	}

	
}