#include "State.h"

State::State(App& app) : mApp(&app) {

}

void State::Active() {
	active = true;
}

void State::Deactive() {
	active = false;
}