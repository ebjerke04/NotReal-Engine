#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace NotReal
{
	class NOTREAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Define in client...
	Application* CreateApplication();
}

