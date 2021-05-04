#pragma once
#include "Comprimido.h"
#include "AlcoolGel.h"
#include <libUnicornio.h>
#include "Mascara.h"
#include "Vacina.h"
class Player
{
public:
	Player();
	~Player();
	int x, y;
	Sprite sprite;
	//Comprimido c;
	//AlcoolGel ag;
	//Vacina v;
	Comprimido c;
	AlcoolGel ag;
	Vacina v;
	Mascara m;
	int nivel;
	int hp;
	int maxhp;
	int attack;
	int defense;
	int speed;
	void atualizar(int xmax, int ymax);
	bool atirandocomprimido = false;
	bool atirandoalcoolgel = false;
	bool usandovacina = false;
	const int up = 1;
	const int down = 2;
	const int left = 3;
	const int right = 4;
	int currentdir = 2;
	float eficienciamascara();
protected:
	
};