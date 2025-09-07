#pragma once

#include "Kara3d/Layer.h"
#include "Kara3d/Events/Event.h"

namespace Kara3d {
	class KR_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0.0f;

	};
}