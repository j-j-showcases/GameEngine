#pragma once

namespace MorGine {
	class State
	{
	private:
	public:
		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float fps) = 0;
		virtual void Draw(float fps) = 0;

		virtual void Pauze() {};
		virtual void Resume() {};
	};
}

