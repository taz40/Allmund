#include "SandboxActor.h"



SandboxActor::SandboxActor()
{
}


SandboxActor::~SandboxActor()
{
}

void SandboxActor::Update(float deltaTime) {
	transform->rot.y += 30.0f * deltaTime;
}