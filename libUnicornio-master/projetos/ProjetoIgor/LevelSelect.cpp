#include "LevelSelect.h"

using namespace std;

void LevelSelect::carregar()
{
		info.setFonte("supermario256");
		info.setCor(0, 0, 0);
		info.setString("os paises estao sendo atacados pelo covid e suas variantes!\n" "salve todos eles quanto e tempo!");
		info.setEscalaX(1);
		info.setEscalaY(1);
		info.setAlinhamento(TEXTO_CENTRALIZADO);
		infolocal.setFonte("supermario256");
		infolocal.setCor(0, 0, 0);
		infolocal.setString("1 = Egito\n" "2 = Grecia\n" "3 = Persia\n" "4 = Italia\n" "5 = Mexico\n" "6 = China\n" "7 = Brasil");
		infolocal.setEscalaX(1);
		infolocal.setEscalaY(1);
		infolocal.setAlinhamento(TEXTO_CENTRALIZADO);
		lua.setEscala(0.25, 0.25);
		sol.setEscala(0.5, 0.5);
		infodia.setFonte("supermario256");
		infodia.setCor(0, 0, 0);
		infodia.setString("dia");
		infodia.setEscalaX(1);
		infodia.setEscalaY(1);
		infodia.setAlinhamento(TEXTO_CENTRALIZADO);
		infomes.setFonte("supermario256");
		infomes.setCor(0, 0, 0);
		infomes.setString("mes");
		infomes.setEscalaX(1);
		infomes.setEscalaY(1);
		infomes.setAlinhamento(TEXTO_CENTRALIZADO);
		infoano.setFonte("supermario256");
		infoano.setCor(0, 0, 0);
		infoano.setString("ano");
		infoano.setEscalaX(1);
		infoano.setEscalaY(1);
		infoano.setAlinhamento(TEXTO_CENTRALIZADO);
}

void LevelSelect::executar()
{
	opcao1 = false;
	opcao2 = false;
	opcao3 = false;
	opcao4 = false;
	opcao5 = false;
	opcao6 = false;
	opcao7 = false;
	if (gTeclado.pressionou[TECLA_Z]) {
		dia = !dia;
	}
			if (gTeclado.pressionou[TECLA_1]) {
				opcao1 = true;
			}
			else if (gTeclado.pressionou[TECLA_2]) {
				opcao2 = true;
			}
			else if (gTeclado.pressionou[TECLA_3]) {
				opcao3 = true;
			}
			else if (gTeclado.pressionou[TECLA_4]) {
				opcao4 = true;
			}
			else if (gTeclado.pressionou[TECLA_5]) {
				opcao5 = true;
			}
			else if (gTeclado.pressionou[TECLA_6]) {
				opcao6 = true;
			}
			else if (gTeclado.pressionou[TECLA_7]) {
				opcao7 = true;
			}else if (gTeclado.pressionou[TECLA_CIMA]) {
				opcaodata = (opcaodata - 1) % 3;
			}
			else if (gTeclado.pressionou[TECLA_BAIXO]) {
				opcaodata = (opcaodata + 1) % 3;
			}
			else if (gTeclado.pressionou[TECLA_DIR]) {
				if (opcaodata == 0) {
					if (datames == 4 || datames == 6 || datames == 9 || datames == 11) {
						datadia = (datadia + 1) % 30;
						if (datadia == 0) {
							datadia = 30;
						}
					}
					else if (datames == 2) {
						if (dataano % 4 == 0) {
							datadia = (datadia + 1) % 29;
							if (datadia == 0) {
								datadia = 29;
							}
						}
						else {
							datadia = (datadia + 1) % 28;
							if (datadia == 0) {
								datadia = 28;
							}
						}
					}
					else {
						datadia = (datadia + 1) % 31;
						if (datadia == 0) {
							datadia = 31;
						}
					}
				}
				else if(opcaodata == 1){
					datames = (datames + 1) % 12;
					if (datames == 0) {
						datames = 12;
					}
				}
				else {
					dataano = (dataano + 1) % 2021;
					if (dataano == 0) {
						dataano = 2021;
					}
				}
			}
			else if (gTeclado.pressionou[TECLA_ESQ]) {
				if (opcaodata == 0) {
					if (datames == 4 || datames == 6 || datames == 9 || datames == 11) {
						datadia = (datadia - 1) % 30;
						if (datadia == 0) {
							datadia = 30;
						}
					}
					else if (datames == 2) {
						if (dataano % 4 == 0) {
							datadia = (datadia - 1) % 29;
							if (datadia == 0) {
								datadia = 29;
							}
						}
						else {
							datadia = (datadia - 1) % 28;
							if (datadia == 0) {
								datadia = 28;
							}
						}
					}
					else {
						datadia = (datadia - 1) % 31;
						if (datadia == 0) {
							datadia = 31;
						}
					}
				}
				else if (opcaodata == 1) {
					datames = (datames - 1) % 12;
					if (datames == 0) {
						datames = 12;
					}
				}
				else {
					dataano = (dataano - 1) % 2021;
					if (dataano == 0) {
						dataano = 2021;
					}
				}
			}
}



void LevelSelect::desenhar()
{
	info.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 100);
	infolocal.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (dia) {
		sol.desenhar(50, gJanela.getAltura() / 2 - 50);
	}
	else {
		lua.desenhar(gJanela.getLargura() - 45, gJanela.getAltura() / 2 - 50);
	}
	infodia.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 2 + 70);
	infomes.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 2 + 90);
	infoano.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 2 + 110);
}

void LevelSelect::desenharConfig() {
	Texto aux, aux2, aux3;
	aux.setFonte("supermario256");
	aux.setCor(0, 0, 0);
	aux.setString(std::to_string(datadia));
	aux.setEscalaX(1);
	aux.setEscalaY(1);
	aux.setAlinhamento(TEXTO_CENTRALIZADO);
	aux.desenhar(gJanela.getLargura() * 3 / 4, gJanela.getAltura()/2 + 70);
	aux2.setFonte("supermario256");
	aux2.setCor(0, 0, 0);
	aux2.setString(std::to_string(datames));
	aux2.setEscalaX(1);
	aux2.setEscalaY(1);
	aux2.setAlinhamento(TEXTO_CENTRALIZADO);
	aux2.desenhar(gJanela.getLargura() * 3 / 4, gJanela.getAltura()/2 + 90);
	aux3.setFonte("supermario256");
	aux3.setCor(0, 0, 0);
	aux3.setString(std::to_string(dataano));
	aux3.setEscalaX(1);
	aux3.setEscalaY(1);
	aux3.setAlinhamento(TEXTO_CENTRALIZADO);
	aux3.desenhar(gJanela.getLargura() * 3 / 4, gJanela.getAltura()/2 + 110);
}
