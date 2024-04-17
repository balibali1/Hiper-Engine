#pragma once

#include "Hiper\Core.h"
#include "Hiper\Input.h"

namespace Hiper
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressImpl(int keycode) override;
		virtual bool IsMouseButtonPressImpl(int button) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
	};
}