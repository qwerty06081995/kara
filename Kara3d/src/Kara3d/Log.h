#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Kara3d {
	class KR_API Log
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

#define KR_CORE_ERROR(...) ::Kara3d::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KR_CORE_WARN(...)  ::Kara3d::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KR_CORE_INFO(...)  ::Kara3d::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KR_CORE_TRACE(...) ::Kara3d::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KR_CORE_FATAL(...) ::Kara3d::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define KR_ERROR(...) ::Kara3d::Log::GetClientLogger()->error(__VA_ARGS__)
#define KR_WARN(...)  ::Kara3d::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KR_INFO(...)  ::Kara3d::Log::GetClientLogger()->info(__VA_ARGS__)
#define KR_TRACE(...) ::Kara3d::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KR_FATAL(...) ::Kara3d::Log::GetClientLogger()->fatal(__VA_ARGS__)

