#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameOverState.hpp"
#include "GameState.hpp"

GameOverState::GameOverState(StateManager& stateManager, sf::RenderWindow& window)
	: State{ stateManager, window } {
	std::cout << "[GameOverState] Initialized" << std::endl;
	m_font.loadFromFile("graphics/arial.ttf");
	m_text.setFont(m_font);
	m_text.setColor(sf::Color::Red);
	m_text.setString("GAME OVER\nPRESS SPACE TO TRY AGAIN\nPRESS EXIT TO QUIT");
	m_text.setPosition(m_window.getSize().x / 2.0f - m_text.getGlobalBounds().width / 2.0f,
		m_window.getSize().y / 2.0f - m_text.getGlobalBounds().height / 2.0f);
}

void GameOverState::pause() {

}

void GameOverState::resume() {

}

void GameOverState::processEvents() {
	sf::Event event;

	while (m_window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			m_stateManager.quit();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code) {
				case sf::Keyboard::Space: {
					std::unique_ptr<GameState> gameState(new GameState(m_stateManager, m_window));
					m_stateManager.stateToChangeTo(std::move(gameState));
					break;
				}
				case sf::Keyboard::Escape:
					m_stateManager.quit();
					break;
			}
		}
	}
}

void GameOverState::update(sf::Time dt) {
	
}

void GameOverState::draw() {
	m_window.clear(sf::Color::Black);
	m_window.draw(m_text);
	m_window.display();
}