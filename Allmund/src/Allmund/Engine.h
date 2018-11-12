#pragma once
#include "Core.h"

namespace Allmund {

	enum ALLMUND_API RenderAPI {
		DirectX,
		Metal,
		OpenGL
	};

	class ALLMUND_API Allmund
	{
	public:
		static RenderAPI renderAPI;
		static bool Init();
		static void Terminate();
	};

}