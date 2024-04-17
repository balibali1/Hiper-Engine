#pragma once

#include "Hiper\Core.h"

namespace Hiper
{
	class HIPER_API Input
	{
	public:
		inline static bool IsKeyPress(int keycode) { return s_Instance->IsKeyPressImpl(keycode); }
		inline static bool IsMouseButtonPress(int button) { return s_Instance->IsMouseButtonPressImpl(button); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseXImpl(); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

	protected:
		virtual bool IsKeyPressImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressImpl(int button) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;

	private:
		static Input* s_Instance;
	};
}
