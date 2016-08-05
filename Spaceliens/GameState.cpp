#include <iostream>

#include "GameState.hpp"

GameState::GameState(StateManager& stateManager, sf::RenderWindow& window)
	: State{ stateManager, window }
	, m_entityManager{ m_window }
	, m_player{ std::make_unique<Player>(static_cast<sf::Vector2f>(m_window.getSize())) } {
	std::cout << "[GameState] Initialized" << std::endl;

	int enemies = 3;

	float x = 200.0f, y = window.getSize().y / 2.0f;
	
	for (int i = 0; i < enemies; i++) {
		std::unique_ptr<Enemy> enemy(new Enemy(static_cast<sf::Vector2f>(window.getSize()), { x, y }));
		x += 50.0f;
		m_entityManager.add("Enemy" + std::to_string(i), std::move(enemy));
	}

	m_entityManager.add("Player", std::move(m_player));
}

void GameState::pause() {

}

void GameState::resume() {

}

void GameState::processEvents() {
	sf::Event event;

	while (m_window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			m_stateManager.quit();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code) {
				case sf::Keyboard::Escape:
					m_stateManager.quit();
					break;
			}
		}
	}
}

void GameState::update(sf::Time dt) {
	m_entityManager.update(dt);
}

void GameState::draw() {
	m_window.clear(sf::Color::Black);
	m_entityManager.draw();
	m_window.display();
}