#pragma once
#include <stack>
#include <SFML/Graphics.hpp>

#include "State.h"

namespace MorGine {
	typedef std::unique_ptr<State> StateRef;
	class StateManager
	{
	public:
		StateManager() { _removing = _adding = _replacing = false; }
		~StateManager() {}

		void AddState(StateRef newState, bool replacing = true);
		void RemoveState();

		void ProcessStateChanges();

		StateRef& GetActiveState();
	private:
		std::stack<StateRef> _states;
		StateRef _newState;

		bool _removing;
		bool _adding;
		bool _replacing;
	};
}

