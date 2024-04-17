#include <Hiper.h>
#include "imgui/imgui.h"

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

	virtual void OnImGuiRender() override
	{
		// TODO:
		// 下面三句会引发编译错误，初步估计是由于sandbox用的是Hiper生成的dll，这依靠的HIPER_API的宏定义，将dll export和import
		// 而ImGui并没有使用类似HIPER_API的语句，将dll给sandbox用
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
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
	}

	~Sandbox(){}
};

Hiper::Application* Hiper::CreateApplication()
{
	return new Sandbox();
}