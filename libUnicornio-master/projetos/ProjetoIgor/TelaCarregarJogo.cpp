#include "TelaCarregarJogo.h"

TelaCarregarJogo::TelaCarregarJogo()
{
    setTipo(5);
    /*
    t.setFonte("supermario256");
    t.setCor(0, 0, 0);
    string s = "File select:\n";
    for (int i = 0; i < 3; i++) {
        s += to_string(i + 1) + ": " + files[i] + "\n";
    }
    t.setString(s);
    t.setEscalaX(1);
    t.setEscalaY(1);
    t.setAlinhamento(TEXTO_CENTRALIZADO);*/
}

void TelaCarregarJogo::executar(Player *p, string nomes[5], long scorelist[5], Fila<Usuario> *uc, Usuario* atual, string files[3])
{
    if (saiu) {
        saiu = false;
    }
    t.setFonte("supermario256");
    t.setCor(0, 0, 0);
    string s = "File select. Press R to exit.\n";
    for (int i = 0; i < 3; i++) {
        s += to_string(i + 1) + ": " + files[i] + "\n";
    }
    t.setString(s);
    t.setEscalaX(1);
    t.setEscalaY(1);
    t.setAlinhamento(TEXTO_CENTRALIZADO);
	t.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);
    if (gTeclado.pressionou[TECLA_1]) {
        if (files[0] != "EMPTY") {
            ifstream f1;
            f1.open("../" + files[0] + ".txt");
            if (f1.is_open()) {
                string novonome;
                string novodia;
                string novomes;
                string novoano;
                //string novotime;
                long novoscore;
                int novonivelcena;
                int novonivelstatus;
                int novohp;
                int novomaxhp;
                int novoatk;
                int novodef;
                int novospd;
                f1 >> novodia;
                f1 >> novomes;
                f1 >> novoano;
                //f1 >> novotime;
                f1 >> novonome;
                f1 >> novoscore;
                f1 >> novonivelcena;
                f1 >> novonivelstatus;
                f1 >> novohp;
                f1 >> novomaxhp;
                f1 >> novoatk;
                f1 >> novodef;
                f1 >> novospd;
                atual->setScore(novoscore);
                p->nivel = novonivelstatus;
                p->maxhp = novomaxhp;
                p->hp = novohp;
                p->attack = novoatk;
                p->defense = novodef;
                p->speed = novospd;
                indexfaseatual = novonivelcena;
                f1.close();
                saiu = true;
            }
            else {

            }
        }
    }
    else if (gTeclado.pressionou[TECLA_2]) {
            if (files[1] != "EMPTY") {
                ifstream f1;
                f1.open("../" + files[1] + ".txt");
                if (f1.is_open()) {
                    string novonome;
                    string novodia;
                    string novomes;
                   string novoano;
                    //string novotime;
                    long novoscore;
                    int novonivelcena;
                    int novonivelstatus;
                    int novohp;
                    int novomaxhp;
                    int novoatk;
                    int novodef;
                    int novospd;
                    f1 >> novodia;
                    f1 >> novomes;
                    f1 >> novoano;
                    //f1 >> novotime;
                    f1 >> novonome;
                    f1 >> novoscore;
                    f1 >> novonivelcena;
                    f1 >> novonivelstatus;
                    f1 >> novohp;
                    f1 >> novomaxhp;
                    f1 >> novoatk;
                    f1 >> novodef;
                    f1 >> novospd;
                    atual->setScore(novoscore);
                    p->nivel = novonivelstatus;
                    p->maxhp = novomaxhp;
                    p->hp = novohp;
                    p->attack = novoatk;
                    p->defense = novodef;
                    p->speed = novospd;
                    indexfaseatual = novonivelcena;
                    f1.close();
                    saiu = true;
                }
                else {

                }
        }
    }
    else if (gTeclado.pressionou[TECLA_3]) {
            if (files[2] != "EMPTY") {
                ifstream f1;
                f1.open("../" + files[2] + ".txt");
                if (f1.is_open()) {
                    string novonome;
                    string novodia;
                    string novomes;
                    string novoano;
                    string novotime;
                    long novoscore;
                    int novonivelcena;
                    int novonivelstatus;
                    int novohp;
                    int novomaxhp;
                    int novoatk;
                    int novodef;
                    int novospd;
                    f1 >> novodia;
                    f1 >> novomes;
                    f1 >> novoano;
                    //f1 >> novotime;
                    f1 >> novonome;
                    f1 >> novoscore;
                    f1 >> novonivelcena;
                    f1 >> novonivelstatus;
                    f1 >> novohp;
                    f1 >> novomaxhp;
                    f1 >> novoatk;
                    f1 >> novodef;
                    f1 >> novospd;
                    atual->setScore(novoscore);
                    p->nivel = novonivelstatus;
                    p->maxhp = novomaxhp;
                    p->hp = novohp;
                    p->attack = novoatk;
                    p->defense = novodef;
                    p->speed = novospd;
                    indexfaseatual = novonivelcena;
                    f1.close();
                    saiu = true;
                }
                else {

                }
            }
        }
}
