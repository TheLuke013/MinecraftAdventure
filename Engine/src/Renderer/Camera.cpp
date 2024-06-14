#include "Engine/Renderer/Camera.h"

namespace Engine
{
	Camera::Camera()
	{
		camera.position = properties.position;
		camera.target = properties.target;
		camera.up = properties.up;
		camera.fovy = properties.fovY;                               
		camera.projection = properties.projection;
	}

	Camera::~Camera()
	{
	}

	void Camera::BeginCamera()
	{
		BeginMode3D(camera);
	}

	void Camera::EndCamera()
	{
		EndMode3D();
	}

	void Camera::Update()
	{
		UpdateCamera(&camera, properties.mode);
	}
}