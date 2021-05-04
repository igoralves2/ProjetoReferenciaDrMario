#pragma once
#include <libUnicornio.h>
class MenuPrincipal
{
public:
	MenuPrincipal();
	void carregarmenu();
	void executarMenu();
	void desenharMenu();
	bool startGame();
	bool exitGame();
protected:
	bool start = false;
	bool exit = false;
	Texto titulo;
	BotaoSprite startButton;
	BotaoSprite exitButton;
};

