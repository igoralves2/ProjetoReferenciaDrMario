#include "Tela.h"

Tela::Tela()
{
	saiu = false;
}

Tela::~Tela()
{
}

void Tela::executar(Player* p, string nomes[5], long scorelist[5], Fila<Usuario>* uc, Usuario* atual, string files[3])
{
	t.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);
}



int Tela::getTipo()
{
	return tipo;
}

void Tela::setTipo(int nro)
{
	this->tipo = nro;
}

bool Tela::isQuit()
{
	return saiu;
}

void Tela::troca()
{
	saiu = !saiu;
}

void Tela::setIndexAtual(int novoi)
{
	this->indexfaseatual = novoi;
}

int Tela::getNivelAtual()
{
	return indexfaseatual;
}

