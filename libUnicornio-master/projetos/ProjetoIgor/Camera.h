#pragma once
class Camera
{
public:
	Camera();
	~Camera();
	int getX();
	int getY();
	void setX(int xnovo);
	void setY(int ynovo);
	int clamp(int atual, int min, int max);
protected:
	int x, y;
};

