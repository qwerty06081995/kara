#pragma once

#include "Core.h"
#include "Kara3d/Events/Event.h"

namespace Kara3d {
	class KR_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}

