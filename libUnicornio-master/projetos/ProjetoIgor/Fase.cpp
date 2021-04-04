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

Fase::Fase()
{
}

Fase::~Fase()
{
}

void Fase::carregar(long* score, Player* pnovo, bool novosun, int novodia, int novomes, int novoano, int novolocal)
{
	this->levelscore = *score;
	(*pnovo).sprite.setSpriteSheet("drmario");
	(*pnovo).x = gJanela.getLargura() / 2;
	(*pnovo).y = gJanela.getAltura() / 2;
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
	red.sprite.setSpriteSheet("redvirus");
	red.x = (gJanela.getLargura() / 2 - 270);
	red.y = (gJanela.getAltura() / 2 - 200);

	Virus yellow = YellowVirus();
	yellow.setStatus(1, 20, 1, 1, 1);
	yellow.sprite.setSpriteSheet("yellowvirus");
	yellow.x = (gJanela.getLargura() / 2 - 160);
	yellow.y = (gJanela.getAltura() / 2 - 200);

	Virus blue = BlueVirus();
	blue.setStatus(1, 20, 1, 1, 1);
	blue.sprite.setSpriteSheet("bluevirus");
	blue.x = (gJanela.getLargura() / 2 + 160);
	blue.y = (gJanela.getAltura() / 2 - 200);

	Virus cyan = CyanVirus();
	cyan.setStatus(1, 20, 1, 1, 1);
	cyan.sprite.setSpriteSheet("cyanvirus");
	cyan.x = (gJanela.getLargura() / 2 + 270);
	cyan.y = (int)(gJanela.getAltura() / 2 - 200);

	Virus green = GreenVirus();
	green.setStatus(1, 20, 1, 1, 1);
	green.sprite.setSpriteSheet("greenvirus");
	green.x = (gJanela.getLargura() / 2 - 270);
	green.y = (gJanela.getAltura() / 2 + 200);

	Virus purple = PurpleVirus();
	purple.setStatus(1, 20, 1, 1, 1);
	purple.sprite.setSpriteSheet("purplevirus");
	purple.x = gJanela.getLargura() / 2 - 160;
	purple.y = (int)(gJanela.getAltura() / 2 + 200);

	Virus pink = PinkVirus();
	pink.setStatus(1, 20, 1, 1, 1);
	pink.sprite.setSpriteSheet("pinkvirus");
	pink.x = (gJanela.getLargura() / 2 + 160);
	pink.y = (gJanela.getAltura() / 2 + 200);

	Virus covid = Covid();
	covid.setStatus(1, 20, 1, 1, 1);
	covid.sprite.setSpriteSheet("covid");
	covid.x = (int)(gJanela.getLargura() / 2 + 270);
	covid.y = (int)(gJanela.getAltura() / 2 + 200);

	(*pnovo).c.resetPosition(&(*pnovo).x, &(*pnovo).y);
	(*pnovo).c.sprite.setSpriteSheet("capsule");
	(*pnovo).ag.resetPosition(&(*pnovo).x, &(*pnovo).y);
	(*pnovo).ag.sprite.setSpriteSheet("alcoolgel");
	(*pnovo).v.resetPosition(&(*pnovo).x, &(*pnovo).y);
	(*pnovo).v.sprite.setSpriteSheet("vacina");

	viruses[0] = red;
	viruses[1] = yellow;
	viruses[2] = green;
	viruses[3] = cyan;
	viruses[4] = blue;
	viruses[5] = purple;
	viruses[6] = pink;
	viruses[7] = covid;

}


void Fase::atualizar(Player* pnovo)
{
	(*pnovo).atualizar();
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
		if (!(*pnovo).ag.movendo) {
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
	if (!(*pnovo).ag.movendo) {
		(*pnovo).ag.x = (*pnovo).x;
		(*pnovo).ag.y = (*pnovo).y;
	}
	else {
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
	for (int i = 0; i < 8; i++) {
		if (viruses[i].vivo) {
			//viruses[i].atualizar(p.x, p.y);
			bool colidiujogador = ((abs((*pnovo).x - viruses[i].x) < 50) && (abs((*pnovo).y - viruses[i].y) < 50));
			if (colidiujogador) {
				(*pnovo).hp -= viruses[i].dano((*pnovo).defense, (*pnovo).m.getEficienciaContagio());
				if ((*pnovo).hp <= 0) {
					return;
				}
			}
			bool colidiuComprimido = uniTestarColisaoSpriteComSprite((*pnovo).c.sprite, (*pnovo).c.x, (*pnovo).c.y, 10,
				viruses[i].getSprite(), viruses[i].x, viruses[i].y, 10);
			bool colidiuAlcoolGel = false;
			bool colidiuVacina = uniTestarColisaoSpriteComSprite((*pnovo).v.sprite, (*pnovo).v.x, (*pnovo).v.y, 10,
				viruses[i].getSprite(), viruses[i].x, viruses[i].y, 10);
			if ((*pnovo).ag.explodindo) {
				colidiuAlcoolGel = uniTestarColisaoCirculoComSprite((*pnovo).ag.x, (*pnovo).ag.y, 100, viruses[i].sprite,
					viruses[i].x, viruses[i].y, 10);
			}
			else {
				colidiuAlcoolGel = uniTestarColisaoSpriteComSprite((*pnovo).ag.sprite, (*pnovo).ag.x, (*pnovo).ag.y, 10,
					viruses[i].sprite, viruses[i].x, viruses[i].y, 10);
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
	if ((*pnovo).c.movendo) {
		(*pnovo).c.sprite.desenhar((*pnovo).c.x, (*pnovo).c.y);
	}
	if ((*pnovo).ag.movendo) {
		(*pnovo).ag.sprite.desenhar((*pnovo).ag.x, (*pnovo).ag.y);
	}
	else if ((*pnovo).ag.explodindo) {
		gGraficos.desenharCirculo((*pnovo).ag.x, (*pnovo).ag.y, 100, 255, 255, 255);
	}
	if ((*pnovo).v.movendo) {
		(*pnovo).v.sprite.desenhar((*pnovo).v.x, (*pnovo).v.y);
	}
	(*pnovo).sprite.desenhar((*pnovo).x, (*pnovo).y);
	for (int i = 0; i < 8; i++) {
		if (viruses[i].vivo) {
			viruses[i].sprite.desenhar(viruses[i].x, viruses[i].y);
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

