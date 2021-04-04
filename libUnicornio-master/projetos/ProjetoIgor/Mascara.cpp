#include "Mascara.h"

Mascara::Mascara()
{
}

Mascara::~Mascara()
{
}

void Mascara::setTipo(int tipo)
{
	this->tipo = tipo;
}

void Mascara::setEficienciaContagio(float qtd)
{
	eficienciaContagio = qtd;
}

int Mascara::getTipo()
{
	return tipo;
}

float Mascara::getEficienciaContagio()
{
	return eficienciaContagio;
}

Sprite Mascara::getSprite()
{
	return sprite;
}
