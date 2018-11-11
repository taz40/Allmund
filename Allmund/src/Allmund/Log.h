#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "Core.h"

namespace Allmund {

	class ALLMUND_API Log
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
#define AM_CORE_TRACE(...) ::Allmund::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AM_CORE_INFO(...)  ::Allmund::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AM_CORE_WARN(...)  ::Allmund::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AM_CORE_ERROR(...) ::Allmund::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AM_CORE_FATAL(...) ::Allmund::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define AM_TRACE(...) ::Allmund::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AM_INFO(...)  ::Allmund::Log::GetClientLogger()->info(__VA_ARGS__)
#define AM_WARN(...)  ::Allmund::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AM_ERROR(...) ::Allmund::Log::GetClientLogger()->error(__VA_ARGS__)
#define AM_FATAL(...) ::Allmund::Log::GetClientLogger()->critical(__VA_ARGS__)