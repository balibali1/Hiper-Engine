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
		// �������������������󣬳�������������sandbox�õ���Hiper���ɵ�dll����������HIPER_API�ĺ궨�壬��dll export��import
		// ��ImGui��û��ʹ������HIPER_API����䣬��dll��sandbox��
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