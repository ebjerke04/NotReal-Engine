#pragma once

#ifdef NR_PLATFORM_WINDOWS
	
extern NotReal::Application* NotReal::CreateApplication();

int main(int argc, char** argv)
{
	NotReal::Log::Init();

	auto app = NotReal::CreateApplication();
	app->Run();
	delete app;
}

#endif