#include "Application.h"

#include "Kara3d/Events/ApplicationEvent.h"
#include "Kara3d/Log.h"

namespace Kara3d {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		KR_TRACE(e.ToString()); // просто e выводит ошибку 
		while (true);
	}
}
