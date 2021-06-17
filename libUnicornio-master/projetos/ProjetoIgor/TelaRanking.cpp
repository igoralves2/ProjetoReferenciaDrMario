#include "TelaRanking.h"

TelaRanking::TelaRanking()
{
    setTipo(3);
    t.setFonte("supermario256");
    t.setCor(0, 0, 0);
    t.setString("Top 5:\n");
    t.setEscalaX(1);
    t.setEscalaY(1);
    t.setAlinhamento(TEXTO_CENTRALIZADO);
}

void TelaRanking::executar(Player *p, string nomes[5], long scorelist[5], Fila<Usuario>* uc, Usuario* atual, string files[3])
{
    t.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);
    string s = "";
    for (int i = 0; i < 5; i++) {
        s += to_string(i + 1) + ": " + nomes[i] + " com " + to_string(scorelist[i]) + " pontos\n";
    }
    Texto top5;
    top5.setFonte("supermario256");
    top5.setCor(0, 0, 0);
    top5.setString(s);
    top5.setEscalaX(1);
    top5.setEscalaY(1);
    top5.setAlinhamento(TEXTO_CENTRALIZADO);
    top5.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4 + 50);
}
