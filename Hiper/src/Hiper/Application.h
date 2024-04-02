#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hiper/Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"


namespace Hiper
{
	class HIPER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:

		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	// To be Defined in Cline
	Application* CreateApplication();
}
