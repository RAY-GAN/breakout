#include "PlayerController.h"

using namespace sf;
using namespace gm;

PlayerController::PlayerController() {

	PlayerPaddle = nullptr;
}

PlayerController::PlayerController(Paddle* PlayerPaddle) {

	this->PlayerPaddle = PlayerPaddle;

}

void PlayerController::HandleInput(Event event) {

	if (event.type == Event::KeyPressed) {
		if (event.key.code == Keyboard::Right) {
			PlayerPaddle->setMovmentDirection(MovementDirection::Right);
		}
		else if (event.key.code == Keyboard::Left) {
			PlayerPaddle->setMovmentDirection(MovementDirection::Left);
		}
	}

	if (event.type == Event::KeyReleased) {
		if (event.key.code == Keyboard::Right && PlayerPaddle->getMovementDirection() == MovementDirection::Right) {
			PlayerPaddle->setMovmentDirection(MovementDirection::None);
		}
		if (event.key.code == Keyboard::Left && PlayerPaddle->getMovementDirection() == MovementDirection::Left) {
			PlayerPaddle->setMovmentDirection(MovementDirection::None);
		}
	}


}

void PlayerController::update(sf::RenderWindow& window, float deltaTime) {

	PlayerPaddle->update(window, deltaTime);

}

PlayerController::~PlayerController() {

}
