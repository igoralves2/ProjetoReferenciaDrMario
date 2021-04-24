#include "Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

int Camera::getX()
{
    return x;
}

int Camera::getY()
{
    return y;
}

void Camera::setX(int xnovo)
{
    this->x = xnovo;
}

void Camera::setY(int ynovo)
{
    this->y = ynovo;
}

int Camera::clamp(int atual, int min, int max)
{
    if (atual < min) {
        atual = min;
    }
    else if (atual > max) {
        atual = max;
    }return atual;
}
