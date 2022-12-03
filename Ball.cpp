#include "Ball.h"

#include <random>

using namespace sf;
using namespace gm;
using namespace std;

Ball::Ball() {

}

Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& size) : GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
	health = 3;
	score = 0;
}

void Ball::update(sf::RenderWindow& window, float deltaTime) {

	move(velocity);

	float vertical = getVelocity().y;
	float horizontal = getVelocity().x;

	if (getPosition().y < 0) {

		setPosition(Vector2f(getPosition().x, 0));
		setVelocity(Vector2f(horizontal, -vertical));
	}

	else if (getPosition().x > 640) {
		setPosition(Vector2f(640, getPosition().y));
		setVelocity(Vector2f(-horizontal, vertical));
	}

	else if (getPosition().x < 0) {
		setPosition(Vector2f(0, getPosition().y));
		setVelocity(Vector2f(-horizontal, vertical));
	}
	

}

void Ball::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

Vector2f& Ball::getPosition() {
	return position;
}

void Ball::setPosition(const sf::Vector2f& position) {
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Ball::move(const sf::Vector2f& velocity) {
	GameObject::move(velocity);
	body.setPosition(position);
}

const Vector2f& Ball::getVelocity() const {
	return velocity;
}

void Ball::setVelocity(const sf::Vector2f& velocity) {
	this->velocity = velocity;
}

void Ball::Bounce(GameObject* go,bool accelerate) {

	float x = getVelocity().x;
	float y = getVelocity().y;
	float add = 0.5f;

	Vector2f ballpos = Vector2f(getCollider().left + getCollider().width * 0.5, getCollider().top + getCollider().height * 0.5);
	Vector2f otherpos = Vector2f(go->getCollider().left + go->getCollider().width * 0.5, go->getCollider().top + go->getCollider().height * 0.5);
	Vector2f ltpos = Vector2f(go->getCollider().left, go->getCollider().top);
	Vector2f lbpos = Vector2f(go->getCollider().left, go->getCollider().top + go->getCollider().height);
	Vector2f rtpos = Vector2f(go->getCollider().left + go->getCollider().width, go->getCollider().top);
	Vector2f rbpos = Vector2f(go->getCollider().left + go->getCollider().width, go->getCollider().top + go->getCollider().height);

		//bottom
		if (Intersect(ballpos, otherpos, lbpos, rbpos)) {
			if (add) {
				setVelocity(Vector2f(x, -y - add));
			}
			else {
				setVelocity(Vector2f(x, -y));
			}
		}
		//right
		else if (Intersect(ballpos, otherpos, rtpos, rbpos)) {
			if (add) {
				setVelocity(Vector2f(-x + add, y));
			}
			else {
				setVelocity(Vector2f(-x, y));
			}
		}
		//left
		else if (Intersect(ballpos, otherpos, lbpos, ltpos)) {
			if (add) {
				setVelocity(Vector2f(-x - add, y));
			}
			else {
				setVelocity(Vector2f(-x, y));
			}
		}
		//top
		else if (Intersect(ballpos, otherpos, rtpos, ltpos)) {
			if (add) {
				setVelocity(Vector2f(x, -y - add));
			}
			else {
				setVelocity(Vector2f(x, -y));
			}
		}

	
}

bool Ball::Intersect(const Vector2f& pos1, const Vector2f& pos2, const Vector2f& pos3, const Vector2f& pos4) {
	float uA = ((pos4.x - pos3.x) * (pos1.y - pos3.y) - (pos4.y - pos3.y) * (pos1.x - pos3.x)) / ((pos4.y - pos3.y) * (pos2.x - pos1.x) - (pos4.x - pos3.x) * (pos2.y - pos1.y));
	float uB = ((pos2.x - pos1.x) * (pos1.y - pos3.y) - (pos2.y - pos1.y) * (pos1.x - pos3.x)) / ((pos4.y - pos3.y) * (pos2.x - pos1.x) - (pos4.x - pos3.x) * (pos2.y - pos1.y));

	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
		return true;
	}
	return false;
}

const Color& Ball::getFillColor() const {
	return body.getFillColor();
}

void Ball::setFillColor(const Color& color) {
	body.setFillColor(color);
}



Ball::~Ball() {

}