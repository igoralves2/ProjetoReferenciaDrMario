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
	int x = 400, y = 300;
	Sprite sprite;
	//Comprimido c;
	//AlcoolGel ag;
	//Vacina v;
	
	Comprimido c;
	AlcoolGel ag;
	Vacina v;
	//Arma armas[3];
	Mascara m;
	int nivel = 1;
	int hp = 100;
	int maxhp = 100;
	int attack = 1;
	int defense = 1;
	int speed = 1;
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