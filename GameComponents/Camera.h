#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include "Sprite.h"
class Camera
{
public:
	Camera(int width, int height);

	//center of camera
	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR3 pos);

	int GetWidth();
	int GetHeight();

	D3DXVECTOR3 GetPosition();
	RECT GetBound();
	void Follow(Sprite *following);
	void Unfollow();
	bool IsFollowing();
	void Update(D3DXVECTOR3 movement);
	~Camera();

private:
	int             mWidth, mHeight;
	Sprite *following;
	D3DXVECTOR3     mPosition;
};
