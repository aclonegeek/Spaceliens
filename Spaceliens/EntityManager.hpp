#pragma once
#include <map>
#include <memory>
#include <vector>

#include "Entity.hpp"

class EntityManager {
public:
	EntityManager(sf::RenderWindow& window);

	void add(const std::string& name, std::unique_ptr<Entity> entity);
	bool exists(const std::string& name);
	void remove();
	void update(const sf::Time& dt);
	void draw();

	const Entity& getEntity(const std::string& name) const;
private:
	std::map<std::string, std::unique_ptr<Entity>> m_entities;
	std::vector<std::string> m_entitiesToRemove;
	sf::RenderWindow& m_window;
};