#include "Vacina.h"

Vacina::Vacina()
{
	setPoder(5);
	setTipo(3);
}



Vacina::~Vacina()
{
}

int Vacina::dano(int nivelp, int attackp, int defensev)
{
	//float delta = 1.0f;
	//if (this->idfraqueza == tipov) {
		//delta = 2.0f;
	//}
	return floor(Arma::dano(nivelp, attackp, defensev));
}


void Vacina::atualizar()
{/*
	if (x < 0 || x > gJanela.getLargura() || y < 0 || y > gJanela.getAltura()) {
		movendo = false;
	}
	else {*/
		x += dx;
		y += dy;
	//}
	moves++;
	if (moves >= 200) {
		movendo = false;
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
