#pragma once

#ifdef NR_PLATFORM_WINDOWS
	
extern NotReal::Application* NotReal::CreateApplication();

int main(int argc, char** argv)
{
	NotReal::Log::Init();
	NR_CORE_WARN("core log message");
	int a = 5;
	NR_INFO("client log message & Var={0}", a);

	auto app = NotReal::CreateApplication();
	app->Run();
	delete app;
}

#endif