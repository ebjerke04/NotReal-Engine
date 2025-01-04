#include "nrpch.pch"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace NotReal
{

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();

}