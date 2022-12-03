#include "Brick.h"

using namespace gm;
using namespace sf;



Brick::Brick() {

}

Brick::Brick(const Vector2f& position, const Vector2f& size, const BrickType* t): GameObject(position, size)
{
	bricksprite.setPosition(position);
	type = t;
	hp = t->hp;
	Alive = true;
}

void Brick::update(sf::RenderWindow& window, float deltaTime) {

	if (hp <= 0) { Alive = false;}
	

}

void Brick::render(sf::RenderWindow& window, float deltaTime) {
	bricksprite.setTexture(*(type->tex));
	bricksprite.setColor(type->col);
	window.draw(bricksprite);
}

void Brick::setPosition(const sf::Vector2f& position) {
	GameObject::setPosition(position);
	bricksprite.setPosition(position);
}

void Brick::setAlive(bool isAlive) {
	Alive = isAlive;
}

bool Brick::getAlive() const{
	return Alive;
}

void Brick::setHealth(int health) {
	hp = health;
}

int Brick::getHealth() const {
	return hp;
}

void Brick::reset(const BrickType* bricktype) {
	hp = bricktype->hp;
	Alive = true;
}

void Brick::setFillColor(const Color& color) {
	bricksprite.setColor(color);
}

void Brick::setType(const BrickType* type) {
	this->type = type;
}

Brick::~Brick() {

}