#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
public:
	Enemy(sf::Vector2f windowSize, sf::Vector2f position);

	void movement(const sf::Time& dt);
	void update(const sf::Time& dt);
	void collision(Entity& entity);
private:
	float m_speed = 200.0f;

	sf::Vector2f m_windowSize;

	bool m_moveDown;
};