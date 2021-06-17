#include "TelaPrincipal.h"

TelaPrincipal::TelaPrincipal() {
    setTipo(1);
        t.setFonte("supermario256");
        t.setCor(0, 0, 0);
        t.setString("Welcome! Choose:\n""1=New Game\n""2=Load Game\n""3=Ranking\n""4=Credits\n""5=Logout\n");
        t.setEscalaX(1);
        t.setEscalaY(1);
        t.setAlinhamento(TEXTO_CENTRALIZADO);
}



void TelaPrincipal::executar(Player *p, string nomes[5], long scorelist[5], Fila<Usuario>* uc, Usuario* atual, string files[3]){
    t.desenhar(gJanela.getLargura()/2 ,gJanela.getAltura()/ 4);
}
