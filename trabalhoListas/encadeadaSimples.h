#ifndef LISTA_ENCADEADA_SIMPLES_H_INCLUDED
#define LISTA_ENCADEADA_SIMPLES_H_INCLUDED
namespace TLDS
{
    template <typename TIPO>
    struct TElemento {
        TIPO dado;
        TElemento <TIPO>* proximo;
    };

    template <typename TIPO>
    struct TLista {
        TElemento <TIPO>* inicio;
    };


    //Inicia
    template <typename TIPO>
    void inicializar(TLista <TIPO>& p) {

        p.inicio = NULL;
    }


    //Cria elemento
    template <typename TIPO>
    TElemento <TIPO>* novo_elemento_lista(TIPO dado) {

        TElemento <TIPO>* novo = new TElemento<TIPO>;

        novo->dado = dado;
        novo->proximo = NULL;

        return novo;
    }


    //inserir
    template <typename TIPO>
    bool inserirInicio(TLista <TIPO>& lista, TIPO dado) {


        TElemento <TIPO>* novo = novo_elemento_lista(dado);

        if (lista.inicio == NULL) {
            lista.inicio = novo;
            return true;
        }
        else {

            novo->proximo = lista.inicio;
            lista.inicio = novo;
            return true;
        }
    }


    template <typename TIPO>
    bool inserePosicao(TLista <TIPO>& lista, TIPO dado, int p) {

        int qtt = contaLista(lista), i = 0;

        TElemento<TIPO>* novo = novo_elemento_lista(dado);
        TElemento<TIPO>* nav = lista.inicio;
        TElemento<TIPO>* anterior;

        if (lista.inicio == NULL || p > qtt || p < 0) {
            return false;
        }
        if (p == qtt) {
            insereFinal(lista, dado);
            return true;
        }if (p == 0) {
            inserirInicio(lista, dado);
            return true;
        }
        else {

            while (i < p) {
                anterior = nav;
                nav = nav->proximo;
                i++;
            }
            novo->proximo = anterior->proximo;
            anterior->proximo = novo;
            return true;
        }
    }


    template <typename TIPO>
    bool insereFinal(TLista <TIPO>& lista, TIPO dado) {

        TElemento<TIPO>* nav = lista.inicio;

        if (lista.inicio != NULL) {

            while (nav->proximo != NULL)
                nav = nav->proximo;


            if (nav->proximo != NULL) {
                return false;

            }
            else {
                TElemento <TIPO>* novo = novo_elemento_lista(dado);
                novo->proximo = nav->proximo;
                nav->proximo = novo;
                //     cout << "teste: "<< dado.nome<< endl;
                //     cout << "endereco: "<< nav << endl;
                //    cout << "proximo end: "<< novo << endl;
                return true;
            }

        }
        else {
            TElemento <TIPO>* novo = novo_elemento_lista(dado);
            novo->proximo = lista.inicio;
            lista.inicio = novo;
            // cout << "teste: "<< dado.nome<< endl;
            // cout << "endereco: "<< nav << endl;
            // cout << "proximo end: "<< novo << endl;
            return true;
        }


    }



    //Remover
    template <typename TIPO>
    bool removeInicio(TLista <TIPO>& lista) {

        if (lista.inicio == NULL) {
            return false;
        }
        else {
            TElemento<TIPO>* removedor = lista.inicio;
            lista.inicio = removedor->proximo;
            delete removedor;
            return true;
        }
    }


    template <typename TIPO>
    bool removePosicao(TLista <TIPO>& lista, int p) {

        int qtt = contaLista(lista), i = 0;

        TElemento<TIPO>* nav = lista.inicio;
        TElemento<TIPO>* depois;

        if (lista.inicio == NULL || p > qtt || p < 0) {
            return false;
        }
        if (p == qtt - 1) {
            removeFinal(lista);
            return true;
        }if (p == 0) {
            removeInicio(lista);
            return true;
        }
        else {

            while (i < p) {
                depois = nav;
                nav = nav->proximo;
                i++;
            }
            depois->proximo = nav->proximo;
            delete depois;
            return true;
        }
    }


    template <typename TIPO>
    bool removeFinal(TLista <TIPO>& lista) {

        TElemento<TIPO>* nav = lista.inicio;
        TElemento<TIPO>* ultimo;
        if (lista.inicio == NULL) {
            return false;
        }
        else {
            while (nav->proximo != NULL) {
                ultimo = nav;
                nav = nav->proximo;
            }
            ultimo->proximo = NULL;
            delete ultimo;
            return true;
        }
    }


    //quantidade
    template <typename TIPO>
    int contaLista(TLista <TIPO>& lista) {

        int qtt = 0;

        TElemento<TIPO>* nav = lista.inicio;

        if (lista.inicio == NULL) {
            cout << "Lista Vazia!" << endl;
        }
        else {

            while (nav != NULL) {
                nav = nav->proximo;
                qtt++;
            }
            return qtt;
        }


    }

    template<typename T>
    void imprimir(TLista<T> lista) {
        TElemento<T>* nav = new TElemento<T>;
        nav = lista.inicio;

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
}

#endif // LISTA_ENCADEADA_SIMPLES

