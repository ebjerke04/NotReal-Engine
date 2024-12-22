#pragma once

#include "Core.h"

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

