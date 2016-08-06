#include "EntityManager.hpp"

EntityManager::EntityManager(sf::RenderWindow& window)
	: m_window{ window } {
}

void EntityManager::add(const std::string& name, std::unique_ptr<Entity> entity) {
	m_entities.insert(std::make_pair(name, std::move(entity)));
}

void EntityManager::update(const sf::Time& dt) {
	for (auto& entity : m_entities) {
		if (entity.second->isActive()) {
			entity.second->update(dt);
		} else {
			m_entitiesToRemove.push_back(entity.first);
			remove();
			break;
		}
	}
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