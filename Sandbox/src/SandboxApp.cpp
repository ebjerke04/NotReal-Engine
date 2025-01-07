#include <NotReal.h>
#include <NotReal/Core/EntryPoint.h>
#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public NotReal::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		m_SquareVA = NotReal::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		NotReal::Ref<NotReal::VertexBuffer> squareVB;
		squareVB = NotReal::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
		squareVB->SetLayout({
			{ NotReal::ShaderDataType::Float3, "a_Position" },
			{ NotReal::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		NotReal::Ref<NotReal::IndexBuffer> squareIB;
		squareIB = NotReal::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		m_SquareVA->SetIndexBuffer(squareIB);

		m_ShaderLibrary.Load("assets/shaders/FlatColorShader.glsl");
		m_ShaderLibrary.Load("assets/shaders/TextureShader.glsl");
		
		m_Texture = NotReal::Texture2D::Create("assets/textures/ChillGuy.png");

		std::dynamic_pointer_cast<NotReal::OpenGLShader>(m_ShaderLibrary.Get("TextureShader"))->Bind();
		std::dynamic_pointer_cast<NotReal::OpenGLShader>(m_ShaderLibrary.Get("TextureShader"))->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(NotReal::Timestep ts) override
	{
		m_CameraController.OnUpdate(ts);

		NotReal::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		NotReal::RenderCommand::Clear();

		NotReal::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<NotReal::OpenGLShader>(m_ShaderLibrary.Get("FlatColorShader"))->Bind();
		std::dynamic_pointer_cast<NotReal::OpenGLShader>(m_ShaderLibrary.Get("FlatColorShader"))->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				NotReal::Renderer::Submit(m_ShaderLibrary.Get("FlatColorShader"), m_SquareVA, transform);
			}
		}

		m_Texture->Bind();
		NotReal::Renderer::Submit(m_ShaderLibrary.Get("TextureShader"), m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		NotReal::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(NotReal::Event& event) override
	{
		m_CameraController.OnEvent(event);
	}
private:
	NotReal::ShaderLibrary m_ShaderLibrary;

	NotReal::Ref<NotReal::VertexArray> m_SquareVA;

	NotReal::Ref<NotReal::Texture2D> m_Texture;

	NotReal::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public NotReal::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

NotReal::Application* NotReal::CreateApplication()
{
	return new Sandbox();
}