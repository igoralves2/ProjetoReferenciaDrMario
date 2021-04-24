#include "AlcoolGel.h"/

AlcoolGel::AlcoolGel()
{
	setTipo(2);
	setPoder(4);
}


AlcoolGel::~AlcoolGel()
{
}



int AlcoolGel::dano(int nivelp, int attackp, int defensev)
{
	return Arma::dano(nivelp, attackp, defensev);
}

void AlcoolGel::atualizar()
{/*
	if (x < 0 || x > gJanela.getLargura() || y < 0 || y > gJanela.getAltura()) {
		movendo = false;
	}
	else {*/
		x += dx;
		y += dy;
	/*}*/
	moves++;
	if (moves == 200) {
		explodindo = true;
		movendo = false;
	}
	else if (moves > 300) {
		explodindo = false;
		moves = 0;
	}
}