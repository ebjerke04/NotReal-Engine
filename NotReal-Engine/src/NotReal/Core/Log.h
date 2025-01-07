#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace NotReal
{

	class NOTREAL_API Log
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

#define NR_CORE_TRACE(...)   ::NotReal::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NR_CORE_INFO(...)    ::NotReal::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NR_CORE_WARN(...)    ::NotReal::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NR_CORE_ERROR(...)   ::NotReal::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NR_CORE_FATAL(...)   ::NotReal::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define NR_TRACE(...)        ::NotReal::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NR_INFO(...)         ::NotReal::Log::GetClientLogger()->info(__VA_ARGS__)
#define NR_WARN(...)         ::NotReal::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NR_ERROR(...)        ::NotReal::Log::GetClientLogger()->error(__VA_ARGS__)
#define NR_FATAL(...)        ::NotReal::Log::GetClientLogger()->fatal(__VA_ARGS__)