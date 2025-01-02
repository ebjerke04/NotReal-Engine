#pragma once

#include "NotReal/Layer.h"

#include "NotReal/Events/MouseEvent.h"
#include "NotReal/Events/KeyEvent.h"
#include "NotReal/Events/ApplicationEvent.h"

enum ImGuiKey;

namespace NotReal
{
	class NOTREAL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}

