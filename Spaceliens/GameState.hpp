#pragma once
#include "StateManager.hpp"
#include "EntityManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class GameState : public State {
public:
	GameState(StateManager& stateManager, sf::RenderWindow& window);

	void pause();
	void resume();

	void processEvents();
	void update(sf::Time dt);
	void draw();
private:
	EntityManager m_entityManager;

	std::unique_ptr<Player> m_player;
	int m_enemyCount;

	sf::Sound m_shootSound;
	sf::SoundBuffer m_shootSoundBuffer;
	sf::Sound m_explosionSound;
	sf::SoundBuffer m_explosionSoundBuffer;
};
