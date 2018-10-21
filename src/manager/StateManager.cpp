#include "StateManager.h"

StateManager::StateManager() {

}

void StateManager::onEvent(SDL_Event event) {
	if (!m_states.empty())
		m_states.back()->onEvent(event);
}

void StateManager::onUpdate() {
	if (!m_states.empty())
		m_states.back()->onUpdate();
}

void StateManager::onRender() {
	if (!m_states.empty())
		m_states.back()->onRender();
}

void StateManager::onClean() {
	while (!m_states.empty()) {
		m_states.back()->onClean();
		m_states.pop_back();
	}
}

void StateManager::ChangeState(State *state) {
	if (!m_states.empty()) {
		m_states.back()->onClean();
		m_states.pop_back();
	}

	m_states.push_back(state);
	m_states.back()->onInit();
	m_states.back()->Active();
}

void StateManager::PushState(State *state) {
	if (!m_states.empty())
		m_states.back()->Deactive();

	m_states.push_back(state);
	m_states.back()->onInit();
	m_states.back()->Active();
}


void StateManager::PopState() {
	if (!m_states.empty()) {
		m_states.back()->onClean();
		m_states.pop_back();
	}

	if (!m_states.empty())
		m_states.back()->Active();
}

State* StateManager::Get() {

}
