#pragma once

#ifdef NR_PLATFORM_WINDOWS
	
extern NotReal::Application* NotReal::CreateApplication();

int main(int argc, char** argv)
{
	auto app = NotReal::CreateApplication();
	app->Run();
	delete app;
}

#endif