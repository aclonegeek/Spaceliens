#pragma once
#include <SFML/Audio.hpp>

#include "EntityManager.hpp"

class Player : public Entity {
public:
	Player(EntityManager& entityManager, sf::Vector2f windowSize);

	void handleInput(const sf::Time& dt);
	void update(const sf::Time& dt);
	void collision(Entity& entity);
	void destroy();
private:
	const float m_speed = 200.0f;
	
	sf::Vector2f m_windowSize;

	EntityManager& m_entityManager;

	bool m_spaceKey;
	int m_bulletCount;

	sf::Sound m_shootSound;
	sf::SoundBuffer m_shootSoundBuffer;

	sf::Sound m_explosionSound;
	sf::SoundBuffer m_explosionSoundBuffer;
};