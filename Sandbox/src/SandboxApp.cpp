#include <Kara3d.h>

class ExampleLayer : public Kara3d::Layer {
public:
	ExampleLayer() : Layer("Layer") {}

	void OnUpdate() override {
		KR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Kara3d::Event& event) override {
		KR_TRACE("{0}", event.ToString());
	}
};

class SanboxApp : public Kara3d::Application
{
public:
	SanboxApp() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Kara3d::ImGuiLayer());
	}
	~SanboxApp() {}
};

Kara3d::Application* Kara3d::CreateApplication() {
	return new SanboxApp();
}