#include <memory>
#include "Enemy.hpp"
#include "Projectile.hpp"

Enemy::Enemy(EntityManager& entityManager, sf::Vector2f windowSize, sf::Vector2f position)
	: m_entityManager{ entityManager }
	, m_windowSize{ windowSize }
	, m_moveDown{ false }
	, m_bulletCount{ 0 } {
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

void Enemy::shoot() {
	int roll = rand() % 99;

	if (roll == 69) {
		sf::Vector2f position = getPosition();
		position.x += getGlobalBounds().width / 2.0f + 10.0f;

		std::unique_ptr<Projectile> projectile(new Projectile(m_windowSize, position, false));
		m_entityManager.add("EnemyProjectile" + std::to_string(m_bulletCount), std::move(projectile));
		m_bulletCount++;
	}
}

void Enemy::update(const sf::Time& dt) {
	movement(dt);
	shoot();
	Entity::update(dt);
}

void Enemy::collision(Entity& entity) {

}