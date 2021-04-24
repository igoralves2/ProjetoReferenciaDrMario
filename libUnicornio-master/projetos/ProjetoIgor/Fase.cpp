#include "Fase.h"
#include "Virus.h"
#include "RedVirus.h"
#include "YellowVirus.h"
#include "GreenVirus.h"
#include "CyanVirus.h"
#include "BlueVirus.h"
#include "PurpleVirus.h"
#include "PinkVirus.h"
#include "Covid.h"
#include <malloc.h>
using namespace std;
Fase::Fase()
{
}

Fase::~Fase()
{
}

void Fase::carregar(long* score, Player* pnovo, bool novosun, int novodia, int novomes, int novoano, int novolocal)
{
	fasewidth = 1000;
	faseheight = 1000;
	this->levelscore = *score;
	(*pnovo).sprite.setSpriteSheet("drmario");
	(*pnovo).x = fasewidth / 2;
	(*pnovo).y = faseheight / 2;
	this->sun = novosun;
	this->dia = novodia;
	this->mes = novomes;
	this->ano = novoano;
	this->local = novolocal;
	this->levelscore = 0;
	this->virusderrotados = 0;
	this->nroViruses = 8;
	
	Virus red = RedVirus();
	red.setStatus(1,10,1,1,1);
	//red.sprite.setSpriteSheet("redvirus");
	red.x = (fasewidth / 2 - 360);
	red.y = (faseheight / 2 - 400);

	Virus yellow = YellowVirus();
	yellow.setStatus(1, 10, 1, 1, 1);
	//yellow.sprite.setSpriteSheet("yellowvirus");
	yellow.x = (fasewidth / 2 - 240);
	yellow.y = (faseheight / 2 - 400);

	Virus blue = BlueVirus();
	blue.setStatus(1, 10, 1, 1, 1);
	//blue.sprite.setSpriteSheet("bluevirus");
	blue.x = (fasewidth / 2 + 240);
	blue.y = (faseheight / 2 - 400);

	Virus cyan = CyanVirus();
	cyan.setStatus(1, 10, 1, 1, 1);
	//cyan.sprite.setSpriteSheet("cyanvirus");
	cyan.x = (fasewidth / 2 + 360);
	cyan.y = (faseheight / 2 - 400);

	Virus green = GreenVirus();
	green.setStatus(1, 10, 1, 1, 1);
	//green.sprite.setSpriteSheet("greenvirus");
	green.x = (fasewidth / 2 - 360);
	green.y = (faseheight / 2 + 400);

	Virus purple = PurpleVirus();
	purple.setStatus(1, 10, 1, 1, 1);
	//purple.sprite.setSpriteSheet("purplevirus");
	purple.x = fasewidth / 2 - 240;
	purple.y = (faseheight / 2 + 400);

	Virus pink = PinkVirus();
	pink.setStatus(1, 10, 1, 1, 1);
	//pink.sprite.setSpriteSheet("pinkvirus");
	pink.x = (fasewidth / 2 + 240);
	pink.y = (faseheight / 2 + 400);

	Virus covid = Covid();
	covid.setStatus(1, 10, 1, 1, 1);
	//covid.sprite.setSpriteSheet("covid");
	covid.x = (fasewidth / 2 + 360);
	covid.y = (faseheight / 2 + 400);

	(*pnovo).c.resetPosition(&(*pnovo).x, &(*pnovo).y);
	(*pnovo).c.setSprite("capsule");
	(*pnovo).ag.resetPosition(&(*pnovo).x, &(*pnovo).y);
	(*pnovo).ag.setSprite("alcoolgel");
	(*pnovo).v.resetPosition(&(*pnovo).x, &(*pnovo).y);
	(*pnovo).v.setSprite("vacina");
	playercamera = Camera();
	playercamera.setX((*pnovo).x);
	playercamera.setY((*pnovo).y);
	viruses = (Virus*)realloc(viruses, 8*sizeof(Virus));
	viruses[0] = red;
	viruses[1] = yellow;
	viruses[2] = green;
	viruses[3] = cyan;
	viruses[4] = blue;
	viruses[5] = purple;
	viruses[6] = pink;
	viruses[7] = covid;
}

