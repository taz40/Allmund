#include <Allmund.h>

class Sandbox : public Allmund::Application {

public:
	Sandbox() {
		
	}

	~Sandbox() {
		
	}

};

Allmund::Application* Allmund::CreateApplication() {
	return new Sandbox();
}