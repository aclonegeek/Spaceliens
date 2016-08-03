#include "Player.hpp"

Player::Player(sf::Vector2f windowSize)
	: m_windowSize{ windowSize } {
	active = 1;
	type = "player";
	load("player.png");
	setPosition(m_windowSize.x / 2.0f - getGlobalBounds().width / 2.0f, m_windowSize.y - getGlobalBounds().height - 10.0f);
}

void Player::handleInput(const sf::Time& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		move(-m_speed * dt.asSeconds(), 0.0f);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move(m_speed * dt.asSeconds(), 0.0f);
	}
}

void Player::update(const sf::Time& dt) {
	handleInput(dt);

	if (getPosition().x < 0) {
		move(m_speed * dt.asSeconds(), 0.0f);
	} else if (getPosition().x + getGlobalBounds().width > m_windowSize.x) {
		move(-m_speed * dt.asSeconds(), 0.0f);
	}

	Entity::update(dt);
}

void Player::collision(Entity& entity) {

}