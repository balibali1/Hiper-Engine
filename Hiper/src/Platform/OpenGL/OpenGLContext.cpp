#include "hppch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Hiper
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		HP_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int state = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HP_CORE_ASSERT(state, "Fail to initialize Glad!");

		HP_CORE_INFO("OpenGL Info:");
		HP_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		HP_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		HP_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);

	}
}