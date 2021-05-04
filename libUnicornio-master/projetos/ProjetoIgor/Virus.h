#pragma once
#include "libUnicornio.h"
class Virus
{
public:
	Virus();
	~Virus();
	void setStatus(int novonivel, int novohp, int novoattack, int novadefense, int novaspeed);
	void atualizar(int xp, int yp);
	void setClasseVirus(int nro);
	void setFeverPower(int nro);
	void setChillPower(int nro);
	void setCoughPower(int nro);
	void setSneezePower(int nro);
	void setAcuracy(int newacuracy);
	void setX(int novox);
	void setY(int novoy);
	int getFeverPower();
	int getChillPower();
	int getCoughPower();
	int getSneezePower();
	int getAcuracia();
	int getTipo();
	int getX();
	int getY();
	Sprite getSprite();
	void setSprite(string path);
	int dano(int defense, float eficiencia);
	bool vivo = true;
	int getLevel();
	int getMaxHP();
	int getHP();
	int getAttack();
	int getDefense();
	int getSpeed();
	void setHP(int nro);
protected:
	int x, y;
	int nivel;
	int hp;
	int maxhp;
	int attack;
	int defense;
	int speed;
private:
	Sprite sprite;
	int classevirus;
	//1=red
	//2=yellow
	//3=green
	//4=cyan
	//5=blue
	//6=purple
	//7=pink
	//8=covid
	int feverpower;
	int chillpower;
	int coughpower;
	int sneezepower;
	int acuracia = 2;
};

