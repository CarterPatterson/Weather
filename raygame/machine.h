#pragma once

#include "MachineStates.h"

class AbstractState;
class Machine {
	friend class AbstractState;
public:
	Machine();

	~Machine();
private:
	AbstractState* mState;
};

// machine.cpp
#include "Machine.h"

Machine::Machine(){
	
}

Machine::~Machine() {
	delete mState;
}
