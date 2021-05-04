#pragma once
#include "libUnicornio.h"
#include "Player.h"
#include <string>
#include "MenuPrincipal.h"
#include "Virus.h"
#include "Comprimido.h"
#include "LevelSelect.h"
#include "AlcoolGel.h"
#include "Fase.h"
enum GameState { Menu, SelecaoFase, EmFase, FimDeJogo, NivelConcluido, JogoConcluido, LevelUp };

class Jogo
{
public:
	Jogo();
	~Jogo();
	void inicializar();
	void finalizar();
	void executar();
private:
	MenuPrincipal mainmenu;
	Player player;
	long gamescore;
	long gamescorerestantes = 10000;
	Fase fase;
	Sprite itemsprite;
	Sprite spritemascara;
	GameState state;
	Texto texto;
	Virus *viruses;
	int virusderrotados = 0;
	Texto vitoria;
	Texto derrota;
	Texto levelup;
	LevelSelect ls;
	int lasthp;
};

