#include <NotReal.h>

class Sandbox : public NotReal::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

NotReal::Application* NotReal::CreateApplication()
{
	return new Sandbox();
}