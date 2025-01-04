#include "nrpch.pch"
#include "VertexArray.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace NotReal
{

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    NR_CORE_ASSERT(false, "RendererAPI::None not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLVertexArray();
		}

		NR_CORE_ASSERT(false, "Unknown RendererAPI state");
		return nullptr;
	}

}