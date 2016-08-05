#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
public:
	Enemy(sf::Vector2f windowSize, sf::Vector2f position);

	void update(const sf::Time& dt);
	void collision(Entity& entity);
private:
	const float m_speed = 200.0f;

	sf::Vector2f m_windowSize;
};