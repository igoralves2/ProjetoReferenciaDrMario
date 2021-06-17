#include "Usuario.h"

Usuario::Usuario()
{
    score = 0;
    name = "";
    password = "";
}

Usuario::Usuario(string novousuario, string novasenha)
{
    this->name = novousuario;
    this->password = novasenha;
    score = 0;
    //p = pnovo;

}

Usuario::~Usuario()
{
}
/*
Player Usuario::getPlayer()
{
    return *p;
}*/

string Usuario::getName()
{
    return name;
}

string Usuario::getPassword()
{
    return password;
}

long Usuario::getScore()
{
    return score;
}

void Usuario::setScore(long s)
{
    this->score = s;
}
/*
void Usuario::setPlayer(Player pnovo)
{
    this->p = &pnovo;
}*/
