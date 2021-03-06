#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class StateManager;

class State {
public:
	State(StateManager& stateManager, sf::RenderWindow& window);

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void processEvents() = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void draw() = 0;
protected:
	StateManager& m_stateManager;
	sf::RenderWindow& m_window;
};