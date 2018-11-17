#include "SandboxActor.h"



SandboxActor::SandboxActor()
{
}


SandboxActor::~SandboxActor()
{
}

void SandboxActor::Update() {
	transform->rot.y += 1;
}