#include "Paddle.h"

using namespace sf;
using namespace gm;

Paddle::Paddle() : direction(MovementDirection::None) {

}

Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2f& size) : GameObject(position, size), direction(MovementDirection::None) {
	body.setPosition(position);
	body.setSize(size);
}

void Paddle::update(sf::RenderWindow& window, float deltaTime) {
	move(Vector2f(PlayerMovementSpeedPerSecond * direction * deltaTime, 0));

	if (getPosition().x < 0) {

		setPosition(Vector2f(0, getPosition().y));

	}

	else if (getPosition().y > 640) {
		setPosition(Vector2f(640, getPosition().y));

	}
}

void Paddle::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Paddle::setPosition(const sf::Vector2f& position) {
	GameObject::setPosition(position);
	body.setPosition(position);
}


void Paddle::move(const sf::Vector2f& velocity) {
	GameObject::move(velocity);
	// Don't forget to update the Paddle's shape position to match the new position
	body.setPosition(position);
}

void Paddle::setMovmentDirection(MovementDirection direction) {
	this->direction = direction;
}

MovementDirection Paddle::getMovementDirection() const {
	return direction;
}

const Color& Paddle::getFillColor() const {
	return body.getFillColor();
}

void Paddle::setFillColor(const Color& color) {
	body.setFillColor(color);
}

Paddle::~Paddle() {

}
