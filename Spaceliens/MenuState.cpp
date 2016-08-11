#include <SFML/Graphics.hpp>
#include <iostream>

#include "MenuState.hpp"
#include "GameState.hpp"

MenuState::MenuState(StateManager& stateManager, sf::RenderWindow& window)
	: State{ stateManager, window } {
	std::cout << "[MenuState] Initialized" << std::endl;

	m_font.loadFromFile("graphics/arial.ttf");
	m_text.setFont(m_font);
	m_text.setColor(sf::Color::Green);
	m_text.setString("SPACELIENS\nPRESS SPACE TO PLAY\nPRESS EXIT TO QUIT");
	m_text.setPosition(m_window.getSize().x / 2.0f - m_text.getGlobalBounds().width / 2.0f,
		m_window.getSize().y / 2.0f - m_text.getGlobalBounds().height / 2.0f);
}

void MenuState::pause() {

}

void MenuState::resume() {

}

void MenuState::processEvents() {
	sf::Event event;

	while (m_window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				m_stateManager.quit();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Space: {
						std::unique_ptr<State> gameState(new GameState(m_stateManager, m_window));
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

void MenuState::update(sf::Time dt) {

}

void MenuState::draw() {
	m_window.clear(sf::Color::Black);
	m_window.draw(m_text);
	m_window.display();
}