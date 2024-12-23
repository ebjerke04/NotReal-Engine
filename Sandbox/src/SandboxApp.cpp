#include "nrpch.pch"
#include <NotReal.h>

class Sandbox : public NotReal::Application
{
public:
	Sandbox()
	{
		NR_INFO("message from client");
	}

	~Sandbox()
	{

	}
};

NotReal::Application* NotReal::CreateApplication()
{
	return new Sandbox();
}