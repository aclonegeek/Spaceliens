#pragma once
#include "StateManager.hpp"

class GameWonState : public State {
public:
	GameWonState(StateManager& stateManager, sf::RenderWindow& window);

	void pause();
	void resume();

	void processEvents();
	void update(sf::Time dt);
	void draw();
private:
	sf::Font m_font;
	sf::Text m_text;
};
