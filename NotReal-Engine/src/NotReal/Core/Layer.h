#pragma once

#include "NotReal/Core/Core.h"
#include "NotReal/Events/Event.h"

#include "NotReal/Core/Timestep.h"

namespace NotReal
{
	class NOTREAL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}