#pragma once

#ifdef AM_PLATFORM_WINDOWS

extern Allmund::Application* Allmund::CreateApplication();

	int main(int argc, char** argv) {
		auto app = Allmund::CreateApplication();
		app->Run();
		delete app;
	}
#endif