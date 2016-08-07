#include "Enemy.hpp"

#include <iostream>

Enemy::Enemy(sf::Vector2f windowSize, sf::Vector2f position)
	: m_windowSize{ windowSize }
	, m_moveDown{ false } {
	active = 1;
	type = "Enemy";
	load("enemy.png");
	setPosition(position);
}

void Enemy::movement(const sf::Time& dt) {
	if (getPosition().x < 0) {
		m_speed *= -1;
		m_moveDown = true;
	} else if (getPosition().x + getGlobalBounds().width > m_windowSize.x) {
		m_speed *= -1;
		m_moveDown = true;
	}

	if (m_moveDown) {
		move(m_speed * 1.1f * dt.asSeconds(), 50.0f);
		m_moveDown = false;
	} else {
		move(m_speed * dt.asSeconds(), 0.0f);
	}
}

void Enemy::update(const sf::Time& dt) {
	movement(dt);
	Entity::update(dt);
}

void Enemy::collision(Entity& entity) {

}