#pragma once
#include <libUnicornio.h>
#include "Arma.h"
class AlcoolGel : public Arma
{

	public:
		AlcoolGel();
		//bool explodindo = false;
		//Sprite sprite;
		//void setPosition(int *xnovo, int *ynovo, int *novodx, int *novody);
		//void resetPosition(int *xnovo, int *ynovo);
		//void setPoder(int podernovo);
		//int dano(int nivelp, int attackp, int defensev);
		~AlcoolGel();
		//int x;
		//int y;
		//int dx = 0;
		//int dy = 0;
		int dano(int nivelp, int attackp, int defensev);
		void atualizar() override;
		//bool movendo = false;
		//bool explodindo = false;
		int moves = 0;
	protected:

};

