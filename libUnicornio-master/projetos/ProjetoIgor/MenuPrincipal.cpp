#include "MenuPrincipal.h"
#include "libUnicornio.h"
MenuPrincipal::MenuPrincipal()
{
	
}

void MenuPrincipal::carregarmenu()
{
	gRecursos.carregarSpriteSheet("startbutton", "../assets/startbutton.jpg");
	gRecursos.carregarSpriteSheet("exitbutton", "../assets/exitbutton.jpg");
	startButton.setSpriteSheet("startbutton");
	exitButton.setSpriteSheet("exitbutton");
	titulo.setFonte("supermario256");
	titulo.setCor(0, 0, 0);
	titulo.setString("Dr Mario RPG: COVID-19 Attack");
	titulo.setEscalaX(1);
	titulo.setEscalaY(1);
	startButton.getSprite()->setEscala(0.75, 0.75);
	exitButton.getSprite()->setEscala(0.5, 0.5);
	startButton.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 10);
	exitButton.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 100);
	titulo.setAlinhamento(TEXTO_CENTRALIZADO);
}

void MenuPrincipal::executarMenu() {
	start = false;
	exit = false;

	if (gTeclado.pressionou[TECLA_ENTER] || startButton.estaClicado()) {
		start = true;
	}
	else if (gTeclado.pressionou[TECLA_ESC] || exitButton.estaClicado()) {
		exit = true;
	}
}

void MenuPrincipal::desenharMenu()
{
	titulo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 100);
	startButton.desenhar();
	exitButton.desenhar();
}

bool MenuPrincipal::startGame() {
	return start;
}

bool MenuPrincipal::exitGame()
{
	return exit;
}