void Fase::carregar(string filePath, long* score, Player* pnovo, bool novosun, int novodia, int novomes, int novoano, int novolocal)
{
	ifstream arq;
	arq.open(filePath, ios::in);
	if (arq.is_open()) {
		fasewidth = 1000;
		faseheight = 1000;
		this->levelscore = *score;
		(*pnovo).sprite.setSpriteSheet("drmario");
		(*pnovo).x = fasewidth / 2;
		(*pnovo).y = faseheight / 2;
		(*pnovo).c.resetPosition(&(*pnovo).x, &(*pnovo).y);
		(*pnovo).c.setSprite("capsule");
		(*pnovo).ag.resetPosition(&(*pnovo).x, &(*pnovo).y);
		(*pnovo).ag.setSprite("alcoolgel");
		(*pnovo).v.resetPosition(&(*pnovo).x, &(*pnovo).y);
		(*pnovo).v.setSprite("vacina");
		this->sun = novosun;
		this->dia = novodia;
		this->mes = novomes;
		this->ano = novoano;
		this->local = novolocal;
		this->levelscore = 0;
		this->virusderrotados = 0;
		arq >> nroViruses;
		viruses = new Virus[nroViruses];
		int tipo;
		int nivel;
		int hp;
		int atk;
		int def;
		int spd;
		int x;
		int y;
		//Virus* r;
		for (int i = 0; i < nroViruses; i++) {
			arq >> tipo;
			arq >> nivel;
			arq >> hp;
			arq >> atk;
			arq >> def;
			arq >> spd;
			arq >> x;
			arq >> y;
			Virus v;
			switch (tipo) {
			case 1://Red
				v = RedVirus();
				v.setStatus(nivel, hp, atk, def, spd);
				v.x = x;
				v.y = y;
				viruses[i] = v;
				break;
			case 2://Yellow
				v = YellowVirus();
				v.setStatus(nivel, hp, atk, def, spd);
				v.x = x;
				v.y = y;
				viruses[i] = v;
				break;
			case 3://Green
				v = GreenVirus();
				v.setStatus(nivel, hp, atk, def, spd);
				v.x = x;
				v.y = y;
				viruses[i] = v;
				break;
			case 4://Cyan
				v = CyanVirus();
				v.setStatus(nivel, hp, atk, def, spd);
				v.x = x;
				v.y = y;
				viruses[i] = v;
				break;
			case 5://Blue
				v = BlueVirus();
				v.setStatus(nivel, hp, atk, def, spd);
				v.x = x;
				v.y = y;
				viruses[i] = v;
				break;
			case 6://Purple
				v = PurpleVirus();
				v.setStatus(nivel, hp, atk, def, spd);
				v.x = x;
				v.y = y;
				viruses[i] = v;
				break;
			case 7://Pink
				v = PinkVirus();
				v.setStatus(nivel, hp, atk, def, spd);
				v.x = x;
				v.y = y;
				viruses[i] = v;
				break;
			default://Covid
				v = Covid();
				v.setStatus(nivel, hp, atk, def, spd);
				v.x = x;
				v.y = y;
				viruses[i] = v;
				break;
			}
		}
		arq.close();
	}
	else {
		std::cout << "Erro! Fase não carregada!" << std::endl;
	}
}

