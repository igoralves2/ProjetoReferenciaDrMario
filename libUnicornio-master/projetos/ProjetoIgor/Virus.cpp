#include "Virus.h"



Virus::Virus()
{
}



Virus::~Virus()
{
}

void Virus::setStatus(int novonivel, int novohp, int novoattack, int novadefense, int novaspeed)
{
	this->nivel = novonivel;
	this->maxhp = novohp;
	this->hp = this->maxhp;
	this->attack = novoattack;
	this->defense = novadefense;
	this->speed = novaspeed;
}

void Virus::atualizar(int xp, int yp)
{
	int mover = rand() % 5;
	if (mover >= 4) {
		if (xp > this->x) {
			x += speed;
		}
		else if (xp < this->x) {
			x -= speed;
		}
		if (yp > this->y) {
			y += speed;
		}
		else if (yp < this->y) {
			y -= speed;
		}
	}
}

void Virus::setClasseVirus(int nro)
{
	classevirus = nro;
}

void Virus::setFeverPower(int nro)
{
	feverpower = nro;
}

void Virus::setChillPower(int nro)
{
	chillpower = nro;
}

void Virus::setCoughPower(int nro)
{
	coughpower = nro;
}

void Virus::setSneezePower(int nro)
{
	sneezepower = nro;
}

void Virus::setAcuracy(int newacuracy)
{
	this->acuracia = newacuracy;
}

void Virus::setX(int novox)
{
	this->x = novox;
}

void Virus::setY(int novoy)
{
	this->y = novoy;
}

int Virus::getFeverPower()
{
	return feverpower;
}

int Virus::getChillPower()
{
	return chillpower;
}

int Virus::getCoughPower()
{
	return coughpower;
}

int Virus::getSneezePower()
{
	return sneezepower;
}

int Virus::getAcuracia()
{
	return acuracia;
}

int Virus::getTipo()
{
	return classevirus;
}


Sprite Virus::getSprite()
{
	return sprite;
}

void Virus::setSprite(string path)
{
	this->sprite.setSpriteSheet(path);
}

int Virus::dano(int defense, float eficiencia)
{
	int doenca = rand() % 4;
	int dano = 1;
	if (doenca == 0) {
		float danofloat = (this->nivel * ((this->attack * 1.0f) / (defense * 1.0f)) * this->feverpower) * eficiencia;
		if (danofloat < 1) {
			dano = 1;
		}
		else {
			dano = floor(danofloat);
		}
		if (rand() % acuracia != 0) {
			return 0;
		}
	}
	else if (doenca == 1) {
		float danofloat = (this->nivel * ((this->attack * 1.0f) / (defense * 1.0f)) * this->chillpower) * eficiencia;
		int dano;
		if (danofloat < 1) {
			dano = 1;
		}
		else {
			dano = floor(danofloat);
		}if (rand() % acuracia != 0) {
			return 0;
		}
	}
	else if (doenca == 2) {
		float danofloat = (this->nivel * ((this->attack * 1.0f) / (defense * 1.0f)) * this->coughpower) * eficiencia;
		int dano;
		if (danofloat < 1) {
			dano = 1;
		}
		else {
			dano = floor(danofloat);
		}
		if (rand() % acuracia != 0) {
			return 0;
		}
	}
	else if(doenca == 3){
		float danofloat = (this->nivel * ((this->attack * 1.0f) / (defense * 1.0f)) * this->sneezepower) * eficiencia;
		int dano;
		if (danofloat < 1) {
			dano = 1;
		}
		else {
			dano = floor(danofloat);
		}if (rand() % acuracia != 0) {
			return 0;
		}
	}
	return dano;
}
