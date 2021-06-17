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
#include "Fila.h"
#include "Tela.h"
#include "Pilha.h"
#include "ArrayList.h"
#include "Usuario.h"
enum GameState { Menu, SelecaoFase, EmFase, FimDeJogo, NivelConcluido, JogoConcluido, LevelUp };

class Jogo
{
public:
	Jogo();
	~Jogo();
	void inicializar();
	void finalizar();
	void executar();
	Player* getPlayer();
private:
	Player player;
	Pilha<Tela*> *pilhatelas;
	MenuPrincipal mainmenu;
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
	Tela *atual;
	Texto levelup;
	LevelSelect ls;
	int lasthp;
	Tela t;
	string top5names[5] = {"Igor", "Donald", "Huguinho", "Zezinho", "Luizinho"};
	long top5scores[5] = {10, 9, 8, 7, 6};
	Fila<Usuario> *usuarioscadastrados = new Fila<Usuario>;
	Usuario usuarioatual;
	string files[3] = {"EMPTY", "EMPTY", "EMPTY"};
};

