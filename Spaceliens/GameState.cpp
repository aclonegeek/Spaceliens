#include <iostream>

#include "GameState.hpp"
#include "GameOverState.hpp"
#include "GameWonState.hpp"

GameState::GameState(StateManager& stateManager, sf::RenderWindow& window)
	: State{ stateManager, window }
	, m_entityManager{ m_window }
	, m_player{ std::make_unique<Player>(m_entityManager, static_cast<sf::Vector2f>(m_window.getSize())) } {
	std::cout << "[GameState] Initialized" << std::endl;

	m_shootSoundBuffer.loadFromFile("audio/shoot.wav");
	m_shootSound.setBuffer(m_shootSoundBuffer);
	m_shootSound.setVolume(10.0f);

	m_explosionSoundBuffer.loadFromFile("audio/explosion.wav");
	m_explosionSound.setBuffer(m_explosionSoundBuffer);
	m_explosionSound.setVolume(5.0f);

	m_enemyCount = 3;

	float x = 200.0f, y = window.getSize().y / 2.0f;
	
	for (int i = 0; i < m_enemyCount; i++) {
		std::unique_ptr<Enemy> enemy(new Enemy(m_entityManager,
			static_cast<sf::Vector2f>(window.getSize()), { x, y },
			m_shootSound, m_explosionSound, m_shootSoundBuffer, m_explosionSoundBuffer, m_enemyCount));
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
	// If the player is killed, present the game over screen
	if (!m_entityManager.exists("Player")) {
		std::unique_ptr<GameOverState> gameOver(new GameOverState(m_stateManager, m_window));
		m_stateManager.stateToChangeTo(std::move(gameOver));
	}

	// If all enemies are killed, present the game won screen
	if (m_enemyCount == 0) {
		std::unique_ptr<GameWonState> gameWon(new GameWonState(m_stateManager, m_window));
		m_stateManager.stateToChangeTo(std::move(gameWon));
	}

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