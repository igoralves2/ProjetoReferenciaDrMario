
#include "TelaCadastroUsuario.h"

TelaCadastroUsuario::TelaCadastroUsuario()
{
    setTipo(2);
    t.setFonte("supermario256");
    t.setCor(0, 0, 0);
    t.setString("Register your name and password:\n");
    t.setEscalaX(1);
    t.setEscalaY(1);
    t.setAlinhamento(TEXTO_CENTRALIZADO);
    textoatual = 0;
    username.inicializar();
}

void TelaCadastroUsuario::executar(Player* p, string nomes[5], long scorelist[5], Fila<Usuario> *uc, Usuario* atual, string files[3])
{
    if (saiu) {
        textoatual = 0;
        username.inicializar();
        saiu = false;
    }
    else {
        t.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);
        if (textoatual == 0) {
            username.atualizar();
            Texto t2;
            t2.setFonte("supermario256");
            t2.setCor(0, 0, 0);
            t2.setString("Usuario:");
            t2.setEscalaX(1);
            t2.setEscalaY(1);
            t2.setAlinhamento(TEXTO_CENTRALIZADO);
            t2.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 2);
            username.desenhar(gJanela.getLargura() * 3 / 4, gJanela.getAltura() / 2);
            if (gTeclado.pressionou[TECLA_ENTER]) {
                textoatual++;
                nameuseratual = username.getString();
                username.finalizar();
                userPassword.inicializar();
            }
        }
        else if (textoatual == 1) {

            userPassword.atualizar();
            Texto t3;
            t3.setFonte("supermario256");
            t3.setCor(0, 0, 0);
            t3.setString("Senha");
            t3.setEscalaX(1);
            t3.setEscalaY(1);
            t3.setAlinhamento(TEXTO_CENTRALIZADO);
            t3.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 2 + 20);
            userPassword.desenhar(gJanela.getLargura() * 3 / 4, gJanela.getAltura() / 2 + 20);
            if (gTeclado.pressionou[TECLA_ENTER]) {
                passworduseratual = userPassword.getString();
                if (uc->quantidadeElementos() > 0) {
                    bool achounalista = false;
                    int i = 0;
                    int n = (*uc).quantidadeElementos();
                    Usuario u = uc->primeiroDaFila();
                    for (i; i < n; i++) {
                        u = uc->primeiroDaFila();
                        uc->desenfileirar();
                        uc->enfileirar(u);
                        if (u.getName() == nameuseratual) {
                            achounalista = true;
                            break;
                        }
                    }
                    if (achounalista) {
                        if (u.getPassword() == passworduseratual) {
                            *atual = u;
                           //uc->enfileirar(*atual);
                            userPassword.finalizar();
                            textoatual++;
                        }
                        else {
                            textoatual = 0;
                            userPassword.finalizar();
                            username.inicializar();
                        }
                    }
                    else {
                        *atual = Usuario(nameuseratual, passworduseratual);
                        uc->enfileirar(*atual);
                        userPassword.finalizar();
                        textoatual++;
                    }
                }
                else {
                    *atual = Usuario(nameuseratual, passworduseratual);
                    uc->enfileirar(*atual);
                    userPassword.finalizar();
                    textoatual++;
                }
            }
        }
        else if (textoatual == 2) {
            Texto result;
            result.setFonte("supermario256");
            result.setCor(0, 0, 0);
            result.setString("Registrado com sucesso! pressione ENTER para continuar");
            result.setEscalaX(1);
            result.setEscalaY(1);
            result.setAlinhamento(TEXTO_CENTRALIZADO);
            result.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 30);
            if (gTeclado.pressionou[TECLA_ENTER]) {
                saiu = true;
            }
        }
    }
}
