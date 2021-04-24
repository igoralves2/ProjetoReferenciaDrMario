#include "Arma.h"

Arma::Arma()
{
}

Arma::~Arma()
{
}

void Arma::setPosition(int* xnovo, int* ynovo, int* novodx, int* novody)
{
	this->x = *xnovo;
	this->y = *ynovo;
	this->dx = *novodx;
	this->dy = *novody;
}

void Arma::resetPosition(int* xnovo, int* ynovo)
{
	movendo = false;
	explodindo = false;
	this->x = *xnovo;
	this->y = *ynovo;
	this->dx = 0;
	this->dy = 0;
}

int Arma::dano(int nivelp, int attackp, int defensev)
{
	float danofloat = (nivelp * ((attackp * 1.00f) / (defensev * 1.00f)) * this->poder);
	int dano = 1;
	if (danofloat < 1) {
		dano = 1;
	}
	else {
		dano = floor(danofloat);
	}return dano;
}

void Arma::setSprite(string path)
{
	this->sprite.setSpriteSheet(path);
}

int Arma::getTipo()
{
	return tipo;
}

int Arma::getPoder()
{
	return poder;
}

Sprite Arma::getSprite()
{
	return sprite;
}

void Arma::setTipo(int novoTipo)
{
	this->tipo = novoTipo;
}

void Arma::setPoder(int novopoder)
{
	this->poder = novopoder;
}
/*
void Arma::atualizar()
{
	if (x < 0 || x > gJanela.getLargura() || y < 0 || y > gJanela.getAltura()) {
		movendo = false;
	}
	else {
		x += dx;
		y += dy;
	}/*
	if (getTipo() == 2) {
		moves++;
		if (moves == 200) {
			explodindo = true;
			movendo = false;
		}
		else if(moves > 300){
			explodindo = false;
			moves = 0;
		}
	}if (getTipo() == 3) {
		moves++;
		if (moves >= 200) {
			movendo = false;
			moves = 0;
		}
	}
}*/
