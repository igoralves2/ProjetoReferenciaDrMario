#include "Comprimido.h"

Comprimido::Comprimido()
{
	setTipo(1);
	setPoder(3);
}

Comprimido::~Comprimido()
{
}

void Comprimido::atualizar()
{/*
	if (x < 0 || x > gJanela.getLargura() || y < 0 || y > gJanela.getAltura()) {
		movendo = false;
	}
	else {*/
		x += dx;
		y += dy;
	//}
		moves++;
		if (moves >= 260) {
			moves = 0;
			movendo = false;
		}
}

int Comprimido::dano(int nivelp, int attackp, int defensev)
{
	return Arma::dano(nivelp, attackp, defensev);
}
