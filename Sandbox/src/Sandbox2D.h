#pragma once

#include <NotReal.h>

class Sandbox2D : public NotReal::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(NotReal::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(NotReal::Event& e) override;
private:
	NotReal::OrthographicCameraController m_CameraController;

	NotReal::Ref<NotReal::VertexArray> m_SquareVA;
	NotReal::Ref<NotReal::Shader> m_FlatColorShader;

	NotReal::Ref<NotReal::Texture2D> m_ChillGuy;

	glm::vec4 m_SquareColor = { 0.8f, 0.2f, 0.3f, 1.0f };
};