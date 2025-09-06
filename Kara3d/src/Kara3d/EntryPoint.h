#pragma once

#ifdef KR_PLATFORM_WINDOWS

extern Kara3d::Application* Kara3d::CreateApplication();

void main(int argc, char** argv)
{
	//Planning the Event System | Game Engine series
	//https://www.youtube.com/watch?v=5mlziHwq90k&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=8
	Kara3d::Log::Init();
	KR_CORE_WARN("Core Logger Initialized Ho ho ");
	KR_INFO("Client Logger Works");
	auto app = Kara3d::CreateApplication();
	app->Run();
	delete app;
}
#endif // KR_PLATFORM_WINDOWS