void Fase::atualizar(Player* pnovo)
{
	//tick
	(*pnovo).atualizar(fasewidth, faseheight);
	if ((*pnovo).atirandocomprimido) {
		(*pnovo).atirandocomprimido = false;
		if (!(*pnovo).c.movendo) {
			(*pnovo).c.movendo = true;
			int dx = 0;
			int dy = 0;
			if ((*pnovo).currentdir == (*pnovo).up) {
				dy = -1;
			}if ((*pnovo).currentdir == (*pnovo).down) {
				dy = 1;
			}
			if ((*pnovo).currentdir == (*pnovo).left) {
				dx = -1;
			}if ((*pnovo).currentdir == (*pnovo).right) {
				dx = 1;
			}
			(*pnovo).c.setPosition(&(*pnovo).x, &(*pnovo).y, &dx, &dy);
		}
	}if ((*pnovo).atirandoalcoolgel) {
		(*pnovo).atirandoalcoolgel = false;
		if (!(*pnovo).ag.movendo && !(*pnovo).ag.explodindo) {
			(*pnovo).ag.movendo = true;
			int dx = 0;
			int dy = 0;
			if ((*pnovo).currentdir == (*pnovo).up) {
				dy = -1;
			}if ((*pnovo).currentdir == (*pnovo).down) {
				dy = 1;
			}
			if ((*pnovo).currentdir == (*pnovo).left) {
				dx = -1;
			}if ((*pnovo).currentdir == (*pnovo).right) {
				dx = 1;
			}
			(*pnovo).ag.setPosition(&(*pnovo).x, &(*pnovo).y, &dx, &dy);
		}
	}if ((*pnovo).usandovacina) {
		(*pnovo).usandovacina = false;
		if (!(*pnovo).v.movendo) {
			(*pnovo).v.movendo = true;
			int dx = 0;
			int dy = 0;
			if ((*pnovo).currentdir == (*pnovo).up) {
				dy = -1;
			}if ((*pnovo).currentdir == (*pnovo).down) {
				dy = 1;
			}
			if ((*pnovo).currentdir == (*pnovo).left) {
				dx = -1;
			}if ((*pnovo).currentdir == (*pnovo).right) {
				dx = 1;
			}
			(*pnovo).v.setPosition(&(*pnovo).x, &(*pnovo).y, &dx, &dy);
		}
	}
	int novox = playercamera.clamp((*pnovo).x - (gJanela.getLargura() / 2), 0, fasewidth - gJanela.getLargura());
	playercamera.setX(novox);
	int novoy = playercamera.clamp((*pnovo).y - gJanela.getAltura() / 2, 0, faseheight - gJanela.getAltura());
	playercamera.setY(novoy);
	bool atualizouc = false;
	bool atualizouag = false;
	bool atualizouv = false;
	if (!(*pnovo).c.movendo) {
		(*pnovo).c.x = (*pnovo).x;
		(*pnovo).c.y = (*pnovo).y;
	}
	else {
		(*pnovo).c.atualizar();
		atualizouc = true;
	}
	if (!(*pnovo).ag.movendo && !(*pnovo).ag.explodindo) {
		(*pnovo).ag.x = (*pnovo).x;
		(*pnovo).ag.y = (*pnovo).y;
	}
	else{
		(*pnovo).ag.atualizar();
		atualizouag = true;
	}
	if(!(*pnovo).v.movendo) {
		(*pnovo).v.x = (*pnovo).x;
		(*pnovo).v.y = (*pnovo).y;
	}
	else {
		(*pnovo).v.atualizar();
		atualizouv = true;
	}
	for (int i = 0; i < nroViruses; i++) {
		if (viruses[i].vivo) {
			viruses[i].atualizar((*pnovo).x, (*pnovo).y);
			bool colidiujogador = ((abs((*pnovo).x - viruses[i].x) < 50) && (abs((*pnovo).y - viruses[i].y) < 50));
			if (colidiujogador) {
				(*pnovo).hp -= viruses[i].dano((*pnovo).defense, (*pnovo).m.getEficienciaContagio());
				if ((*pnovo).hp <= 0) {
					return;
				}
			}
			bool colidiuComprimido = uniTestarColisaoSpriteComSprite((*pnovo).c.getSprite(), (*pnovo).c.x, (*pnovo).c.y, 0,
				viruses[i].getSprite(), viruses[i].x, viruses[i].y, 0);
			bool colidiuAlcoolGel = false;
			bool colidiuVacina = uniTestarColisaoSpriteComSprite((*pnovo).v.getSprite(), (*pnovo).v.x, (*pnovo).v.y, 0,
				viruses[i].getSprite(), viruses[i].x, viruses[i].y, 0);
			if ((*pnovo).ag.explodindo) {
				colidiuAlcoolGel = uniTestarColisaoCirculoComSprite((*pnovo).ag.x, (*pnovo).ag.y, 100, viruses[i].getSprite(),
					viruses[i].x, viruses[i].y, 0);
			}
			else if((*pnovo).ag.movendo){
				colidiuAlcoolGel = uniTestarColisaoSpriteComSprite((*pnovo).ag.getSprite(), (*pnovo).ag.x, (*pnovo).ag.y, 0,
					viruses[i].getSprite(), viruses[i].x, viruses[i].y, 0);
			}
			if (colidiuComprimido && atualizouc) {
				viruses[i].hp -= (*pnovo).c.dano((*pnovo).nivel, (*pnovo).attack, viruses[i].defense);
				if (viruses[i].hp <= 0) {
					viruses[i].vivo = false;
					setScore(getScore() + 10);
					virusderrotados++;
				}
				(*pnovo).c.resetPosition(&(*pnovo).x, &(*pnovo).y);
			}
			if (colidiuAlcoolGel && atualizouag) {
				//(*pnovo).ag.explodindo = true;
				viruses[i].hp -= (*pnovo).ag.dano((*pnovo).nivel, (*pnovo).attack, viruses[i].defense);
				if (viruses[i].hp <= 0) {
					viruses[i].vivo = false;
					setScore(getScore() + 10);
					virusderrotados++;
				}
				(*pnovo).ag.resetPosition(&(*pnovo).x, &(*pnovo).y);
			}if (colidiuVacina && atualizouv) {
				viruses[i].hp -= (*pnovo).v.dano((*pnovo).nivel, (*pnovo).attack, viruses[i].defense);
				if (viruses[i].hp <= 0) {
					viruses[i].vivo = false;
					setScore(getScore() + 10);
					virusderrotados++;
				}
				(*pnovo).v.resetPosition(&(*pnovo).x, &(*pnovo).y);
			}
		}
	}
	//Render
	
	if ((*pnovo).c.movendo) {
		(*pnovo).c.getSprite().desenhar((*pnovo).c.x - playercamera.getX(), (*pnovo).c.y - playercamera.getY());
	}
	if ((*pnovo).ag.movendo) {
		(*pnovo).ag.getSprite().desenhar((*pnovo).ag.x - playercamera.getX(), (*pnovo).ag.y - playercamera.getY());
	}
	if ((*pnovo).ag.explodindo) {
		gGraficos.desenharCirculo((*pnovo).ag.x - playercamera.getX(), (*pnovo).ag.y - playercamera.getY(), 100, 255, 255, 255, 255, true);
	}
	if ((*pnovo).v.movendo) {
		(*pnovo).v.getSprite().desenhar((*pnovo).v.x - playercamera.getX(), (*pnovo).v.y - playercamera.getY());
	}
	(*pnovo).sprite.desenhar((*pnovo).x - playercamera.getX(), (*pnovo).y - playercamera.getY());
	for (int i = 0; i < nroViruses; i++) {
		if (abs(viruses[i].x - playercamera.getX()) / 2 <= gJanela.getLargura() / 2 &&
			abs(viruses[i].y - playercamera.getY()) / 2 <= gJanela.getAltura() / 2) {//Se está dentro da camera
			if (viruses[i].vivo) {
				viruses[i].getSprite().desenhar(viruses[i].x - playercamera.getX(), viruses[i].y - playercamera.getY());
			}
		}
	}
}

void Fase::desenhar()
{
	Texto pontuacao;
	pontuacao.setFonte("supermario256");
	pontuacao.setCor(0, 0, 0);
	pontuacao.setString("" + this->getScore());
	pontuacao.setEscalaX(1);
	pontuacao.setEscalaY(1);
	pontuacao.setAlinhamento(TEXTO_CENTRALIZADO);
	pontuacao.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() - 10);
}

void Fase::finalizar()
{
}

bool Fase::concluida(Player *pnovo)
{
	if ((*pnovo).hp <= 0) {
		(*pnovo).hp = (*pnovo).maxhp;
		return false;
	}
	setScore(getScore() + (long)(*pnovo).hp * 10);
	return true;
}

bool Fase::finalizada(Player* pnovo)
{
	return (*pnovo).hp <= 0 || virusderrotados == nroViruses;
}

Virus* Fase::getViruses()
{
    return viruses;
}



long Fase::getScore()
{
	return levelscore;
}

void Fase::setScore(long newscore)
{
	this->levelscore = newscore;
}

