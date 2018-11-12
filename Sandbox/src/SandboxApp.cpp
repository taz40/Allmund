#include <Allmund.h>

class Sandbox : public Allmund::Application {

public:
	Sandbox()
	: Application(800, 600, "Test"){
		AM_TRACE("Sandbox initialized");
	}

	~Sandbox() {
		
	}

};

Allmund::Application* Allmund::CreateApplication() {
	return new Sandbox();
}