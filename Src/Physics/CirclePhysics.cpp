#include "CirclePhysics.h"
#include "../../Src/Sprite/Sprite.h"

CirclePhysics::CirclePhysics()
{
    Init();
}

bool CirclePhysics::Init()
{
    //Define Cirle Model
    m_modelCircle.push_back({ 0.0f, 0.0f });
    int nPoints = 20;
    for (int i = 0; i < nPoints; i++)
    {
        m_modelCircle.push_back({ cosf(i / (float)(nPoints - 1) * 2.0f * 3.14159f), sinf(i / (float)(nPoints - 1) * 2.0f * 3.14159f) });
    }

    float defaultRadius = 4.0f;

    return true;
}

bool CirclePhysics::Update()
{
    //todo
    return false;
}

Circle* CirclePhysics::MakeCircle(std::string imgPath, float x, float y, float r)
{
    return AddCircle(imgPath, x, y, r);
}

void CirclePhysics::MakeSpriteSDL(Circle* targetCircle)
{
    targetCircle->sprite = Sprite::MakeSpriteSDL(targetCircle->imgPath, (int)targetCircle->r, (int)targetCircle->r, { (int)targetCircle->x, (int)targetCircle->y }, m_SDLWindow);
}

void CirclePhysics::MakeSpriteRayLib(Circle* targetCircle)
{
    targetCircle->sprite = Sprite::MakeSpriteRayLib(targetCircle->imgPath, (int)targetCircle->r, (int)targetCircle->r, { (int)targetCircle->x, (int)targetCircle->y });
}

void CirclePhysics::SetVelocityRandom(Circle* targetCircle)
{
    int minVelocity = -1;
    int maxVelocity = 1;

    int randomNum = rand() % (maxVelocity - (minVelocity) + 1) + minVelocity;
    int randomNum2 = rand() % (maxVelocity - (minVelocity) + 1) + minVelocity;

    targetCircle->vx = randomNum;
    targetCircle->vy = randomNum;
}

std::vector<Circle>* CirclePhysics::GetCirleList()
{
    return &m_circleList;
}

void CirclePhysics::SetWindow(SDL_Window* window)
{
    m_SDLWindow = window;
}

//Sprite* CirclePhysics::SyncSpritePos()
//{
//    return nullptr;
//}

Circle* CirclePhysics::AddCircle(std::string imgPath, float x, float y, float r)
{
    Circle tempCircle;
    tempCircle.x = x; tempCircle.y = y;
    tempCircle.vx = 0; tempCircle.vy = 0;
    tempCircle.ax = 0; tempCircle.ay = 0;
    tempCircle.r = r;
    tempCircle.imgPath = imgPath;

    tempCircle.id = m_circleList.size();
    m_circleList.emplace_back(tempCircle);
    return &tempCircle;
}
