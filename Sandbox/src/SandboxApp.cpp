#include <Allmund.h>

class Sandbox : public Allmund::Application {

public:
	Sandbox() {
		AM_TRACE("Sandbox initialized");
	}

	~Sandbox() {
		
	}

};

Allmund::Application* Allmund::CreateApplication() {
	return new Sandbox();
}