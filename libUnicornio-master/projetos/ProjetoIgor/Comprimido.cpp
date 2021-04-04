#include "Comprimido.h"

Comprimido::Comprimido()
{
	setTipo(1);
	setPoder(1);
}

Comprimido::~Comprimido()
{
}

void Comprimido::atualizar()
{
	if (x < 0 || x > gJanela.getLargura() || y < 0 || y > gJanela.getAltura()) {
		movendo = false;
	}
	else {
		x += dx;
		y += dy;
	}
}
