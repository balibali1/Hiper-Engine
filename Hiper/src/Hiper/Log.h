#pragma once

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Hiper
{
	class HIPER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//Core log macros
#define HP_CORE_TRACE(...)	::Hiper::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HP_CORE_WARN(...)	::Hiper::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HP_CORE_INFO(...)	::Hiper::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HP_CORE_ERROR(...)	::Hiper::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HP_CORE_FATAL(...)	::Hiper::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define HP_TRACE(...)	::Hiper::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HP_WARN(...)	::Hiper::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HP_INFO(...)	::Hiper::Log::GetClientLogger()->info(__VA_ARGS__)
#define HP_ERROR(...)	::Hiper::Log::GetClientLogger()->error(__VA_ARGS__)
#define HP_FATAL(...)	::Hiper::Log::GetClientLogger()->fatal(__VA_ARGS__)




