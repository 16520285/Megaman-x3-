#include "Map.h"
#include "GameComponents/GameLog.h"
#include <cstdlib>
#include <ctime>
Map::Map(char* filePath,Player *mPlayer)
{
	this->mPlayer = mPlayer;
	LoadMap(filePath);
	
}

Map::~Map()
{
	delete mMap;
	for (size_t i = 0; i < mListTileset.size(); i++)
	{
		if (mListTileset[i])
			delete mListTileset[i];
	}
	mListTileset.clear();

	delete mQuadTree;
}

void Map::LoadMap(char* filePath)
{
	mBackGround = new Sprite("Resources/background.png");
	mBackGround->SetScale(D3DXVECTOR2(5,5));
	mBackGround->SetPosition(0,0);
	mMap = new Tmx::Map();
	mMap->ParseFile(filePath);

	RECT r;
	r.left = 0;
	r.top = 0;
	r.right = this->GetWidth();
	r.bottom = this->GetHeight();

	//mQuadTree = new QuadTree(1,1, r); //khoi tao quadtree

	for (size_t i = 0; i < mMap->GetNumTilesets(); i++)
	{
		const Tmx::Tileset *tileset = mMap->GetTileset(i);

		Sprite *sprite = new Sprite(tileset->GetImage()->GetSource().c_str());

		mListTileset.insert(std::pair<int, Sprite*>(i, sprite));
	}

	//Khoi tao body cho cac doi tuong tinh
#pragma region -OBJECTGROUP, STATIC OBJECT-

	for (size_t i = 0; i < mMap->GetNumObjectGroups(); i++)
	{

		const Tmx::ObjectGroup *objectGroup = mMap->GetObjectGroup(i);
		if (objectGroup->GetName() == "map")
		{
			for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
			{
				//lay object group chu khong phai layer
				//object group se chua nhung body
				Tmx::Object *object = objectGroup->GetObjects().at(j);

				Entity *entity = new Entity();

				entity->SetPosition(object->GetX() + object->GetWidth() / 2,
					object->GetY() + object->GetHeight() / 2);
				entity->SetWidth(object->GetWidth());
				entity->SetHeight(object->GetHeight());
				entity->Tag = Entity::EntityTypes::Static;
				entity->id = object->GetId();
				//mQuadTree->insertEntity(entity);
				mListEntity[entity->id] = entity;
				mList.push_back(entity);
			}

		}
	}
#pragma endregion
	for (size_t i = 0; i < mMap->GetNumObjectGroups(); i++)
	{

		const Tmx::ObjectGroup *objectGroup = mMap->GetObjectGroup(i);
		if (objectGroup->GetName() == "creep 1")
		{
			for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
			{

				Tmx::Object *object = objectGroup->GetObjects().at(j);
				D3DXVECTOR3 position(object->GetX(), object->GetY(), 0);
				//Enemy1 *temp = new Enemy1();
				Enemy1 *temp = new Enemy1();
				temp->SetPosition(position);
				mListEnemy1.push_back(temp);
				
			}
		}
		if (objectGroup->GetName() == "creep 2")
		{
			for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
			{

				Tmx::Object *object = objectGroup->GetObjects().at(j);
				D3DXVECTOR3 position(object->GetX(), object->GetY(), 0);
				//Enemy1 *temp = new Enemy1();
				Enemy2 *temp = new Enemy2();
				temp->SetPosition(position);
				mListEnemy2.push_back(temp);
				
			}
		}
		if (objectGroup->GetName() == "creep 3")
		{
			for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
			{

				Tmx::Object *object = objectGroup->GetObjects().at(j);
				D3DXVECTOR3 position(object->GetX(), object->GetY()-150, 0);
				//Enemy1 *temp = new Enemy1();
				Enemy3 *temp = new Enemy3();
				temp->SetPosition(position);
				mListEnemy3.push_back(temp);
				
			}
		}
		if (objectGroup->GetName() == "Boss")
			//if (objectGroup->GetName() == "creep 1")
		{
			for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
			{
				Tmx::Object *object = objectGroup->GetObjects().at(j);
				if (object->GetName() == "Boss 1")
				{
					D3DXVECTOR3 position(object->GetX(), object->GetY(), 0);
					 mBoss1 = new Boss1();
					mBoss1->SetPosition(position);

					
				}
				if (object->GetName() == "Boss 2")
				{
					D3DXVECTOR3 position(object->GetX(), object->GetY(), 0);
					mBoss2 = new Boss2();
					mBoss2->SetPosition(position);


				}
				
				if (object->GetName() == "Boss 3")
				{
					D3DXVECTOR3 position(object->GetX(), object->GetY()-200, 0);
					 mBoss3 = new Boss3(this->mPlayer);

					mBoss3->SetPosition(position);
				}
			}

		}

		if (objectGroup->GetName() == "brick")
			for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
			{
				Tmx::Object *object = objectGroup->GetObjects().at(j);
			
					D3DXVECTOR3 position(object->GetX(), object->GetY()-130, 0);
					Brick2 *temp = new Brick2();
					temp->SetPosition(position);
					mListBrick2.push_back(temp);
			}
		if (objectGroup->GetName() == "gate")
			for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
			{
				Tmx::Object *object = objectGroup->GetObjects().at(j);

				D3DXVECTOR3 position(object->GetX(), object->GetY()-60, 0);
				Door *temp = new Door();
				temp->SetPosition(position);
				mListDoor.push_back(temp);
			}

		

	}
	mListDoor[1]->key = false;
	mListDoor[3]->key = false;

	
	//GAMELOG("ene: %d", mListEnemy1);
	

	//ELEVATOR
	elevator = new Elevator();
	elevator->SetPosition(2280,1762);
	elevator->Tag = Entity::EntityTypes::Elevator;
	
	
	//SHIP
	ship = new Ship();
	ship->SetPosition(12618.7, 1824);
	plane = new Plane();
	plane->SetPosition(12618.7, 1524);
	
	//Brick
	for (int i = 0; i <= 3; i++)
	{
		Brick *brick = new Brick();
		brick->SetPosition(12618.7, 1324);
		mListBrick.push_back(brick);
	}
	for (int i = 0; i <= 10; i++)
	{
		SpecialBullet *specialBullet = new SpecialBullet();
		specialBullet->SetPosition(19509.3,3080);
		mListSpecialBullet.push_back(specialBullet);
	}
	times = 10;
	createQuadTree();

}


