#include "TelaJogo.h"
//#include <calendardeviceservice.h>
//#include <ctime>

TelaJogo::TelaJogo()
{
	setTipo(6);
    t.setFonte("supermario256");
    t.setCor(0, 0, 0);
    t.setEscalaX(1);
    t.setEscalaY(1);
    t.setAlinhamento(TEXTO_CENTRALIZADO);
}

void TelaJogo::executar(Player* p, string nomes[5], long scorelist[5], Fila<Usuario>* uc, Usuario* atual, string files[3])
{
	if (gTeclado.pressionou[TECLA_SHIFT_ESQ]) {
		estaPausado = !estaPausado;
	}
	if (!estaPausado) {
		if(fase == nullptr){
			fase = new Fase();
			score = atual->getScore();
			switch (indexfaseatual) {
			case 0:
				fase->carregar("../fase1.txt", &score, p, dia, 1, 1, 2000, 1);
				break;
			case 1:
				fase->carregar("../fase2.txt", &score, p, dia, 1, 1, 2000, 2);
				break;
			case 2:
				fase->carregar("../fase3.txt", &score, p, dia, 1, 1, 2000, 3);
				break;
			case 3:
				fase->carregar("../fase4.txt", &score, p, dia, 1, 1, 2000, 4);
				break;
			case 4:
				fase->carregar("../fase5.txt", &score, p, dia, 1, 1, 2000, 5);
				break;
			case 5:
				fase->carregar("../fase6.txt", &score, p, dia, 1, 1, 2000, 6);
				break;
			case 6:
				fase->carregar("../fase7.txt", &score, p, dia, 1, 1, 2000, 7);
				break;
			default:
				indexfaseatual = 0;
				fase->carregar("../fase1.txt", &score, p, dia, 1, 1, 2000, 1);
				break;
			}
		}if (!fase->finalizada(p)) {
			Texto nivelcenario;
			nivelcenario.setFonte("supermario256");
			nivelcenario.setCor(0, 0, 0);
			nivelcenario.setString("Level " + to_string(indexfaseatual + 1));
			nivelcenario.setEscalaX(1);
			nivelcenario.setEscalaY(1);
			nivelcenario.setAlinhamento(TEXTO_CENTRALIZADO);
			nivelcenario.desenhar(gJanela.getLargura() / 2, 10);
			fase->atualizar(p);
		}
		else if (fase->concluida(p) && !emlevelup) {
			if (!podeinserirnome) {
				podeinserirnome = true;
				nomejogador.inicializar();
			}
			else {
				nomejogador.atualizar();
			}
			Texto vitoria;
			vitoria.setFonte("supermario256");
			vitoria.setCor(0, 0, 0);
			vitoria.setString("Level Complete! Register your name.\n""Your score:" + to_string(score + fase->getNroViruses() * 10 + (*p).hp * 10) + "\n""Press ENTER key to continue");
			vitoria.setEscalaX(1);
			vitoria.setEscalaY(1);
			vitoria.setAlinhamento(TEXTO_CENTRALIZADO);
			vitoria.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
			nomejogador.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 50);
			if (gTeclado.pressionou[TECLA_ENTER]) {
				podeinserirnome = false;
				bool achounome = false;
				int i = 0;
				for (i = 0; i < 5; i++) {
					if (nomes[i] == atual->getName()) {
						achounome = true;
						break;
					}
				}
				if (achounome) {
					string nomeatual = atual->getName();
					long pontuacaoatual = score + fase->getNroViruses() * 10 + (*p).hp * 10;
					for (int j = 0; j <= i; j++) {
						if (pontuacaoatual > scorelist[j]) {
							string auxs = nomes[j];
							nomes[j] = nomeatual;
							nomeatual = auxs;
							long auxl = scorelist[j];
							scorelist[j] = pontuacaoatual;
							pontuacaoatual = auxl;
						}
					}
				}
				else {
					string nomeatual = atual->getName();
					long pontuacaoatual = score + fase->getNroViruses() * 10 + (*p).hp * 10;
					for (int j = 0; j < 5; j++) {
						if (pontuacaoatual > scorelist[j]) {
							string auxs = nomes[j];
							nomes[j] = nomeatual;
							nomeatual = auxs;
							long auxl = scorelist[j];
							scorelist[j] = pontuacaoatual;
							pontuacaoatual = auxl;
						}
					}
				}
				if ((score + fase->getNroViruses() * 10 + (*p).hp * 10) > 10000 * (*p).nivel) {
					(*p).nivel++;
					score += fase->getNroViruses() * 10 + (*p).hp * 10;
					atual->setScore(score);
					emlevelup = true;
				}
				else {
					string auxd = __DATE__;
					string auxt = __TIME__;
					score += fase->getNroViruses() * 10 + (*p).hp * 10;
					indexfaseatual = (indexfaseatual + 1) % 7;
					atual->setScore(score);
					fase = nullptr;
					string dataconclusao = __DATE__;
					string horarioconclusao = to_string(_timezone);
					int index = 0;
					bool achouespaco = false;
					for (index; index < 3; index++) {
						if (files[index] == "EMPTY") {
							achouespaco = true;
							files[index] = auxd;
							break;
						}
					}
					if (achouespaco) {
						ofstream saida("../" + files[index] + ".txt", ios::out);
						if (saida.is_open()) {
							saida << auxd << endl;
							//saida << auxt << endl;
							saida << atual->getName() << endl;
							saida << atual->getScore() << endl;
							saida << (indexfaseatual + 1) << endl;
							saida << p->nivel << endl;
							saida << p->hp << endl;
							saida << p->maxhp << endl;
							saida << p->attack << endl;
							saida << p->defense << endl;
							saida << p->speed << endl;
							saida.close();
						}
						else {
							return;
						}
					}
				}
				//atual->setPlayer(*p);
			}
		}
		else if (emlevelup) {
			Texto levelup;
			levelup.setFonte("supermario256");
			levelup.setCor(0, 0, 0);
			levelup.setString("level up! chosse:\n""1=increase hp max\n""2=increase attack""\n3=increase defense\n""4=increase speed\n");
			levelup.setEscalaX(1);
			levelup.setEscalaY(1);
			levelup.setAlinhamento(TEXTO_CENTRALIZADO);
			levelup.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
			if (gTeclado.pressionou[TECLA_1]) {
				(*p).maxhp += 10;
				(*p).hp = (*p).maxhp;
				emlevelup = false;
				indexfaseatual = (indexfaseatual + 1) % 7;
				fase = nullptr;
				//atual->setPlayer(*p);
			}
			else if (gTeclado.pressionou[TECLA_2]) {
				(*p).attack++;
				emlevelup = false;
				indexfaseatual = (indexfaseatual + 1) % 7;
				fase = nullptr;
				//atual->setPlayer(*p);
			}
			else if (gTeclado.pressionou[TECLA_3]) {
				(*p).defense++;
				emlevelup = false;
				indexfaseatual = (indexfaseatual + 1) % 7;
				fase = nullptr;
				//atual->setPlayer(*p);
			}
			else if (gTeclado.pressionou[TECLA_4]) {
				(*p).speed++;
				emlevelup = false;
				indexfaseatual = (indexfaseatual + 1) % 7;
				fase = nullptr;
				//atual->setPlayer(*p);
			}
		}
		else {
			Texto derrota;
			derrota.setFonte("supermario256");
			derrota.setCor(0, 0, 0);
			derrota.setString("Game Over!\n""Press ENTER to end");
			derrota.setEscalaX(1);
			derrota.setEscalaY(1);
			derrota.setAlinhamento(TEXTO_CENTRALIZADO);
			derrota.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
			if (gTeclado.pressionou[TECLA_ENTER]) {
				//p = new Player;
				p->maxhp = 100;
				p->hp = p->maxhp;
				p->nivel = 1;
				p->attack = 1;
				p->defense = 1;
				p->speed = 1;
				atual->setScore(0);
				//atual->setPlayer(*p);
				fase = nullptr;
				indexfaseatual = -1;
			}
		}
	
		Texto statusnivel;
		statusnivel.setFonte("supermario256");
		statusnivel.setCor(0, 0, 0);
		statusnivel.setString(" nivel:" + to_string((*p).nivel));
		statusnivel.setEscalaX(1);
		statusnivel.setEscalaY(1);
		statusnivel.setAlinhamento(TEXTO_CENTRALIZADO);
		statusnivel.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() - 30);

		Texto statusvidas;
		statusvidas.setFonte("supermario256");
		statusvidas.setCor(0, 0, 0);
		statusvidas.setString("hp:" + to_string((*p).hp) + "/" + to_string((*p).maxhp));
		statusvidas.setEscalaX(1);
		statusvidas.setEscalaY(1);
		statusvidas.setAlinhamento(TEXTO_CENTRALIZADO);
		statusvidas.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() - 30);

		Texto statusattack;
		statusattack.setFonte("supermario256");
		statusattack.setCor(0, 0, 0);
		statusattack.setString("ataque:" + to_string((*p).attack));
		statusattack.setEscalaX(1);
		statusattack.setEscalaY(1);
		statusattack.setAlinhamento(TEXTO_CENTRALIZADO);
		statusattack.desenhar(gJanela.getLargura() * 3 / 4, gJanela.getAltura() - 30);

		Texto statusdefense;
		statusattack.setFonte("supermario256");
		statusattack.setCor(0, 0, 0);
		statusattack.setString("defesa:" + to_string((*p).defense));
		statusattack.setEscalaX(1);
		statusattack.setEscalaY(1);
		statusattack.setAlinhamento(TEXTO_CENTRALIZADO);
		statusattack.desenhar(gJanela.getLargura() / 3, gJanela.getAltura() - 10);

		Texto statusspeed;
		statusspeed.setFonte("supermario256");
		statusspeed.setCor(0, 0, 0);
		statusspeed.setString("velocidade:" + to_string((*p).speed));
		statusspeed.setEscalaX(1);
		statusspeed.setEscalaY(1);
		statusspeed.setAlinhamento(TEXTO_CENTRALIZADO);
		statusspeed.desenhar(gJanela.getLargura() * 2 / 3, gJanela.getAltura() - 10);
	}
	else {
		Texto pausado;
		pausado.setFonte("supermario256");
		pausado.setCor(0, 0, 0);
		pausado.setString("voce quer parar de jogar?:\n""s=sim\n""n=nao");
		pausado.setEscalaX(1);
		pausado.setEscalaY(1);
		pausado.setAlinhamento(TEXTO_CENTRALIZADO);
		pausado.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		if (gTeclado.pressionou[TECLA_N]) {
			estaPausado = !estaPausado;
		}
		else if (gTeclado.pressionou[TECLA_S]) {
			saiu = true;
			fase = nullptr;
			indexfaseatual = -1;
		}
	}
	
}

bool TelaJogo::isDia()
{
	return dia;
}

void TelaJogo::setDia()
{
	dia = !dia;
}

long TelaJogo::getScore()
{
	return score;
}

void TelaJogo::setScore(int s)
{
	this->score = s;
}
