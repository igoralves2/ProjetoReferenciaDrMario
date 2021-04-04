#include "AlcoolGel.h"/

AlcoolGel::AlcoolGel()
{
	setTipo(2);
	setPoder(2);
}


AlcoolGel::~AlcoolGel()
{
}



void AlcoolGel::atualizar()
{
		explodindo = false;
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