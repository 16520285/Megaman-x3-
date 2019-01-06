#pragma once

#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "../GameComponents/Scene.h"
#include "../GameComponents/Sprite.h"
#include "../GameComponents/Animation.h"

#include "../GameComponents/Camera.h"
#include "../GameObjects/Player/Player.h"
#include "../Map.h"
#include "../GameComponents/GameDebugDraw.h"

#include <fstream>
#include <iostream>

#include "../GameComponents/GameLog.h"

#include "../GameObjects/Enemy/Enemy1.h"
#include "../GameObjects/HpTaskBar/HpTaskBar.h"
#include "../GameObjects/HpTaskBar/bossHP/BossHP.h"
class DemoScene : public Scene
{
public:
    DemoScene();
	
    void Update(float dt);
    void LoadContent();
    void Draw();

    void OnKeyDown(int keyCode);
    void OnKeyUp(int keyCode);
    void OnMouseDown(float x, float y);
	void saveQuadTree(QuadTree *quadtree);
	HpTaskBar *hpTaskBar;
	BossHP *bossHP1,*bossHP2;

protected:
	void checkCollision();
	void CheckCameraAndWorldMap();
	void DrawQuadtree(QuadTree *quadtree);
	void DrawCollidable();
    Player *mPlayer;
	float mTimeCounter;
	Map *map;
	Camera *camera;
    std::map<int, bool> keys;
	std::vector<Entity*> mCollidable;
	std::vector<Entity*> mCollidable1;
	std::vector<Entity*> mCollidableEnemy;

	GameDebugDraw *mDebugDraw;

	fstream outfile;
	//void createQuadTree();
};

