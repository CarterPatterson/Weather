#pragma once

#include "Machine.h"
#include <exception>
#include <stdexcept>

class Machine;

class AbstractState {
public:
	virtual ~AbstractState();
protected:
	void setState(Machine& machine, AbstractState* st);
};

class Normal : public AbstractState {
public:
	virtual ~Normal();
};


// MachineStates.cpp
#include "MachineStates.h"

AbstractState::~AbstractState() {
}

void AbstractState::setState(Machine& machine, AbstractState* state) {
	AbstractState* aux = machine.mState;
	machine.mState = state;
	delete aux;
}

Normal::~Normal() {
}