#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f windowSize)
	: m_windowSize{ windowSize } {
	active = 1;
	type = "Enemy";
	load("enemy.png");
	setPosition(m_windowSize.x / 2.0f - getGlobalBounds().width / 2.0f, m_windowSize.y / 2.0f - getGlobalBounds().height / 2.0f);
}

void Enemy::update(const sf::Time& dt) {
	if (getPosition().x < 0) {
		move(m_speed * dt.asSeconds(), 0.0f);
	} else if (getPosition().x + getGlobalBounds().width > m_windowSize.x) {
		move(-m_speed * dt.asSeconds(), 0.0f);
	}

	Entity::update(dt);
}

void Enemy::collision(Entity& entity) {

}