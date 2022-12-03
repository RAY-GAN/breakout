#ifndef BRICK_H
#define BRICK_H

#include "GameObject.h"

namespace gm {

	struct BrickType {
		int hp;
		sf::Texture* tex;
		sf::Color col;
		sf::SoundBuffer* buf;
	};


	class Brick :
		public GameObject
	{

	private: 
		sf::Sprite bricksprite;
		const BrickType* type;
		int hp;
		bool Alive;

	public:

		Brick();

		Brick(const sf::Vector2f& position, const sf::Vector2f& size, const BrickType* t);

		virtual void update(sf::RenderWindow& window, float deltaTime) override;

		virtual void render(sf::RenderWindow& window, float deltaTime) override;

		virtual void setPosition(const sf::Vector2f& position) override;

		void setAlive(bool isAlive);

		bool getAlive() const;

		void setHealth(int health);

		int getHealth() const;

		void reset(const BrickType* bricktype);

		void setFillColor(const sf::Color& color);

		void setType(const BrickType* type);

		virtual ~Brick();

		

	};
}

#endif
