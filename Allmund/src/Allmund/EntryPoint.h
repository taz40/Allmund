#pragma once
#include "Engine.h"

#ifdef AM_PLATFORM_WINDOWS

extern Allmund::Application* Allmund::CreateApplication();

	int main(int argc, char** argv) {
		Allmund::Log::Init();
		AM_CORE_TRACE("Initialized Log");
		if (Allmund::Allmund::Init()) {
			auto app = Allmund::CreateApplication();
			app->Run();
			delete app;
			Allmund::Allmund::Terminate();
		}else {
			AM_CORE_FATAL("Allmund failed to initialize.");
		}
	}

#endif