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
		HP_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Hiper::Event& event) override
	{
		HP_TRACE("{0}", event);
	}
};

class Sandbox : public Hiper::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox(){}
};

Hiper::Application* Hiper::CreateApplication()
{
	return new Sandbox();
}