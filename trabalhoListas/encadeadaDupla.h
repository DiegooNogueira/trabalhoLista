#ifndef LISTA_ENCADEADA_DUPLA_H_INCLUDED
#define LISTA_ENCADEADA_DUPLA_H_INCLUDED


namespace TLDD
{

    template<typename TIPO>
    struct TElemento {
        TIPO dado;
        TElemento <TIPO>* anterior;
        TElemento <TIPO>* proximo;
    };

    template<typename TIPO>
    struct TLista {
        TElemento <TIPO>* inicio;
        TElemento <TIPO>* fim;
    };

    template <typename TIPO>
    TElemento <TIPO>* novo_elemento_lista(TIPO dado) {
        TElemento <TIPO>* novo = new TElemento <TIPO>;
        novo->dado = dado;
        novo->anterior = NULL;
        novo->proximo = NULL;
        return novo;
    }


    //Inicializar
    template <typename TIPO>
    void inicializar(TLista <TIPO>& lista) {
        lista.fim = NULL;
        lista.inicio = NULL;
    }

    //Imprimir
    template <typename TIPO>
    void imprimir(TLista <TIPO>& lista) {
        TElemento <TIPO>* nav = lista.inicio;
        cout << "\tJOGADORES";
        cout << "\n****************************************";
        while (nav != NULL) {

            cout << "\nJOGADOR: " << nav->dado.num;
            cout << "\nPONTUACAO: " << nav->dado.pontuacao;
            cout << "\n--------------------------------------";
            nav = nav->proximo;
        }
        cout << "\n****************************************\n\n";
    }

    //Quantidade
    template <typename TIPO>
    int contaLista(TLista <TIPO>& lista) {
        int c = 0;
        TElemento <TIPO>* nav = lista.inicio;
        while (nav->proximo != NULL) {
            nav = nav->proximo;
            c++;
        }
        return c;

    }

    //Iniserir

    template <typename TIPO>
    bool inserirInicio(TLista <TIPO>& lista, TIPO dado) {

        TElemento <TIPO>* novo = novo_elemento_lista(dado);
        TElemento <TIPO>* nav = lista.inicio;
        if (lista.inicio == NULL) {
            lista.inicio = novo;
            lista.fim = novo;
            return true;
        }
        else {
            novo->proximo = nav;
            nav->anterior = novo;
            lista.inicio = novo;
            return true;
        }

    }


    template <typename TIPO>
    bool inserirPosicao(TLista <TIPO>& lista, TIPO dado, int p) {

        TElemento <TIPO>* nav = lista.inicio;
        TElemento <TIPO>* antes;
        TElemento <TIPO>* novo = novo_elemento_lista(dado);
        int c = contaLista(lista), i = 0;
        if (p == 0) {
            inserirInicio(lista, dado);
            return true;
        }
        if (p == c + 1) {
            inserirFim(lista, dado);
            return true;
        }
        if (p > 0 && p <= c) {
            while (i < p) {
                antes = nav;
                nav = nav->proximo;
                i++;
            }
            novo->proximo = nav;
            novo->anterior = antes;
            antes->proximo = novo;

            return true;
        }
        else {
            return false;
        }

    }


    template <typename TIPO>
    bool inserirFim(TLista <TIPO>& lista, TIPO dado) {
        TElemento <TIPO>* novo = novo_elemento_lista(dado);
        TElemento <TIPO>* nav = lista.inicio;
        if (lista.inicio == NULL) {
            lista.inicio = novo;
            lista.fim = novo;
            return true;
        }
        else {
            while (nav->proximo != NULL) {
                nav = nav->proximo;
            }
            nav->proximo = novo;
            lista.fim = novo;
            return true;
        }
    }

    //Remover

    template <typename TIPO>
    bool removerInicio(TLista <TIPO>& lista) {

        TElemento <TIPO>* nav = lista.inicio;
        if (lista.inicio == NULL) {
            return false;
        }
        else {
            lista.inicio = nav->proximo;
            nav->proximo->anterior = NULL;
            delete(nav);
            return true;
        }

    }

    template <typename TIPO>
    bool removerPosicao(TLista <TIPO>& lista, int p) {

        TElemento <TIPO>* nav = lista.inicio;
        TElemento <TIPO>* antes;
        TElemento <TIPO>* depois;
        int c = contaLista(lista), i = 0;
        if (p == 0) {
            removerInicio(lista);
            return true;
        }
        if (p == c) {
            removerFim(lista);
            return true;
        }
        if (p > 0 && p < c) {
            while (i < p) {
                antes = nav;
                nav = nav->proximo;
                depois = nav->proximo;
                i++;
            }
            antes->proximo = depois;
            depois->anterior = antes;
            delete(nav);
            return true;
        }
        else {
            return false;
        }
    }

    template <typename TIPO>
    bool removerFim(TLista <TIPO>& lista) {

        TElemento <TIPO>* nav = lista.inicio;
        TElemento <TIPO>* novoultimo = lista.inicio;
        if (lista.fim == NULL) {
            return false;
        }
        else {
            while (nav->proximo != NULL) {
                novoultimo = nav;
                nav = nav->proximo;
            }
            lista.fim = novoultimo;
            novoultimo->proximo = NULL;
            delete(nav);
            return true;
        }

    }

}
#endif // LISTA_ENCADEADA_DUPLA_H_INCLUDED
