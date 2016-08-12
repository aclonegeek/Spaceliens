#include "EntityManager.hpp"

EntityManager::EntityManager(sf::RenderWindow& window)
	: m_window{ window } {
}

void EntityManager::add(const std::string& name, std::unique_ptr<Entity> entity) {
	m_entities.insert(std::make_pair(name, std::move(entity)));
}

void EntityManager::update(const sf::Time& dt) {
	for (auto& entity : m_entities) {
		if (entity.second->getType() == "PlayerProjectile") { // Player projectile collision
			for (auto& entity2 : m_entities) {
				if (entity.first != entity2.first && entity2.second->getType() != "Player") {
					if (entity.second->checkCollision(*entity2.second)) {
						entity.second->collision(*entity2.second);
					}
				}
			}
		} else if (entity.second->getType() == "EnemyProjectile") { // Enemy projectile collision
			for (auto& entity2 : m_entities) {
				if (entity.first != entity2.first && entity2.second->getType() != "Enemy") {
					if (entity.second->checkCollision(*entity2.second)) {
						entity.second->collision(*entity2.second);
					}
				}
			}
		} else if (entity.second->getType() == "Player") { // Player-Enemy collision
			for (auto& entity2 : m_entities) {
				if (entity.first != entity2.first && entity2.second->getType() == "Enemy") {
					if (entity.second->checkCollision(*entity2.second)) {
						entity.second->collision(*entity2.second);
					}
				}
			}
		}

		if (entity.second->isActive()) {
			entity.second->update(dt);
		} else {
			m_entitiesToRemove.push_back(entity.first);
			remove();
			break;
		}
	}
}

bool EntityManager::exists(const std::string& name) {
	return m_entities.find(name) != m_entities.end();
}

void EntityManager::remove() {
	for (auto& entity : m_entitiesToRemove) {
		auto& found = m_entities.find(entity);
		m_entities.erase(found);
	}
	m_entitiesToRemove.clear();
}

void EntityManager::draw() {
	for (auto& entity : m_entities) {
		m_window.draw(*entity.second);
	}
}

const Entity& EntityManager::getEntity(const std::string& name) const {
	auto found = m_entities.find(name);
	return *found->second;
}