#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include <raylib.h>

#include "Engine/Core/Core.h"

namespace Engine
{
	struct CameraProperties
	{
		Vector3 position = { 1.0f, 1.0f, 1.0f };
		Vector3 target = { 0.0f, 0.0f, 0.0f };
		Vector3 up = { 0.0f, 1.0f, 0.0f };
		float fovY = 45.0f;
		int mode = CAMERA_FREE;
		int projection = CAMERA_PERSPECTIVE;
	};

	class ENGINE_API Camera
	{
	public:
		Camera();
		~Camera();

		void BeginCamera();
		void EndCamera();

		void Update();

	private:
		Camera3D camera;
		CameraProperties properties;
	};
}

#endif
