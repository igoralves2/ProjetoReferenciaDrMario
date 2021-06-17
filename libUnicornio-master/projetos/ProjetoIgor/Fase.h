#pragma once
#include "Virus.h"
#include "Player.h"
#include "Camera.h"
#include <fstream>
class Fase
{
public:
	Fase();
	~Fase();
	void carregar(long* score, Player* pnovo, bool novosun, int novodia, int novomes, int novoano, int novolocal);
	void atualizar(Player* pnovo);
	void desenhar();
	void finalizar();
	void carregar(string filePath, long* score, Player* pnovo, bool novosun, int novodia, int novomes, int novoano, int novolocal);
	bool concluida(Player* pnovo);
	bool finalizada(Player* pnovo);
	Virus* getViruses();
	long getScore();
	void setScore(long newscore);
	int getNroViruses();
	bool carregoufase();
protected:
	int fasewidth;
	int faseheight;
	long levelscore = 0;
	bool sun;
	int dia;
	int mes;
	int ano;
	int local;
	Virus *viruses = (Virus*)calloc(8, sizeof(Virus));
	int virusderrotados = 0;
	int nroViruses;
	Camera playercamera;
	bool carregou = false;
};

