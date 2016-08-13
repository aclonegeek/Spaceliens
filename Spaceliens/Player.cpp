#include <memory>
#include "Player.hpp"
#include "Projectile.hpp"

Player::Player(EntityManager& entityManager, sf::Vector2f windowSize)
	: m_windowSize{ windowSize } 
	, m_entityManager{ entityManager }
	, m_bulletCount{ 0 } {
	active = 1;
	type = "Player";
	load("player.png");
	setPosition(m_windowSize.x / 2.0f - getGlobalBounds().width / 2.0f, m_windowSize.y - getGlobalBounds().height - 10.0f);

	m_shootSoundBuffer.loadFromFile("audio/shoot.wav");
	m_shootSound.setBuffer(m_shootSoundBuffer);
	m_shootSound.setVolume(20.0f);

	m_explosionSoundBuffer.loadFromFile("audio/explosion.wav");
	m_explosionSound.setBuffer(m_explosionSoundBuffer);
	m_explosionSound.setVolume(20.0f);
}

void Player::handleInput(const sf::Time& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		move(-m_speed * dt.asSeconds(), 0.0f);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move(m_speed * dt.asSeconds(), 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_spaceKey) {
		sf::Vector2f position = getPosition();
		position.x += getGlobalBounds().width / 2.0f - 4.0f;

		std::unique_ptr<Projectile> projectile(new Projectile(m_windowSize, position, true));
		m_entityManager.add("PlayerProjectile" + std::to_string(m_bulletCount), std::move(projectile));
		m_bulletCount++;

		m_shootSound.play();
	}
}

void Player::update(const sf::Time& dt) {
	handleInput(dt);

	if (getPosition().x < 0) {
		move(m_speed * dt.asSeconds(), 0.0f);
	} else if (getPosition().x + getGlobalBounds().width > m_windowSize.x) {
		move(-m_speed * dt.asSeconds(), 0.0f);
	}

	m_spaceKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

	Entity::update(dt);
}

void Player::collision(Entity& entity) {
	destroy();
	entity.destroy();
}

void Player::destroy() {
	m_explosionSound.play();
	active = 0;
}