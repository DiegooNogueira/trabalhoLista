#include <iostream>
using namespace std;

#include "estatica.h"
#include "jogador.h"
#include "encadeadaSimples.h"
#include "encadeadaDupla.h"

int main()
{
    TLS::TListaEstatica<Jogador, 10> jogadores;
   
    TLDS::TLista<Jogador> players;
    TLDD::TLista<Jogador> playersDupla;

    Jogador c;
    c.num = 1;
    c.pontuacao = 1;
    Jogador d;
    d.num = 2;
    d.pontuacao = 2;
    Jogador a;
    a.num = 3;
    a.pontuacao = 3;

    Jogador b;
    b.num = 4;
    b.pontuacao = 4;
   
    //dinaminca simples
    TLDS::inicializar(players);
    TLDS::inserirInicio(players, a);
    TLDS::inserirInicio(players, a);
    TLDS::inserirInicio(players, a);
    TLDS::inserirInicio(players, a);
    TLDS::imprimir(players);

    //dinaminca dupla
    TLDD::inicializar(playersDupla);
    TLDD::inserirInicio(playersDupla, b);
    TLDD::inserirInicio(playersDupla, b);
    TLDD::inserirInicio(playersDupla, b);
    TLDD::inserirInicio(playersDupla, b);
    TLDD::imprimir(playersDupla);

    TLS::inicializa(jogadores);

    cria_jogador(jogadores);
    cout << jogadores;

}