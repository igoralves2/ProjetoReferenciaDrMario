#include "Vacina.h"

Vacina::Vacina()
{
	setPoder(3);
	setTipo(3);
}



Vacina::~Vacina()
{
}

int Vacina::dano(int nivelp, int attackp, int defensev, int tipov)
{
	float delta = 1.0f;
	if (this->idfraqueza == tipov) {
		delta = 2.0f;
	}
	float danofloat = (nivelp * ((attackp * 1.0f) / (defensev * 1.0f)) * this->poder) * delta;
	int dano = 1;
	if (danofloat < 1) {
		dano = 1;
	}
	else {
		dano = floor(danofloat);
	}return dano;
}


void Vacina::atualizar()
{
	if (x < 0 || x > gJanela.getLargura() || y < 0 || y > gJanela.getAltura() || moves == 0) {
		movendo = false;

	}
	else {
		x += this->dx;
		y += this->dy;
	}
	moves++;
	if (moves >= 200) {
		moves = 0;
	}
}

int Vacina::getIdFraqueza()
{
	return idfraqueza;
}

void Vacina::setIdFraqueza(int novoid)
{
	this->idfraqueza = novoid;
}
