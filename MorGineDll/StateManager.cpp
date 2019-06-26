#include "pch.h"
#include "StateManager.h"

namespace MorGine {
	void StateManager::AddState(StateRef newState, bool replacing)
	{
		this->_adding = true;
		this->_replacing = replacing;

		this->_newState = std::move(newState);
	}
	void StateManager::RemoveState()
	{
		this->_removing = true;
	}
	void StateManager::ProcessStateChanges()
	{
		if (this->_removing && !this->_states.empty()) {
			this->_states.pop();
			if (!this->_states.empty())
				this->_states.top()->Resume();
			this->_removing = false;
		}
		if (this->_adding) {
			if (!this->_states.empty()) {
				if (this->_replacing)
					this->_states.pop();
				else
					this->_states.top()->Pauze();
			}
			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			this->_adding = false;
			this->_replacing = false;
		}

	}
	StateRef& StateManager::GetActiveState()
	{
		return this->_states.top();
	}
}
