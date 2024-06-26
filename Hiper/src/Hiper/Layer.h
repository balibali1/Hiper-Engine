#pragma once

#include "Hiper\Core.h"
#include "Hiper\Events\Event.h"

namespace Hiper
{
	class HIPER_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}
		virtual void OnImGuiRender() {}

		inline const std::string GetName() const { return m_DebugName; }

	private:
		std::string m_DebugName;
	};
}