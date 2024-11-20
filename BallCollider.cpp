#include "BallCollider.h"

BallCollider::BallCollider()
{
}

bool BallCollider::Init()
{
    //Define Cirle Model
    m_modelCircle.push_back({ 0.0f, 0.0f });
    int nPoints = 20;
    for (int i = 0; i < nPoints; i++)
    {
        m_modelCircle.push_back({ cosf(i / (float)(nPoints - 1) * 2.0f * 3.14159f), sinf(i / (float)(nPoints - 1) * 2.0f * 3.14159f) });
    }

    return true;
}

bool BallCollider::Update()
{
    return false;
}
