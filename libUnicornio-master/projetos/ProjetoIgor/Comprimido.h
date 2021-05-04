#pragma once
#include <libUnicornio.h>
#include "Arma.h"
class Comprimido : public Arma
{	
	public:
		Comprimido();
		//Sprite sprite;
		//void setPosition(int *xnovo, int *ynovo, int *novodx, int *novody);
		//void resetPosition(int* xnovo, int* ynovo);
		~Comprimido();
		//int dano(int nivelp, int attackp, int defensev);
		//int x;
		//int y;
		//int dx = 0;
		//int dy = 0;
		//bool movendo = false;
		//int poder = 5;
		void atualizar() override;
		int dano(int nivelp, int attackp, int defensev);
	protected:
};

