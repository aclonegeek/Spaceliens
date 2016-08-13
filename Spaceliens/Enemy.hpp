#pragma once
#include <SFML/Audio.hpp>

#include "EntityManager.hpp"

class Enemy : public Entity {
public:
	Enemy(EntityManager& entityManager, sf::Vector2f windowSize, sf::Vector2f position,
		sf::Sound& shootSound, sf::Sound& explosionSound, sf::SoundBuffer& shootSoundBuffer,
		sf::SoundBuffer& explosionSoundBuffer, int& enemyCount);

	void movement(const sf::Time& dt);
	void shoot();
	void update(const sf::Time& dt);
	void collision(Entity& entity);
	void destroy();
private:
	EntityManager& m_entityManager;

	float m_speed = 200.0f;
	bool m_moveDown;
	int m_bulletCount;

	int& m_enemyCount;

	sf::Vector2f m_windowSize;

	sf::Sound& m_shootSound;
	sf::SoundBuffer& m_shootSoundBuffer;

	sf::Sound& m_explosionSound;
	sf::SoundBuffer& m_explosionSoundBuffer;
};