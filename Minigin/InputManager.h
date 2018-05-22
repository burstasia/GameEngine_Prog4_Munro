#pragma once
#include <XInput.h>
#include "Singleton.h"
#include "./Objects/Actor.h"
#include <map>

class Command
{
public:
	virtual ~Command() {}
	virtual void Execute(std::shared_ptr < dae::Actor > actor) = 0;
};

class CommandRight : public Command
{
public:
	virtual void Execute(std::shared_ptr<dae::Actor> actor) override { actor->SetDirection(right); };

};

class CommandLeft : public Command
{
public:
	virtual void Execute(std::shared_ptr<dae::Actor> actor) override { actor->SetDirection(left); };

};

class CommandUp : public Command
{
public:
	virtual void Execute(std::shared_ptr<dae::Actor> actor) override { actor->SetDirection(up); };

};

class CommandDown : public Command
{
public:
	virtual void Execute(std::shared_ptr<dae::Actor> actor) override { actor->SetDirection(down); };

};
namespace dae
{
	enum class ControllerButton
	{
		ButtonA,
		ButtonB,
		ButtonX,
		ButtonY,
		KeypadUp,
		KeypadDown,
		KeypadLeft,
		KeypadRight
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		virtual ~InputManager() override;
		bool ProcessInput();
		bool IsPressed(ControllerButton button) const;
		Command* HandleInput();

	private:
		XINPUT_STATE currentState{};

		Command* m_pUp = new CommandUp();
		Command* m_pDown = new CommandDown();
		Command* m_pLeft = new CommandLeft();
		Command* m_pRight = new CommandRight();

		std::map<int, bool> m_Key;
	};

}
