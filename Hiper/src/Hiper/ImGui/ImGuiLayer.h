#pragma once

#include "Hiper\Layer.h"

#include "Hiper\Events\ApplicationEvent.h"
#include "Hiper\Events\KeyEvent.h"
#include "Hiper\Events\MouseEvent.h"

namespace Hiper
{
	class HIPER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}
