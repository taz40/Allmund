#pragma once

#ifdef AM_PLATFORM_WINDOWS

extern Allmund::Application* Allmund::CreateApplication();

	int main(int argc, char** argv) {
		Allmund::Log::Init();
		AM_CORE_WARN("Initialized Log");
		AM_ERROR("Initialized Log");
		int a = 5;
		AM_CORE_ERROR("Error Test, a = {0}", a);
		AM_FATAL("This messag is fatal");

		auto app = Allmund::CreateApplication();
		app->Run();
		delete app;
	}

#endif