#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLEER_H

#include "Paddle.h"

namespace gm {
	class PlayerController
	{
	public:

		Paddle* PlayerPaddle;

		PlayerController();

		PlayerController(Paddle* PlayerPaddle);

		void HandleInput(sf::Event event);

		void update(sf::RenderWindow& window, float deltaTime);

		~PlayerController();

	};
}

#endif


