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
	this->x = *xnovo;
	this->y = *ynovo;
	this->dx = 0;
	this->dy = 0;
}

int Arma::dano(int nivelp, int attackp, int defensev)
{
	float danofloat = (nivelp * ((attackp * 1.0f) / (defensev * 1.0f)) * this->poder);
	int dano = 1;
	if (danofloat < 1) {
		dano = 1;
	}
	else {
		dano = floor(danofloat);
	}return dano;
}

int Arma::getTipo()
{
	return tipo;
}

int Arma::getPoder()
{
	return poder;
}

void Arma::setTipo(int novoTipo)
{
	this->tipo = novoTipo;
}

void Arma::setPoder(int novopoder)
{
	this->poder = novopoder;
}

void Arma::atualizar()
{
	if (tipo == 1) {
		if (x < 0 || x > gJanela.getLargura() || y < 0 || y > gJanela.getAltura()) {
			movendo = false;
		}
		else {
			x += dx;
			y += dy;
		}
	}
	else if (tipo == 2) {
		explodindo = false;
		if (x < 0 || x > gJanela.getLargura() || y < 0 || y > gJanela.getAltura() || moves == 0) {
			movendo = false;

		}
		else {
			x += dx;
			y += dy;
		}
		moves++;
		if (moves >= 200) {
			moves = 0;
		}
	}
	else if (tipo == 3) {
		if (x < 0 || x > gJanela.getLargura() || y < 0 || y > gJanela.getAltura() || moves == 0) {
			movendo = false;

		}
		else {
			x += dx;
			y += dy;
		}moves++;
		if (moves >= 200) {
			moves = 0;
		}
	}
}
