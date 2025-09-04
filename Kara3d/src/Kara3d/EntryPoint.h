#pragma once

#ifdef KR_PLATFORM_WINDOWS

extern Kara3d::Application* Kara3d::CreateApplication();

void main(int argc, char** argv)
{
	//Premake | Game Engine Series
	//https://www.youtube.com/watch?v=sULV3aB2qeU&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=7
	Kara3d::Log::Init();
	KR_CORE_WARN("Core Logger Initialized Ho ho ");
	KR_INFO("Client Logger Works");
	auto app = Kara3d::CreateApplication();
	app->Run();
	delete app;
}
#endif // KR_PLATFORM_WINDOWS

