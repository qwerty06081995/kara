#pragma once

#ifdef KR_PLATFORM_WINDOWS

extern Kara3d::Application* Kara3d::CreateApplication();

void main(int argc, char** argv)
{
	auto app = Kara3d::CreateApplication();
	app->Run();
	delete app;
}
#endif // KR_PLATFORM_WINDOWS

