#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hiper/Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"

#include "Hiper/ImGui/ImGuiLayer.h"

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

		inline static Application& GetInstance() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:

		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be Defined in Cline
	Application* CreateApplication();
}
