#include "Sandbox2D.h"

#include "imgui/imgui.h"
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	NR_PROFILE_FUNCTION();

	m_ChillGuy = NotReal::Texture2D::Create("assets/textures/ChillGuy.png");
}

void Sandbox2D::OnDetach()
{
	NR_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(NotReal::Timestep ts)
{
	NR_PROFILE_FUNCTION();

	m_CameraController.OnUpdate(ts);

	{
		NR_PROFILE_SCOPE("Renderer Prep");
		NotReal::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		NotReal::RenderCommand::Clear();
	}

	{
		NR_PROFILE_SCOPE("Renderer DrawCalls");
		NotReal::Renderer2D::BeginScene(m_CameraController.GetCamera());
		//NotReal::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f }, { 0.5f, 0.5f }, glm::radians(45.0f), m_SquareColor);
		//NotReal::Renderer2D::DrawQuad({ 0.7f, 0.0f }, { 0.5f, 0.5f }, m_SquareColor);

		for (int x = 0; x < 200; x++)
		{
			for (int y = 0; y < 200; y++)
			{
				NotReal::Renderer2D::DrawQuad({ x * 0.05f, y * 0.05f }, { 0.05f, 0.05f }, m_ChillGuy);
			}
		}

		NotReal::Renderer2D::DrawQuad({ -0.5f, -0.5f }, { 0.3f, 0.3f }, m_SquareColor);

		NotReal::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	NR_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(NotReal::Event& e)
{
	m_CameraController.OnEvent(e);
}
