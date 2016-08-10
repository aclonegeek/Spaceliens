#pragma once
#include "EntityManager.hpp"

class Enemy : public Entity {
public:
	Enemy(EntityManager& entityManager, sf::Vector2f windowSize, sf::Vector2f position);

	void movement(const sf::Time& dt);
	void shoot();
	void update(const sf::Time& dt);
	void collision(Entity& entity);
private:
	EntityManager& m_entityManager;

	float m_speed = 200.0f;
	bool m_moveDown;
	int m_bulletCount;

	sf::Vector2f m_windowSize;
};