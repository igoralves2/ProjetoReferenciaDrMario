#pragma once
#include "libUnicornio.h"
class Mascara
{
public:
	Mascara();
	~Mascara();
	int x, y;
	bool coletada = false;
	void setTipo(int tipo);
	void setEficienciaContagio(float qtd);
	int getTipo();
	float getEficienciaContagio();
	Sprite getSprite();
protected:
	Sprite sprite;
private:
	int tipo;
	//1=Normal
	//2=Eficiente;
	float eficienciaContagio = 1;
};

