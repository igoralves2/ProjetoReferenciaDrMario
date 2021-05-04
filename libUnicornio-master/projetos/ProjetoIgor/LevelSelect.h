#pragma once
#include "libUnicornio.h";
#include <string>;
class LevelSelect
{
public:
	void carregar();
	void executar();
	void desenhar();
	void desenharConfig();
	Sprite lua;
	Sprite sol;
	int opcaodata = 0;
	int datadia = 1;
	int datames = 1;
	int dataano = 2020;
	bool dia = true;
	bool opcao1 = false;
	bool opcao2 = false;
	bool opcao3 = false;
	bool opcao4 = false;
	bool opcao5 = false;
	bool opcao6 = false;
	bool opcao7 = false;
protected:
	bool noFinal = false;
	int niveisconcluidos = 0;
	Texto info;
	Texto infolocal;
	Texto infodia;
	Texto infomes;
	Texto infoano;
};

