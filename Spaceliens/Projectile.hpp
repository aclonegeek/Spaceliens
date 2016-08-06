#pragma once
#include "Entity.hpp"

class Projectile : public Entity {
public:
	Projectile(sf::Vector2f windowSize, sf::Vector2f position, bool friendly);

	void update(const sf::Time& dt);
	void collision(Entity& entity);
private:
	const float m_speed = 500.0f;

	sf::Vector2f m_windowSize;
};
