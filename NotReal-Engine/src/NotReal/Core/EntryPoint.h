#pragma once

#ifdef NR_PLATFORM_WINDOWS
	
extern NotReal::Application* NotReal::CreateApplication();

int main(int argc, char** argv)
{
	NotReal::Log::Init();

	NR_PROFILE_BEGIN_SESSION("Startup", "NotReal-Profile-Startup.json");
	auto app = NotReal::CreateApplication();
	NR_PROFILE_END_SESSION();

	NR_PROFILE_BEGIN_SESSION("Runtime", "NotReal-Profile-Runtime.json");
	app->Run();
	NR_PROFILE_END_SESSION();

	NR_PROFILE_BEGIN_SESSION("Shutdown", "NotReal-Profile-Shutdown.json");
	delete app;
	NR_PROFILE_END_SESSION();
}

#endif