#include "Player.h"



Player::Player()
{
	//sprite.setSpriteSheet("drmario");
}



Player::~Player()
{
}

void Player::atualizar(int xmax, int ymax)
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
		if (x + speed < xmax) {
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
		if (y + speed < ymax) {
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
		return 0.50f;
	}
	else if (m.getTipo() == 2) {
			return 0.25f;
	}
	return 1.0f;
}
