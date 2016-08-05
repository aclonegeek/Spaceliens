#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f windowSize, sf::Vector2f position)
	: m_windowSize{ windowSize } {
	active = 1;
	type = "Enemy";
	load("enemy.png");
	setPosition(position);
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