void Map::Draw()
{
	
	D3DXVECTOR2 trans = D3DXVECTOR2(GameGlobal::GetWidth() / 2 - mCamera->GetPosition().x,
		GameGlobal::GetHeight() / 2 - mCamera->GetPosition().y);
	mBackGround->Draw(mBackGround->GetPosition(), RECT(), D3DXVECTOR2(), trans);
	//background->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);*/
#pragma region DRAW TILESET

	for (size_t i = 0; i < mMap->GetNumTileLayers(); i++)
	{
		const Tmx::TileLayer *layer = mMap->GetTileLayer(i);

		if (!layer->IsVisible())
		{
			continue;
		}
		RECT sourceRECT;

		int tileWidth = mMap->GetTileWidth();
		int tileHeight = mMap->GetTileHeight();
		for (size_t m = 0; m < layer->GetHeight(); m++)
		{
			for (size_t n = 0; n < layer->GetWidth(); n++)
			{


				int tilesetIndex = layer->GetTileTilesetIndex(n, m);

				if (tilesetIndex != -1)
				{
					const Tmx::Tileset *tileSet = mMap->GetTileset(tilesetIndex);

					int tileSetWidth = tileSet->GetImage()->GetWidth() / tileWidth;
					int tileSetHeight = tileSet->GetImage()->GetHeight() / tileHeight;

					Sprite* sprite = mListTileset[layer->GetTileTilesetIndex(n, m)];

					//tile index
					int tileID = layer->GetTileId(n, m);

					int y = tileID / tileSetWidth;
					int x = tileID - y * tileSetWidth;

					sourceRECT.top = y * tileHeight;
					sourceRECT.bottom = sourceRECT.top + tileHeight;
					sourceRECT.left = x * tileWidth;
					sourceRECT.right = sourceRECT.left + tileWidth;
					//tru tilewidth/2 va tileheight/2 vi Sprite ve o vi tri giua hinh anh cho nen doi hinh de cho
					//dung toa do (0,0) cua the gioi thuc la (0,0) neu khong thi se la (-tilewidth/2, -tileheigth/2);
					D3DXVECTOR3 position(n * tileWidth + tileWidth / 2, m * tileHeight + tileHeight / 2, 0);

					sprite->SetWidth(tileWidth);
					sprite->SetHeight(tileHeight);

					sprite->Draw(position, sourceRECT, D3DXVECTOR2(), trans);


					//Sprite* sprite = mListTileset[j];
					if (mCamera != NULL)
					{
						RECT objRECT;
						objRECT.left = position.x - tileWidth / 2;
						objRECT.top = position.y - tileHeight / 2;
						objRECT.right = objRECT.left + tileWidth;
						objRECT.bottom = objRECT.top + tileHeight;

						if (!GameCollision::RecteAndRect(mCamera->GetBound(), objRECT).IsCollided)
							continue;
					}

				}
			}

		}
	}
#pragma endregion

#pragma region DRAW ENEMIES
	for (size_t i = 0; i < mListEnemy1.size(); i++)
	{
		mListEnemy1[i]->Draw(mListEnemy1[i]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		for (size_t j = 0; j < mListEnemy1[i]->mListEnemy1Bullet.size(); j++)
		{
			mListEnemy1[i]->mListEnemy1Bullet[j]->Draw(mListEnemy1[i]->mListEnemy1Bullet[j]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		}
	}
	for (size_t i = 0; i < mListEnemy2.size(); i++)
	{
		mListEnemy2[i]->Draw(mListEnemy2[i]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		for (size_t j = 0; j < mListEnemy2[i]->mListEnemy2Bullet.size(); j++)
		{
			mListEnemy2[i]->mListEnemy2Bullet[j]->Draw(mListEnemy2[i]->mListEnemy2Bullet[j]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		}
	}
	for (size_t i = 0; i < mListEnemy3.size(); i++)
	{
		mListEnemy3[i]->Draw(mListEnemy3[i]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		for (size_t j = 0; j < mListEnemy3[i]->mListEnemy3Bullet.size(); j++)
		{
			mListEnemy3[i]->mListEnemy3Bullet[j]->Draw(mListEnemy3[i]->mListEnemy3Bullet[j]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		}
	}
	//DRAW BOSS
	if (mBoss1)
		mBoss1->Draw(mBoss1->GetPosition(), RECT(), D3DXVECTOR2(), trans);
	if (mBoss2)
	{
		mBoss2->Draw(mBoss2->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		for (size_t i=0; i < mBoss2->mListBoss2Bullet.size();i++)
		{
			mBoss2->mListBoss2Bullet[i]->Draw(mBoss2->mListBoss2Bullet[i]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		}
	}
	if (mBoss3)
	{
		mBoss3->Draw(mBoss3->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		if (mBoss3->mListBee.size()!=0)

		for (size_t i = 0; i < mBoss3->mListBee.size(); i++)
		{
			mBoss3->mListBee[i]->Draw(mBoss3->mListBee[i]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
		}
	}
	
	

	
#pragma endregion 

#pragma region DRAW BULLETS PLAYER

	for (size_t i = 0; i < mPlayer->mListPlayerBullet.size(); i++)
	{
		mPlayer->mListPlayerBullet.at(i)->Draw(mPlayer->mListPlayerBullet.at(i)->GetPosition(), RECT(), D3DXVECTOR2(), trans);
	}
#pragma endregion

	
#pragma region DRAW GAME SPECIAL OBJECTS
	elevator->Draw(elevator->GetPosition(), RECT(), D3DXVECTOR2(), trans);

	for (size_t i = 0; i < mListDoor.size(); i++)
	mListDoor[i]->Draw(mListDoor[i]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
	for (size_t i = 0; i < mListBrick2.size(); i++)
	{
		if (mListBrick2[i]) mListBrick2[i]->Draw(mListBrick2[i]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
	}
	
	if (ship) ship->Draw(ship->GetPosition(), RECT(), D3DXVECTOR2(), trans);
	for (size_t i = 0; i < mListBrick.size(); i++)
	{
		if (mListBrick[i]) mListBrick[i]->Draw(mListBrick[i]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
	}
	if (plane) plane->Draw(plane->GetPosition(), RECT(), D3DXVECTOR2(), trans);
	if (mListSpecialBullet[times])  mListSpecialBullet[times]->Draw(mListSpecialBullet[times]->GetPosition(), RECT(), D3DXVECTOR2(), trans);
	
	
#pragma endregion
}


void Map::Update(float dt)
{

#pragma region UPDATE ENEMIES
	for (size_t i = 0; i < mListEnemy1.size(); i++)
	{
		if (inCamera(mListEnemy1[i]->GetPosition().x, mListEnemy1[i]->GetPosition().y))
		{
			if (mPlayer->GetPosition().x > mListEnemy1[i]->GetPosition().x - 30) mListEnemy1[i]->SetReverse(true);
			else mListEnemy1[i]->SetReverse(false);
			mListEnemy1[i]->Update(dt);
		}
			//update bullet enemy
			for (size_t j = 0; j < mListEnemy1[i]->mListEnemy1Bullet.size(); j++)
			{
				mListEnemy1[i]->mListEnemy1Bullet[j]->Update(dt);
				if (mListEnemy1[i]->mListEnemy1Bullet[j]->isDeleted)
				{
					delete mListEnemy1[i]->mListEnemy1Bullet[j];
					mListEnemy1[i]->mListEnemy1Bullet.erase(mListEnemy1[i]->mListEnemy1Bullet.begin() + j);
				}
			}
			//XOA ENEMY NEU ENEMY "CHET"
			if (mListEnemy1.at(i)->isDeleted) {
				delete mListEnemy1.at(i);
				mListEnemy1.erase(mListEnemy1.begin() + i);
			}
		
	}


	for (size_t i = 0; i < mListEnemy2.size(); i++)
	{
		
		
			if (inCamera(mListEnemy2[i]->GetPosition().x, mListEnemy2[i]->GetPosition().y))
			{
				if (mPlayer->GetPosition().x > mListEnemy2[i]->GetPosition().x - 30) mListEnemy2[i]->SetReverse(true);
				else mListEnemy2[i]->SetReverse(false);
				mListEnemy2[i]->Update(dt);
			}
			//update bullet enemy
			for (size_t j = 0; j < mListEnemy2[i]->mListEnemy2Bullet.size(); j++)
			{
				mListEnemy2[i]->mListEnemy2Bullet[j]->Update(dt);
				if (mListEnemy2[i]->mListEnemy2Bullet[j]->isDeleted)
				{
					delete mListEnemy2[i]->mListEnemy2Bullet[j];
					mListEnemy2[i]->mListEnemy2Bullet.erase(mListEnemy2[i]->mListEnemy2Bullet.begin() + j);
				}
			}
			//XOA ENEMY NEU ENEMY "CHET"
			if (mListEnemy2.at(i)->isDeleted) {
				delete mListEnemy2.at(i);
				mListEnemy2.erase(mListEnemy2.begin() + i);
			}
		

	}
	for (size_t i = 0; i < mListEnemy3.size(); i++)
	{
		if (inCamera(mListEnemy3[i]->GetPosition().x, mListEnemy3[i]->GetPosition().y))
		{
			if (mPlayer->GetPosition().x > mListEnemy3[i]->GetPosition().x - 30) mListEnemy3[i]->SetReverse(true);
			else mListEnemy3[i]->SetReverse(false);
			mListEnemy3[i]->Update(dt);
		}
			//update bullet enemy
			for (size_t j = 0; j < mListEnemy3[i]->mListEnemy3Bullet.size(); j++)
			{
				mListEnemy3[i]->mListEnemy3Bullet[j]->Update(dt);
				if (mListEnemy3[i]->mListEnemy3Bullet[j]->isDeleted)
				{
					delete mListEnemy3[i]->mListEnemy3Bullet[j];
					mListEnemy3[i]->mListEnemy3Bullet.erase(mListEnemy3[i]->mListEnemy3Bullet.begin() + j);
				}
			}
			//XOA ENEMY NEU ENEMY "CHET"
			if (mListEnemy3.at(i)->isDeleted) {
				delete mListEnemy3.at(i);
				mListEnemy3.erase(mListEnemy3.begin() + i);
			}
		
	}
#pragma endregion

#pragma region UPDATE GAME SPECIAL OBJECT
	if (inCamera(elevator->GetPosition().x, elevator->GetPosition().y)) elevator->Update(dt);

	for (size_t i = 0; i < mListDoor.size(); i++)
	{
		if (mListDoor[i]->GetPosition().x < (mPlayer->GetPosition().x)) mListDoor[i]->locked = true;
		if (inCamera(mListDoor[i]->GetPosition().x, mListDoor[i]->GetPosition().y)) mListDoor[i]->Update(dt);
	}
	for (size_t i = 0; i < mListBrick2.size(); i++)
	{
		if (mListBrick2[i])
		if (inCamera(mListBrick2[i]->GetPosition().x, mListBrick2[i]->GetPosition().y))	mListBrick2[i]->Update(dt);
		if (mListBrick2[i]->isDeleted) {
			mListBrick2[i] = NULL;
			mListBrick2.erase(mListBrick2.begin() + i);
		}
	}
	if (ship)
	{
		if (inCamera(ship->GetPosition().x, ship->GetPosition().y+200)) ship->Update(dt);
		if (ship->isDeleted) ship = NULL;
	}
	if (ship)
		if (plane)
		{
			if (inCamera(plane->GetPosition().x, plane->GetPosition().y)+200)
			{
				plane->Update(dt);
				if (plane->isDown) {
				
					mListBrick[ship->HP]->SetPosition(plane->GetPosition() + D3DXVECTOR3(0, mListBrick[ship->HP]->GetHeight(), 0));
				}
				if (mListBrick[ship->HP])
				{
					mListBrick[ship->HP]->Update(dt);
					if (mListBrick[ship->HP]->isDeleted) {
						mListBrick[ship->HP] = NULL;
						mListBrick.erase(mListBrick.begin() + ship->HP);
						ship->HP--;
					}
				}
				if (ship->isFinished) {
					plane = NULL;
					mListBrick.clear();
				}
				
			}
		}
	
#pragma endregion

#pragma region UPDATE BOSS
	
		
		if (mBoss3) {
			//if (inCamera(mBoss3->GetPosition().x-100, mBoss3->GetPosition().y))
			if (mPlayer->GetPosition().x>19050)
			{
				if (mPlayer->GetPosition().x > mBoss3->GetPosition().x - 30) mBoss3->SetReverse(true);
				else mBoss3->SetReverse(false);
				mBoss3->Update(dt);
				if (mBoss3->isDeleted)
					mBoss3 = NULL;
			}
			
			speedBeeY = 30;
			if (mBoss3->mListBee.size() != 0)
			for (size_t i = 0; i < mBoss3->mListBee.size(); i++)
			{
				
					speedBeeY += 20;
					if (speedBeeY == 130) speedBeeY = 50;
					if (mBoss3->mListBee[i]->mCurrentReverse) mBoss3->mListBee[i]->SetVx(speedBeeX);
					else mBoss3->mListBee[i]->SetVx(-speedBeeX);
					mBoss3->mListBee[i]->SetVy(speedBeeY);

					if (mBoss3->mListBee[i]->GetPosition().x <= (19509.3 - 425) || mBoss3->mListBee[i]->GetPosition().x >= (19509.3 + 100))
					{
						mBoss3->mListBee[i]->SetVx(0);
						mBoss3->mListBee[i]->SetVy(0);
					}
					if (mListSpecialBullet[times])
						if (mListSpecialBullet[times]->isFollowing) {
							GAMELOG("a:%d", times);
							mBoss3->mListBee[i]->SetVx(mPlayer->GetPosition().x - mBoss3->mListBee[i]->GetPosition().x);
							mBoss3->mListBee[i]->SetVy(mPlayer->GetPosition().y - mBoss3->mListBee[i]->GetPosition().y);
						}
					mBoss3->mListBee[i]->Update(dt);
					
					
					if (mBoss3->mListBee[i]->isDeleted) {
						mBoss3->mListBee[i] = NULL;
						mBoss3->mListBee.erase(mBoss3->mListBee.begin() + i);
					}
			}

			//SPECIAL BULLET
			if (mBoss3->mCurrentState==2 && mBoss3->HP<20)
			{
				mListSpecialBullet[times]->SetPosition(mBoss3->GetPosition());
				mListSpecialBullet[times]->isBegin = true;
			}
			if (mListSpecialBullet[times] && mListSpecialBullet[times]->isBegin) {
				
				mListSpecialBullet[times]->SetVx(mPlayer->GetPosition().x- mListSpecialBullet[times]->GetPosition().x);
				mListSpecialBullet[times]->SetVy(mPlayer->GetPosition().y - mListSpecialBullet[times]->GetPosition().y);
				
				if (mListSpecialBullet[times]->isFollowing) {
					mListSpecialBullet[times]->SetVx(0);
					mListSpecialBullet[times]->SetVy(0);
					mListSpecialBullet[times]->SetPosition(mPlayer->GetPosition());
				}
				mListSpecialBullet[times]->Update(dt);
				if (mListSpecialBullet[times]->isDeleted) {
					mListSpecialBullet[times] = NULL;
					mListSpecialBullet.erase(mListSpecialBullet.begin() + times);
					times--;
				}
			}

			
		}
	if (mBoss1) {
		if (inCamera(mBoss1->GetPosition().x-100, mBoss1->GetPosition().y)) mBoss1->Update(dt);
		if (mBoss1->isDeleted) {
			mListDoor[1]->key = true;
			mBoss1 = NULL;
		}
	}
	if (mBoss2) {
		if (inCamera(mBoss2->GetPosition().x, mBoss2->GetPosition().y)) mBoss2->Update(dt);
		for (size_t i=0; i < mBoss2->mListBoss2Bullet.size(); i++)
		{
			mBoss2->mListBoss2Bullet[i]->Update(dt);
			if (mBoss2->mListBoss2Bullet.at(i)->isDeleted) {
				delete mBoss2->mListBoss2Bullet.at(i);
				mBoss2->mListBoss2Bullet.erase(mBoss2->mListBoss2Bullet.begin() + i);
			}
		}
		if (mPlayer->GetPosition().x > 14658) mBoss2->isDeleted = true;
		if (mBoss2->isDeleted) {
			mListDoor[3]->key = true;
			mBoss2 = NULL;
		}
	}
	

#pragma endregion 

	
}


void Map::createQuadTree()
{
	this->outfile.open("quadtree.txt");
	int cId, cLevel, cNumberOfEntity, j, cNumberOfNodes,dem,temp; RECT cBound;
	while (!outfile.eof())
	{
		//GAMELOG("quad1: %d", temp); 
		outfile >> cId; temp = cId;
		outfile >> cLevel;
		outfile >> cBound.left;
		outfile >> cBound.top;
		outfile >> cBound.right;
		outfile >> cBound.bottom;
		//GAMELOG("id: %d", cId);
		mapQuadtree[cId] = new QuadTree(cId, cLevel, cBound);
		outfile >> cNumberOfEntity;
		for (int i = 0; i < cNumberOfEntity; i++)
		{
			//mapQuadtree[cId]->getmListEntity().push_back(mListEntity[outfile >> j]);
			outfile >> j;
			mapQuadtree[temp]->mListEntity.push_back(mListEntity[j]);
			
			//GAMELOG("temp: %d", temp);
			//GAMELOG("j: %d", j);
			//GAMELOG("list: %d", mapQuadtree[1]->getmListEntity().size());
		}
	}
	
	this->outfile.close();
	
		
	std::map<int, QuadTree*>::iterator it;
	for (it = mapQuadtree.begin(); it!=mapQuadtree.end(); it++)
	{
		if (it->first == 1) mQuadTree = it->second;
		else
		{
			int p = it->first / 10;
			int child = it->first % 10;
			if (mapQuadtree[p] != NULL)
			{
				QuadTree *pQuadTree = mapQuadtree[p];
				//if  (pQuadTree->Nodes==NULL) pQuadTree->Nodes= new QuadTree *[4];
				if (pQuadTree->Nodes == NULL)   pQuadTree->Nodes = new QuadTree *[4];
				switch (child)
				{
				case 1:
					pQuadTree->Nodes[0] = it->second;
					break;
				case 2:
					pQuadTree->Nodes[1] = it->second;
					break;
				case 3:
					pQuadTree->Nodes[2] = it->second;
					break;
				case 4:
					pQuadTree->Nodes[3] = it->second;
					break;
				default:
					break;
				}
			}
		}
	}
	//GAMELOG("quad %d:", mQuadTree1);
	/*this->outfile1.open("quadtree1.txt");
	
	//outfile1 << mapQuadtree[1]->mId << mapQuadtree[1]->Bound.left;
	//saveQuadTree(mQuadTree1);
	outfile1 << mapQuadtree[1]->mId << " " << mapQuadtree[1]->mLevel << " " << mapQuadtree[1]->Bound.left << " " << mapQuadtree[1]->Bound.top << " " << mapQuadtree[1]->Bound.right << " " << mapQuadtree[1]->Bound.bottom << " " <<mapQuadtree[1]->getmListEntity().size()  <<std::endl;
	outfile1 << mapQuadtree[12]->mId << " " << mapQuadtree[12]->mLevel << " " << mapQuadtree[12]->Bound.left << " " << mapQuadtree[12]->Bound.top << " " << mapQuadtree[12]->Bound.right << " " << mapQuadtree[12]->Bound.bottom << " " << mapQuadtree[12]->getmListEntity().size()<< std::endl;
	outfile1.close();
	*/
	
	
}

bool Map::inCamera(int a,int b)
{
	int c = mPlayer->GetPosition().x;
	int d = mPlayer->GetPosition().y;
	if ((abs(a - c) <= GameGlobal::GetWidth() / 2) && (abs(b - d) <= GameGlobal::GetHeight() / 2)) return 1;
	else return 0;
}







Tmx::Map* Map::GetMap()
{
	return mMap;
}

int Map::GetWidth()
{
	return mMap->GetWidth()* mMap->GetTileWidth();
}

int Map::GetHeight()
{
	return mMap->GetHeight() * mMap->GetTileHeight();
}
int Map::GetTileWidth()
{
	return mMap->GetTileWidth();
}

int Map::GetTileHeight()
{
	return mMap->GetTileHeight();
}



/*int Map::GetWidth()
{
	return mMap->GetWidth();
}

int Map::GetHeight()
{
	return mMap->GetHeight();
}
*/

void Map::SetCamera(Camera * camera)
{
	this->mCamera = camera;
}
RECT Map::GetWorldMapBound()
{
	RECT bound;
	bound.left = bound.top = 0;
	bound.right = mMap->GetWidth() * mMap->GetTileWidth();
	bound.bottom = mMap->GetHeight() * mMap->GetTileHeight();

	return bound;
}
std::map<int, Sprite*> Map::getListTileSet()
{
	return mListTileset;
}



QuadTree * Map::GetQuadTree()
{
	return mQuadTree;
}
bool Map::IsBoundLeft()
{
	return (mCamera->GetBound().left == 0);
}

bool Map::IsBoundRight()
{
	return (mCamera->GetBound().right == this->GetWidth());
}

bool Map::IsBoundTop()
{
	return (mCamera->GetBound().top == 0);
}

bool Map::IsBoundBottom()
{
	return (mCamera->GetBound().bottom == this->GetHeight());
}
