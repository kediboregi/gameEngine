#ifndef _Entity_H_
    #define _Entity_H_

#include <SDL.h>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include "math.h"

class Component;

inline std::size_t getNewComponentTypeID() {
	static std::size_t lastID = 0u;
	return lastID++;
}

template <typename T>
inline std::size_t getComponentTypeID() noexcept {
	static_assert (std::is_base_of<Component, T>::value, "");
	static std::size_t typeID = getNewComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

class Entity {
private:
	bool mActive = true;

	std::vector<std::unique_ptr<Component>> components;
	std::array<Component*, maxComponents> componentArray;
	std::bitset<maxComponents> componentBitset;

public:
	Entity();

	void onInit();
	void onUpdate(float deltaTime);
	void onRender(SDL_Renderer* renderer);
	void onClean();

	bool isActive() const;
	void destroy();
	void active();

	template <typename T>
	bool hasComponent() {
		return componentBitset[getComponentTypeID<T>()];
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->mEntity = this;
		std::unique_ptr<Component>uPtr { c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitset[getComponentTypeID<T>()] = true;
		c->onInit();
		return *c;
	}

	template<typename T> T& getComponent() const {
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

#endif
