#pragma once
#include "Entity.hpp"

class Player : public Entity {
public:
	Player(sf::Vector2f windowSize);

	void handleInput(const sf::Time& dt);
	void update(const sf::Time& dt);
	void collision(Entity& entity);
private:
	const float m_speed = 200.0f;
	
	sf::Vector2f m_windowSize;
};