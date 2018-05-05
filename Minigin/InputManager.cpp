#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>


bool dae::InputManager::ProcessInput()
{
	ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &currentState);

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			m_Key[e.key.keysym.sym] = true;
		}
		if (e.type == SDL_KEYUP) {
			m_Key[e.key.keysym.sym] = false;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			m_Key[e.key.keysym.sym] = false;
		}
	}

	return true;
}

bool dae::InputManager::IsPressed(ControllerButton button) const
{
	switch (button)
	{
	case ControllerButton::ButtonA:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
	case ControllerButton::ButtonB:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_B;
	case ControllerButton::ButtonX:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_X;
	case ControllerButton::ButtonY:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
	case ControllerButton::KeypadUp:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP;
	case ControllerButton::KeypadDown:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN;
	case ControllerButton::KeypadLeft:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT;
	case ControllerButton::KeypadRight:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT;
	
	default: return false;
	}
}

Command * dae::InputManager::HandleInput()
{
	//keyboard support
	if (m_Key[SDLK_w])
	{
		return m_pUp;
	}
	if (m_Key[SDLK_s])
	{
		return m_pDown;
	}
	if (m_Key[SDLK_a])
	{
		return m_pLeft;
	}
	if (m_Key[SDLK_d])
	{
		return m_pRight;
	}

	//TODO: controller support
	return nullptr;

}

