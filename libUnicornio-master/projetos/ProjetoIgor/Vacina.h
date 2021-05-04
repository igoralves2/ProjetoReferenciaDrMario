#pragma once
#include "libUnicornio.h"
#include "Arma.h"
class Vacina : public Arma
{
public:
	Vacina();
	//Sprite sprite;
	//void setPosition(int* xnovo, int* ynovo, int* novodx, int* novody);
	//void resetPosition(int* xnovo, int* ynovo);
	~Vacina();
	int dano(int nivelp, int attackp, int defensev);
	//int x;
	//int y;
	//int dx = 0;
	//int dy = 0;
	//bool movendo = false;
	//int moves = 0;
	//int poder = 5;
	void atualizar() override;
	int idfraqueza;
	int getIdFraqueza();
	void setIdFraqueza(int novoid);
private:
	int tipodose;
	//1=red
	//2=yellow
	//3=green
	//4=cyan
	//5=blue
	//6=purple
	//7=pink
};

