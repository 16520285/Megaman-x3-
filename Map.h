#pragma once
#ifndef __GAME_MAP__
#define __GAME_MAP__

#include <d3dx9.h>
#include <d3d9.h>
#include <vector>
#include <math.h>

#include "GameComponents/Sprite.h"
#include "GameComponents/Camera.h"
#include "GameComponents/Sprite.h"
#include "MapReader/Tmx.h.in"
#include "GameComponents/QuadTree.h"
#include "GameObjects/Enemy/Enemy1.h"
#include "GameObjects/Enemy2/Enemy2.h"
#include "GameObjects/Enemy3/Enemy3.h"
#include "GameObjects/Player/Player.h"
#include "GameObjects/Boss1/Boss1.h"
#include "GameObjects//Boss3/Boss3.h"
#include <fstream>
#include <iostream>
#include "GameObjects/Elevator/Elevator.h"
#include "GameObjects/Door/Door.h"
#include "GameObjects/Brick2/Brick2.h"
#include "GameObjects/Ship/Ship.h"
#include "GameObjects/Ship/Plane.h"
#include "GameObjects/Brick/Brick.h"
#include "GameObjects/Boss2/Boss2.h"
#include "GameObjects/Boss3/SpecialBullet/SpecialBullet.h"
class Map
{
public:

	Map(char* filePath,Player *mPlayer);
	Tmx::Map* GetMap();
	RECT GetWorldMapBound();
	int GetWidth();
	int GetHeight();
	int GetTileWidth();
	int GetTileHeight();
	std::map<int, Sprite*> getListTileSet();
	
	bool IsBoundLeft(); //kiem tra luc nay Camera o vi bien ben trai so voi WorldMap
	bool IsBoundRight(); // kiem tra xem co o vi tri bien ben phai worldmap khong
	bool IsBoundTop(); // kiem tra xem co o vi tri bien ben trai worldmap khong
	bool IsBoundBottom(); // kiem tra xem co o vi tri bien ben phai worldmap khong

	void SetCamera(Camera *camera);

	void Update(float dt);

	void Draw();

	bool inCamera(int a,int b);

	//std::vector<Brick*> GetListBrick();

	QuadTree* GetQuadTree();

	std::vector<Entity*> mList;
	
	
	
	void createQuadTree();
	std::map<int, Entity*>          mListEntity;
	std::map<int, QuadTree*>          mapQuadtree;
	
	std::fstream outfile;
	std::fstream outfile1;

	std::vector<Enemy1*>             mListEnemy1;
	std::vector<Enemy2*>             mListEnemy2;
	std::vector<Enemy3*>             mListEnemy3;
	std::vector<Brick2*>             mListBrick2;

	Elevator *elevator;
	std::vector<Door*>             mListDoor;
	Ship *ship;
	Plane *plane;
	Brick *brick;
	Boss1 *mBoss1;
	Boss2 *mBoss2;
	Boss3 *mBoss3;
	SpecialBullet *specialBullet;
	//void saveQuadTree(QuadTree *quadtree);
	~Map();

private:
	Sprite *background;
	void LoadMap(char* filePath);

	//bool isContain(RECT rect1, RECT rect2);
	Player *mPlayer;
	Tmx::Map				       *mMap;
	std::map<int, Sprite*>          mListTileset;
	Camera *mCamera;
	LPD3DXSPRITE                    mSpriteHandler;
	QuadTree                        *mQuadTree,*mQuadTree1;
	//Sprite                          *mSpriteBricks, *mSpriteBrickGold;
	Sprite	*mBackGround;
	
	
	int random;
	
	float speedBeeX = 180, speedBeeY = 30;
};

#endif

