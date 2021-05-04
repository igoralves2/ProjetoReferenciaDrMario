#pragma once
#include "libUnicornio.h"
class Arma
{
public:
	void setPosition(int* xnovo, int* ynovo, int* novodx, int* novody);
	void resetPosition(int* xnovo, int* ynovo);
	int dano(int nivelp, int attackp, int defensev);
	void setSprite(string path);
	int getTipo();
	int getPoder();
	Sprite getSprite();
	void setTipo(int novoTipo);
	void setPoder(int novopoder);
	bool explodindo = false;
	int x, y;
	int dx = 0;
	int dy = 0;
	int moves = 0;
	int poder;
	bool movendo = false;
	virtual void atualizar() = 0;
protected:
	Sprite sprite;
	int tipo;
	//1=comprimido
	//2=alcoolgel
	//3=vacina
	//
};

