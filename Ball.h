#ifndef BALL_H
#define BALL_H

#include "GameObject.h"

namespace gm {
    class Ball :
        public GameObject
    {
    private:
        sf::RectangleShape body;
        sf::Vector2f velocity;

    public:
        int health;
        int score;
        bool notattached;

        Ball();

        Ball(const sf::Vector2f& position, const sf::Vector2f& size);

        virtual void update(sf::RenderWindow& window, float deltaTime);

        virtual void render(sf::RenderWindow& window, float deltaTime);

        virtual sf::Vector2f& getPosition();

        virtual void setPosition(const sf::Vector2f& position);

        virtual void move(const sf::Vector2f& velocity) override;

        const sf::Vector2f& getVelocity() const;

        void setVelocity(const sf::Vector2f& velocity);

        void Bounce(GameObject* go,bool accelerate);

        bool Intersect(const sf::Vector2f& pos1, const sf::Vector2f& pos2, const sf::Vector2f& pos3, const sf::Vector2f& pos4);

        const sf::Color& getFillColor() const;

        void setFillColor(const sf::Color& color);

        virtual ~Ball();

    };
}

#endif



