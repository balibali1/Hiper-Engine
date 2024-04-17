#include <Hiper.h>

class ExampleLayer : public Hiper::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		if (Hiper::Input::IsKeyPress(HP_KEY_TAB))
		{
			HP_TRACE("Tab key is pressed!(poll)");
		}
	}

	void OnEvent(Hiper::Event& event) override
	{
		if (event.GetEventType() == Hiper::EventType::KeyPressed)
		{
			Hiper::KeyPressedEvent& e = (Hiper::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HP_KEY_TAB)
			{
				HP_TRACE("Tab key is pressed!(event)");
			}
			HP_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Hiper::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hiper::ImGuiLayer());
	}

	~Sandbox(){}
};

Hiper::Application* Hiper::CreateApplication()
{
	return new Sandbox();
}