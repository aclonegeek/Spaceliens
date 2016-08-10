#include "Projectile.hpp"

Projectile::Projectile(sf::Vector2f windowSize, sf::Vector2f position, bool friendly)
	: m_windowSize{ windowSize } {
	active = 1;
	load("projectile.png");
	setPosition(position.x, position.y);

	if (friendly) {
		type = "PlayerProjectile";
		setVelocity({ 0.0f, -m_speed });
	} else {
		type = "EnemyProjectile";
		setVelocity({ 0.0f, m_speed });
	}
}

void Projectile::update(const sf::Time& dt) {
	if (getPosition().y + getGlobalBounds().height <= 0 || getPosition().y + getGlobalBounds().height >= m_windowSize.y) {
		destroy();
	}

	Entity::update(dt);
}

void Projectile::collision(Entity& entity) {
	destroy();
	entity.destroy();
}