#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameWonState.hpp"
#include "GameState.hpp"

GameWonState::GameWonState(StateManager& stateManager, sf::RenderWindow& window)
	: State{ stateManager, window } {
	std::cout << "[GameWonState] Initialized" << std::endl;

	m_font.loadFromFile("graphics/arial.ttf");
	m_text.setFont(m_font);
	m_text.setColor(sf::Color::Green);
	m_text.setString("GAME WON\nPRESS SPACE TO PLAY AGAIN\nPRESS EXIT TO QUIT");
	m_text.setPosition(m_window.getSize().x / 2.0f - m_text.getGlobalBounds().width / 2.0f,
		m_window.getSize().y / 2.0f - m_text.getGlobalBounds().height / 2.0f);
}

void GameWonState::pause() {

}

void GameWonState::resume() {

}

void GameWonState::processEvents() {
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

void GameWonState::update(sf::Time dt) {

}

void GameWonState::draw() {
	m_window.clear(sf::Color::Black);
	m_window.draw(m_text);
	m_window.display();
}