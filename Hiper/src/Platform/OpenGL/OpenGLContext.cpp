#include "hppch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hiper
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		HP_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int state = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HP_CORE_ASSERT(state, "Fail to initialize Glad!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);

	}
}