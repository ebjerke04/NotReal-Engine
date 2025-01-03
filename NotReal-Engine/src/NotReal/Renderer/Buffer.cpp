#include "nrpch.pch"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace NotReal
{

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    NR_CORE_ASSERT(false, "RendererAPI::None not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
		}

		NR_CORE_ASSERT(false, "Unknown RendererAPI state");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    NR_CORE_ASSERT(false, "RendererAPI::None not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLIndexBuffer(indices, count);
		}

		NR_CORE_ASSERT(false, "Unknown RendererAPI state");
		return nullptr;
	}

}