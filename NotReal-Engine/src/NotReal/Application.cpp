#include "nrpch.pch"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace NotReal
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			NR_TRACE(e.GetName());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			NR_TRACE(e.GetName());
		}

		while (true);
	}
}