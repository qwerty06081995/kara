#include <Kara3d.h>

class SanboxApp : public Kara3d::Application
{
public:
	SanboxApp() {}
	~SanboxApp() {}
};

Kara3d::Application* Kara3d::CreateApplication() {
	return new SanboxApp();
}