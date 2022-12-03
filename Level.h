#ifndef LEVEL_H
#define LEVEL_H

#include"Brick.h"
#include"Ball.h"
#include<vector>

namespace gm {
	class Level
	{
	private:

		std::vector<std::unique_ptr<Brick>> bricks;
		Ball* ball;
	


	public:

		BrickType* normal;
		BrickType* tough;

		Level();

		Level(BrickType* type1, BrickType* type2, Ball* ball);

		void update(sf::RenderWindow& window, float deltaTime);

		void render(sf::RenderWindow& window, float deltaTime);
		
		std::vector<std::unique_ptr<Brick>>* getBricks();

		void reset(BrickType* type1, BrickType* type2);

		~Level();




	};
}

#endif

