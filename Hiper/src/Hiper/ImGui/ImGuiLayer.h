#pragma once

#include "Hiper\Layer.h"

#include "Hiper\Events\ApplicationEvent.h"
#include "Hiper\Events\KeyEvent.h"
#include "Hiper\Events\MouseEvent.h"

namespace Hiper
{
	class HIPER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		bool OnMouseMoveEvent(MouseMoveEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);

	private:
		float m_Time = 0.0f;
	};
}
