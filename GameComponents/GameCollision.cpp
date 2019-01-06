#include "GameCollision.h"

GameCollision::GameCollision()
{

}


GameCollision::~GameCollision()
{
}

Entity::CollisionReturn GameCollision::RecteAndRect(RECT rect1, RECT rect2)
{
    Entity::CollisionReturn result;

    if (!isCollide(rect1, rect2))
    {
        result.IsCollided = false;

        return result;
    }

    result.IsCollided = true;

    //chon max Left
    result.RegionCollision.left = rect1.left > rect2.left ? rect1.left : rect2.left;
    //chon max right
    result.RegionCollision.right = rect1.right < rect2.right ? rect1.right : rect2.right;
    //chon min bottom
    result.RegionCollision.bottom = rect1.bottom < rect2.bottom ? rect1.bottom : rect2.bottom;
    //chon max top
    result.RegionCollision.top = rect1.top > rect2.top ? rect1.top : rect2.top;

    return result;
}

bool GameCollision::PointAndRectangle(float x, float y, RECT rect)
{
    if (x < rect.left || x > rect.right || y < rect.top || y > rect.bottom)
        return false;

    return true;
}

/*bool GameCollision::RectangleAndCircle(RECT rect, int circlex, int circley, int circleRadius)
{
    int px = circlex;
    int py = circley;

    if (px < rect.left)
        px = rect.left;
    else if (px > rect.right)
        px = rect.right;

    if (py > rect.bottom)
        py = rect.bottom;
    else if (py < rect.top)
        py = rect.top;

    int dx = px - circlex;
    int dy = py - circley;

    return (dx * dx + dy * dy) <= circleRadius * circleRadius;
}
*/
bool GameCollision::isCollide(RECT rect1, RECT rect2)
{
    if (rect1.left > rect2.right || rect1.right < rect2.left || rect1.top > rect2.bottom || rect1.bottom < rect2.top)
    {
        return false;
    }

    return true;
}



Entity::SideCollisions GameCollision::getSideCollision(Entity *e1, Entity::CollisionReturn data)
{
    float xCenter = data.RegionCollision.left + (data.RegionCollision.right - data.RegionCollision.left) / 2.0f;
    float yCenter = data.RegionCollision.top + (data.RegionCollision.bottom - data.RegionCollision.top) / 2.0f;

    D3DXVECTOR2 cCenter = D3DXVECTOR2(xCenter, yCenter);
    D3DXVECTOR2 eCenter = e1->GetPosition();

    //lay vector noi tam Entity va CollisionRect
    D3DXVECTOR2 vec = cCenter - eCenter;

    //chuan hoa vector
    D3DXVec2Normalize(&vec, &vec);

    /*
    - neu vector chuan hoa co y > 0 =>nam phia ben tren Entity
    - neu vector chuan hoa co y < 0 =>nam phia ben duoi Entity
    - neu vector chuan hoa co x > 0 => nam phia ben phai Entity
    - neu vector chuan hoa co x < 0 => nam phia ben trai Entity
    */

    if (vec.y < 0)
    {
        //va cham phia ben tren
        //lay cos cua goc neu ma nam trong khoang goc 70 -> 110 thi va cham top
        if (vec.x <= 0.35f && vec.x >= -0.35f)
        {
            return Entity::Top;
        }
        else if (vec.x > 0.35f && vec.x < 0.8f)
        {
            //goc trong khoang 35 -> 70 phia ben top - right
            return Entity::TopRight;
        }
        else if (vec.x >= 0.8f)
        {
            return Entity::Right;
        }
        else if (vec.x < -0.35f && vec.x >= -0.8f)
        {
            //va cham phia top - left
            return Entity::TopLeft;
        }
        else
        {
            return Entity::Left;
        }
    }
    else
    {
        //va cham phia ben duoi
        //lay cos cua goc neu ma nam trong khoang goc 70 -> 110 thi va cham top
        if (vec.x <= 0.35f && vec.x >= -0.35)
        {
            return Entity::Bottom;
        }
        else if (vec.x > 0.35 && vec.x < 0.8)
        {
            //goc trong khoang 35 -> 70 phia ben top - right
            return Entity::BottomRight;
        }
        else if (vec.x >= 0.8)
        {
            return Entity::Right;
        }
        else if (vec.x < -0.35f && vec.x > -0.8f)
        {
            //va cham phia top - left
            return Entity::BottomLeft;
        }
        else
        {
            return Entity::Left;
        }
    }

    return Entity::NotKnow;
}