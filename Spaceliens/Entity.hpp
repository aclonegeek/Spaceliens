#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite {
public:
	Entity() {}

	void load(const std::string& filename) {
		if (!m_texture.loadFromFile("graphics/sprite/" + filename)) {
			throw std::runtime_error("Entity::load - Failed to load " + filename);
		 }
		setTexture(m_texture);
	}

	bool checkCollision(Entity& entity) {
		return getGlobalBounds().intersects(entity.getGlobalBounds());
	}

	virtual void update(const sf::Time& dt) {
		move(m_velocity * dt.asSeconds());
	}

	virtual void collision(Entity& entity) = 0;

	const bool isActive() const				{ return active == 1; }
	const std::string getType() const		{ return type; }
	const sf::Vector2f getVelocity() const	{ return m_velocity; }
	void setVelocity(sf::Vector2f velocity) { m_velocity = velocity; }
	void setVelocity(float vx, float vy)	{ m_velocity.x = vx; m_velocity.y = vy; }
protected:
	int active;
	std::string type;
private:
	sf::Texture m_texture;
	sf::Vector2f m_velocity;
};