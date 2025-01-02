#include "nrpch.pch"
#include <NotReal.h>

#include "NotReal/Events/Event.h"
#include "NotReal/Events/MouseEvent.h"

class ExampleLayer : public NotReal::Layer
{
public:
	ExampleLayer()
		: Layer("Example Layer")
	{
	}

	void OnUpdate() override
	{
		bool pressed = NotReal::Input::IsKeyPressed(NR_KEY_TAB);
		if (pressed)
			NR_ERROR("Tab press detected in client!");
	}

	void OnEvent(NotReal::Event& event) override
	{
		
	}
};

class Sandbox : public NotReal::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

NotReal::Application* NotReal::CreateApplication()
{
	return new Sandbox();
}