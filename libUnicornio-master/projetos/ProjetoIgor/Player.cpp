#include "Player.h"



Player::Player()
{
	ag = AlcoolGel();
	c = Comprimido();
	v = Vacina();
	nivel = 1;
	hp = 100;
	maxhp = 100;
	attack = 1;
	defense = 1;
	speed = 1;
}



Player::~Player()
{
}

void Player::atualizar()
{
	atirandocomprimido = false;
	atirandoalcoolgel = false;
	usandovacina = false;
	if (gTeclado.segurando[TECLA_ESQ]) {
		currentdir = left;
		if (x - speed > 0) {
			x -= speed;
		}
	}else if (gTeclado.segurando[TECLA_DIR]) {
		currentdir = right;
		if (x + speed < gJanela.getLargura()) {
			x += speed;
		}
	}
	else if (gTeclado.segurando[TECLA_CIMA]) {
		currentdir = up;
		if (y - speed > 0) {
			y -= speed;
		}
	}
	else if (gTeclado.segurando[TECLA_BAIXO]) {
		currentdir = down;
		if (y + speed < gJanela.getAltura()) {
			y += speed;
		}
	}
	if (gTeclado.pressionou[TECLA_X]) {
		atirandocomprimido = true;
	}if (gTeclado.pressionou[TECLA_Z]) {
		atirandoalcoolgel = true;
	}if (gTeclado.pressionou[TECLA_C]) {
		usandovacina = true;
	}
}

float Player::eficienciamascara()
{
	if (m.getTipo() == 1) {
		return 0.5f;
	}
	else if (m.getTipo() == 2) {
			return 0.25f;
	}
	return 1.0f;
}
