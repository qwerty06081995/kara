#pragma once

#include "Core.h"

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

