#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>

using namespace std;
namespace TLS
{
    // 3. Estrutura base da TAD de ranking
    template <typename T, int CAPACIDADE>
    struct TListaEstatica {
        T vetor[CAPACIDADE];
        int quantidade;
    };

    //IMPRIMIR
    template <typename T, int CAPACIDADE>
    ostream& operator<<(ostream& os, TListaEstatica<T, CAPACIDADE> lista) {
        if (lista.quantidade == 0) {
            os << "Lista Vazia" << endl;
        }
        else {
            for (int i = 0; i < lista.quantidade; i++) {
                os << " [" << i << "] " << lista.vetor[i];
            }
        }
        return os;
    }


    //INICIALIZAR
    template <typename T, int CAPACIDADE>
    void inicializa(TListaEstatica<T, CAPACIDADE>& lista) {
        lista.quantidade = 0;
    }



    //INSERIR
    template <typename T, int CAPACIDADE>
    void insere_inicio(TListaEstatica<T, CAPACIDADE>& lista, T dado) {
        if (lista.quantidade >= CAPACIDADE) {
            throw "Lista Cheia";
        }
        for (int i = lista.quantidade; 0 < i; i--) {
            lista.vetor[i] = lista.vetor[i - 1];
        }
        lista.vetor[0] = dado;
        lista.quantidade++;

    }


    template <typename T, int CAPACIDADE>
    void insere_posicao(TListaEstatica<T, CAPACIDADE>& lista, T dado, int posicao) {
        if (lista.quantidade >= CAPACIDADE) {
            throw "Lista Cheia";
        }
        for (int i = lista.quantidade; posicao < i; i--) {
            lista.vetor[i] = lista.vetor[i - 1];
        }
        lista.vetor[posicao] = dado;
        lista.quantidade++;
    }


    template <typename T, int CAPACIDADE>
    void insere_final(TListaEstatica<T, CAPACIDADE>& lista, T dado) {
        if (lista.quantidade >= CAPACIDADE) {
            throw "Lista Cheia";
        }
        lista.vetor[lista.quantidade] = dado;
        lista.quantidade++;
    }



    //REMOVER

    template <typename T, int CAPACIDADE>
    void remove_final(TListaEstatica<T, CAPACIDADE> lista) {
        lista.quantidade--;
    }


    template<typename T, int CAPACIDADE>
    void remove_inicio(TListaEstatica<T, CAPACIDADE>& lista) {
        if (lista.quantidade == 0) {
            throw "lista vazio!";
        };
        for (int i = 0; i < lista.quantidade; i++) {
            lista.vetor[i] = lista.vetor[i + 1];
        }
        lista.quantidade--;
    }


    template<typename T, int CAPACIDADE>
    void remove_posicao(TListaEstatica<T, CAPACIDADE>& lista, int index) {
        if (lista.quantidade == 0) {
            throw "lista vazio!";
        };
        for (int i = index; i < lista.quantidade; i++) {
            lista.vetor[i] = lista.vetor[i + 1];
        }
        lista.quantidade--;
    }



    //OBTER

    template<typename T, int CAPACIDADE>
    T& obter_item_lista(TListaEstatica<T, CAPACIDADE> lista, int posicao) {
        if (lista.quantidade == 0) {
            throw "lista Vazia!";
        }
        else if (lista.quantidade < posicao) {
            throw "Não há este index na lista!";
        }

        return lista.vetor[posicao];
    }



    //Contem não ta funcionando problema na linha 136 - em relação a sobrecarga do binário "=="


    template <typename T, int CAPACIDADE>
    bool contem_lista(TListaEstatica<T, CAPACIDADE> lista, T dado) {
        if (lista.quantidade == 0) {
            throw "lista Vazia!";
        }
        for (int i = 0; i < lista.quantidade; i++) {
            if (lista.vetor[i] == dado) {
                return true;
            }
        }
        return false;
    }
}

#endif

