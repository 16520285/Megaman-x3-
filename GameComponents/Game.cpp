#include "Game.h"
#include "GameGlobal.h"
#include "../GameControllers/SceneManager.h"
#include "../Scenes/DemoScene.h"


Sprite *BG;

Game::Game(int fps)
{
	mFPS = fps;

	SceneManager::GetInstance()->ReplaceScene(new DemoScene());
	/*BG = new Sprite("Resources/background.png", RECT(), GameGlobal::GetWidth(), GameGlobal::GetHeight());
	BG->SetPosition(0,0);*/
	
	InitLoop();
}

Game::~Game()
{
	
}

void Game::Update(float dt)
{
	SceneManager::GetInstance()->GetCurrentScene()->Update(dt); //Demoscene update

	Render();
}

void Game::Render()
{
	auto device = GameGlobal::GetCurrentDevice();
	auto scene = SceneManager::GetInstance()->GetCurrentScene();
	device->Clear(0, NULL, D3DCLEAR_TARGET, scene->GetBackcolor(), 0.0f, 0);

	{
		device->BeginScene();

		//bat dau ve
		GameGlobal::GetCurrentSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

		//draw here
		//map->Draw();
		/*BG->Draw();*/
		scene->Draw();
	
		//ket thuc ve
		GameGlobal::GetCurrentSpriteHandler()->End();

		device->EndScene();
	}

	device->Present(0, 0, 0, 0);
}

void Game::InitLoop()
{
	MSG msg;

	float tickPerFrame = 1.0f / mFPS, delta = 0;

	while (GameGlobal::isGameRunning)
	{
		GameTime::GetInstance()->StartCounter();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//Poll_Keyboard();
		if (Key_Down(DIK_F))
		{

			//if (!camera->IsFollowing()) camera->Follow(player);
			//player->SetPosition(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2);


		}
		if (Key_Down(DIK_U))
		{
		//	if (camera->IsFollowing()) camera->Unfollow();
		}
		/*D3DXVECTOR3 movement = D3DXVECTOR3(0, 0, 0);
		if (Key_Down(DIK_UP)) movement += D3DXVECTOR3(0, -2, 0);
		if (Key_Down(DIK_DOWN)) movement += D3DXVECTOR3(0, 2, 0);
		if (Key_Down(DIK_LEFT)) movement += D3DXVECTOR3(-2, 0, 0);
		if (Key_Down(DIK_RIGHT)) movement += D3DXVECTOR3(2, 0, 0);
		if (camera->IsFollowing())
		{
			camera->Update(movement);
		}
		else player->Update(movement);*/
		delta += GameTime::GetInstance()->GetCouter();

		if (delta >= tickPerFrame)
		{
			Update((delta));
			delta = 0;
		}
		else
		{
			Sleep(tickPerFrame - delta);
			delta = tickPerFrame;
		}
	}
	
}