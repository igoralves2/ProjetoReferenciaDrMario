#pragma once
#include "Jogo.h";
#include "Virus.h";
#include <random>;
#include "Player.h";
#include "RedVirus.h"
#include "YellowVirus.h"
#include "GreenVirus.h"
#include "CyanVirus.h"
#include "BlueVirus.h"
#include "PurpleVirus.h"
#include "PinkVirus.h"
#include "Covid.h"
#include <string>

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false, "Dr Mario RPG: COVID Attack");

	//	O resto da inicialização vem aqui!
	//	...
	gRecursos.carregarSpriteSheet("drmario", "../assets/DrMario.png");
	gRecursos.carregarSpriteSheet("levelmap", "../assets/levelselect.jpg");
	//Os 7 vírus
	gRecursos.carregarSpriteSheet("redvirus", "../assets/RedVirus.png");
	gRecursos.carregarSpriteSheet("yellowvirus", "../assets/YellowVirus.png");
	gRecursos.carregarSpriteSheet("bluevirus", "../assets/BlueVirus.png");
	gRecursos.carregarSpriteSheet("cyanvirus", "../assets/CyanVirus.png");
	gRecursos.carregarSpriteSheet("greenvirus", "../assets/GreenVirus.png");
	gRecursos.carregarSpriteSheet("purplevirus", "../assets/PurpleVirus.png");
	gRecursos.carregarSpriteSheet("pinkvirus", "../assets/PinkVirus.png");
	//O Covid
	gRecursos.carregarSpriteSheet("covid", "../assets/COVID.png");
	//Egito dia e noite
	gRecursos.carregarTextura("egitodia", "../assets/EgitoDia.jpg");
	gRecursos.carregarTextura("egitonoite", "../assets/EgitoNoite.jpg");
	//Grécia dia e noite
	gRecursos.carregarTextura("greciadia", "../assets/GreciaDia.jpg");
	gRecursos.carregarTextura("grecianoite", "../assets/GreciaNoite.jpg");
	//Pérsia dia e noite
	gRecursos.carregarTextura("persiadia", "../assets/PersiaDia.jpg");
	gRecursos.carregarTextura("persianoite", "../assets/PersiaNoite.jpg");
	//Itália dia e noite
	gRecursos.carregarTextura("italiadia", "../assets/ItaliaDia.jpg");
	gRecursos.carregarTextura("italianoite", "../assets/ItaliaNoite.jpg");
	//México dia e noite
	gRecursos.carregarTextura("mexicodia", "../assets/MexicoDia.jpg");
	gRecursos.carregarTextura("mexiconoite", "../assets/MexicoNoite.jpg");
	//China dia e noite
	gRecursos.carregarTextura("chinadia", "../assets/ChinaDia.jpg");
	gRecursos.carregarTextura("chinanoite", "../assets/ChinaNoite.jpg");
	//Brasil dia e noite
	gRecursos.carregarTextura("brasildia", "../assets/BrasilDia.jpg");
	gRecursos.carregarTextura("brasilnoite", "../assets/BrasilNoite.jpg");
	
	//Armas e items do jogador
	gRecursos.carregarSpriteSheet("capsule", "../assets/Capsule.jpg");
	gRecursos.carregarSpriteSheet("alcoolgel", "../assets/AlcoolGel.jpg");
	gRecursos.carregarSpriteSheet("vacina", "../assets/Vacina.jpg");
	gRecursos.carregarSpriteSheet("item", "../assets/item.jpg");
	gRecursos.carregarSpriteSheet("mascara", "../assets/Mascara.jpg");

	gRecursos.carregarFonte("supermario256", "../assets/SuperMario256.ttf");
	
	vitoria.setFonte("supermario256");
	vitoria.setCor(0, 0, 0);
	vitoria.setString("Level Complete!\n""Press X key to continue");
	vitoria.setEscalaX(1);
	vitoria.setEscalaY(1);
	vitoria.setAlinhamento(TEXTO_CENTRALIZADO);
	
	derrota.setFonte("supermario256");
	derrota.setCor(0, 0, 0);
	derrota.setString("Game Over!\n""Press X to return to the level select");
	derrota.setEscalaX(1);
	derrota.setEscalaY(1);
	derrota.setAlinhamento(TEXTO_CENTRALIZADO);

	levelup.setFonte("supermario256");
	levelup.setCor(0, 0, 0);
	levelup.setString("level up! chosse:\n""1=increase hp max\n""2=increase attack""\n3=increase defense\n""4=increase speed\n");
	levelup.setEscalaX(1);
	levelup.setEscalaY(1);
	levelup.setAlinhamento(TEXTO_CENTRALIZADO);

	mainmenu.carregarmenu();
	ls.carregar();

	gamescore = 0;
	
	//itemsprite.setSpriteSheet("item");
	
	spritemascara.setSpriteSheet("mascara");


	//Sol e lua
	gRecursos.carregarSpriteSheet("sun", "../assets/Sun.jpg");
	gRecursos.carregarSpriteSheet("moon", "../assets/Moon.jpg");
	ls.sol.setSpriteSheet("sun");
	ls.lua.setSpriteSheet("moon");
	srand(0);
	state = Menu;
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		//	Seu código vem aqui!
		//	...
		if (state != Menu) {
			Texto statusnivel;
			statusnivel.setFonte("supermario256");
			statusnivel.setCor(0, 0, 0);
			statusnivel.setString(" nivel:" + to_string(player.nivel));
			statusnivel.setEscalaX(1);
			statusnivel.setEscalaY(1);
			statusnivel.setAlinhamento(TEXTO_CENTRALIZADO);
			statusnivel.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() - 30);

			Texto statusvidas;
			statusvidas.setFonte("supermario256");
			statusvidas.setCor(0, 0, 0);
			statusvidas.setString("hp:" + to_string(player.hp) + "/" + to_string(player.maxhp));
			statusvidas.setEscalaX(1);
			statusvidas.setEscalaY(1);
			statusvidas.setAlinhamento(TEXTO_CENTRALIZADO);
			statusvidas.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() - 30);

			Texto statusattack;
			statusattack.setFonte("supermario256");
			statusattack.setCor(0, 0, 0);
			statusattack.setString("ataque:" + to_string(player.attack));
			statusattack.setEscalaX(1);
			statusattack.setEscalaY(1);
			statusattack.setAlinhamento(TEXTO_CENTRALIZADO);
			statusattack.desenhar(gJanela.getLargura() * 3 / 4, gJanela.getAltura() - 30);

			Texto statusdefense;
			statusattack.setFonte("supermario256");
			statusattack.setCor(0, 0, 0);
			statusattack.setString("defesa:" + to_string(player.defense));
			statusattack.setEscalaX(1);
			statusattack.setEscalaY(1);
			statusattack.setAlinhamento(TEXTO_CENTRALIZADO);
			statusattack.desenhar(gJanela.getLargura() / 3, gJanela.getAltura() - 10);

			Texto statusspeed;
			statusspeed.setFonte("supermario256");
			statusspeed.setCor(0, 0, 0);
			statusspeed.setString("velocidade:" + to_string(player.speed));
			statusspeed.setEscalaX(1);
			statusspeed.setEscalaY(1);
			statusspeed.setAlinhamento(TEXTO_CENTRALIZADO);
			statusspeed.desenhar(gJanela.getLargura() * 2 / 3, gJanela.getAltura() - 10);
		}
		if (state == Menu) {
			gJanela.setCorDeFundo(255, 255, 255);
			mainmenu.executarMenu();
			if (mainmenu.startGame()) {
				state = SelecaoFase;
			}
			else if (mainmenu.exitGame()) {
				break;
			}mainmenu.desenharMenu();
		}
		if (state == SelecaoFase) {
				if (ls.dia) {
					gJanela.setCorDeFundo(255, 255, 0);
				}
				else {
					gJanela.setCorDeFundo(0, 0, 255);
			}
			ls.executar();
			if (ls.opcao1) {
				fase.carregar(&gamescore, &player, ls.dia, ls.datadia, ls.datames, ls.dataano, 1);
				state = EmFase;
			}
			else if (ls.opcao2) {
				fase.carregar(&gamescore, &player, ls.dia, ls.datadia, ls.datames, ls.dataano, 2);
				state = EmFase;
			}else if (ls.opcao3) {
				fase.carregar(&gamescore, &player, ls.dia, ls.datadia, ls.datames, ls.dataano, 3);
				state = EmFase;
			}else if (ls.opcao4) {
				fase.carregar(&gamescore, &player, ls.dia, ls.datadia, ls.datames, ls.dataano, 4);
				state = EmFase;
			}else if (ls.opcao5) {
				fase.carregar(&gamescore, &player, ls.dia, ls.datadia, ls.datames, ls.dataano, 5);
				state = EmFase;
			}else if (ls.opcao6) {
				fase.carregar(&gamescore, &player, ls.dia, ls.datadia, ls.datames, ls.dataano, 6);
				state = EmFase;
			}else if (ls.opcao7) {
				fase.carregar(&gamescore, &player, ls.dia, ls.datadia, ls.datames, ls.dataano, 7);
				state = EmFase;
			}
			ls.desenhar();
			ls.desenharConfig();
		}
		if (state == EmFase) {
			fase.atualizar(&player);
			if (fase.finalizada(&player)) {
				if (fase.concluida(&player)) {
					state = NivelConcluido;
				}
				else {
					state = FimDeJogo;
				}
			}
		}
		if (state == NivelConcluido) {
			if (ls.dia) {
				gJanela.setCorDeFundo(255, 255, 0);
			}
			else {
					gJanela.setCorDeFundo(0, 0, 255);
			}
			vitoria.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
			Texto pontuacao;
			pontuacao.setFonte("supermario256");
			pontuacao.setCor(0, 0, 0);
			pontuacao.setString("level score:" + to_string(gamescore + fase.getScore()));
			pontuacao.setEscalaX(1);
			pontuacao.setEscalaY(1);
			pontuacao.setAlinhamento(TEXTO_CENTRALIZADO);
			pontuacao.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);
			if (gTeclado.pressionou[TECLA_X]) {	
				if((gamescore + fase.getScore()) / gamescorerestantes > 0){
					gamescore = 0;
					player.nivel++;
					state = LevelUp;
				}
				else {
					gamescore += fase.getScore();
					state = SelecaoFase;
				}
			}
		}
		if (state == FimDeJogo) {
				if (ls.dia) {
					gJanela.setCorDeFundo(255, 255, 0);
				}
				else {
					gJanela.setCorDeFundo(0, 0, 255);
			}
			derrota.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
			if (gTeclado.pressionou[TECLA_X]) {
				state = SelecaoFase;
			}
		}
		if (state == LevelUp) {
			if (ls.dia) {
				gJanela.setCorDeFundo(255, 255, 0);
			}
			else {
				gJanela.setCorDeFundo(0, 0, 255);
			}
			levelup.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
			if (gTeclado.pressionou[TECLA_1]) {
				player.maxhp += 10;
				state = SelecaoFase;
			}else if (gTeclado.pressionou[TECLA_2]) {
				player.attack++;
				state = SelecaoFase;
			}else if (gTeclado.pressionou[TECLA_3]) {
				player.defense++;
				state = SelecaoFase;
			}else if (gTeclado.pressionou[TECLA_4]) {
				player.speed++;
				state = SelecaoFase;
			}
		}
		uniTerminarFrame();
	}
}
