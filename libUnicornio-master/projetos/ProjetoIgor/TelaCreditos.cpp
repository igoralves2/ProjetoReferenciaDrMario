#include "TelaCreditos.h"

TelaCreditos::TelaCreditos()
{
    setTipo(4);
    t.setFonte("supermario256");
    t.setCor(0, 0, 0);
    t.setString("Creditos:\n""Dr Mario: COVID Attack\n""Desenvolvido por Igor Alves\n""Agradecimentos a Nintendo e aos profissionais de saude\n");
    t.setEscalaX(1);
    t.setEscalaY(1);
    t.setAlinhamento(TEXTO_CENTRALIZADO);
}

void TelaCreditos::executar(Player *p, string nomes[5], long scorelist[5], Fila<Usuario> *uc, Usuario* atual, string files[3])
{
    t.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);
}
