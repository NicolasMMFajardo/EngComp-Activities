#ifndef LISTAEncadeadaDupla_H
#define LISTAEncadeadaDupla_H
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
struct TElementoEncadeadaDupla {
    T Dado;
    TElementoEncadeadaDupla* proximo, * anterior;
};

template <typename T>
struct TListaEncadeadaDupla {
    TElementoEncadeadaDupla<T>* inicio, * fim;
};

template <typename T>
ostream& operator<<(ostream& os, TListaEncadeadaDupla<T> lista) {
    if (lista.inicio == NULL) {
        os << "Lista vazia" << endl;
    }
    else {
        TElementoEncadeadaDupla<T>* nav = lista.inicio;
        for (int i = 0; nav != NULL; i++) {
            os << "Lista[" << i << "]: " << nav->Dado << endl;
            nav = nav->proximo;
        }
    }
    return os;
}

template <typename T>
void inicializar_lista(TListaEncadeadaDupla<T>& lista) {
    lista.inicio = NULL;
    lista.fim = NULL;
}

template <typename T>
void inserir_inicio(TListaEncadeadaDupla<T>& lista, T novoDado) {
    TElementoEncadeadaDupla<T>* novo = new TElementoEncadeadaDupla<T>;
    novo->Dado = novoDado;
    novo->proximo = lista.inicio;
    novo->anterior = NULL;

    //ponteiro head vai receber um valor
    if (lista.inicio != NULL) {
        lista.inicio->anterior = novo;
        // lista.inicio = novo;
    }
    else {
        //lista.inicio = novo;
        lista.fim = novo;
    }
    lista.inicio = novo;
}

template <typename T>
void inserir_posicao(TListaEncadeadaDupla<T>& lista, T novoDado, int posicao) {

    if (posicao < 0) {
        throw "Invalid Index < 0";
    }
    if (posicao == 0) {
        inserir_inicio(lista, novoDado);
    }
    TElementoEncadeadaDupla<T>* nav = lista.inicio;

    for (int i = 0; nav->proximo != NULL && i < posicao - 1; i++) {
        nav = nav->proximo;
    }
    if (nav != NULL) {
        TElementoEncadeadaDupla<T>* novo = new TElementoEncadeadaDupla<T>;

        novo->Dado = novoDado;
        novo->proximo = nav->proximo;
        nav->proximo->anterior = novo;
        nav->proximo = novo;
        novo->anterior = nav;
        //arrumar ordem,
        if (novo->proximo != NULL) {
            novo->proximo->anterior = novo;
        }
        else {
            throw "Index NULL";
        }
    }
    else {
        stringstream buffer;
        buffer << "problema ao inserir na posicao: ";
        buffer << posicao;
        buffer << " - posicao invalida > quantidade";
        string mensagem = buffer.str();
        throw mensagem;
    }
}

template <typename T>
void inserir_fim(TListaEncadeadaDupla<T>& lista, T novoDado) {

    if (lista.inicio == NULL) {
        inserir_inicio(lista, novoDado);
    }

    else {
        TElementoEncadeadaDupla<T>* novo = new TElementoEncadeadaDupla<T>;
        novo->Dado = novoDado;
        novo->anterior = lista.fim;
        lista.fim->proximo = novo;
        novo->proximo = NULL;
        lista.fim = novo;
    }
}

template <typename T>
T remover_inicio(TListaEncadeadaDupla<T>& lista) {
    if (lista.inicio != NULL) {
        T copiaDado = lista.inicio->Dado;
        TElementoEncadeadaDupla<T>* apagar = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        lista.inicio->anterior = NULL;
        delete apagar;
        return copiaDado;
    }
}

template <typename T>
T remover_posicao(TListaEncadeadaDupla<T>& lista, int posicao) {
    if (lista.inicio == NULL) {
        throw "List underflow";
    }

    if (posicao < 0) {
        throw "Invalid Index < 0";
    }

    if (posicao == 0) {
        remover_inicio(lista);
    }
    else {
        TListaEncadeadaDupla<T>* nav = lista.inicio;
        for (int i = 0; nav->proximo != NULL && i < posicao - 1; i++) {
            nav = nav->proximo;
        }
        if (nav != NULL) {
            TListaEncadeadaDupla<T>* apagar = nav->proximo;
            T copiaDado = apagar->Dado;
            if (apagar != NULL) {
                nav->proximo = apagar->proximo;
                nav->proximo->anterior = nav;
                delete apagar;
                return copiaDado;
            }
            else {
                throw "Invalid Index ==| size";
            }
        }
        else {
            stringstream buffer;
            buffer << "problema ao remover na posicao: ";
            buffer << posicao;
            buffer << " - posicao invalida > quantidade";
            string mensagem = buffer.str();
            throw mensagem;
        }
    }
}

template <typename T>
T remover_fim(TListaEncadeadaDupla<T>& lista) {
    if (lista.inicio != NULL) {
        if (lista.inicio == lista.fim) {
            remover_inicio(lista);
        }
        else {
            T copiaDado = lista.fim->Dado;
            TElementoEncadeadaDupla<T>* apagar = lista.fim;
            lista.fim->anterior->proximo = NULL;
            lista.fim = lista.fim->anterior;
            delete apagar;
            return copiaDado;
        }
    }
}

template <typename T>
T& obter_item(TListaEncadeadaDupla<T>& lista, int posicao) {
    if (lista.inicio == NULL) {
        throw "List underflow";
    }

    if (posicao < 0) {
        throw "Invalid Index < 0";
    }

    if (posicao == 0) {
        return lista.inicio->Dado;
    }
    else {
        TElementoEncadeadaDupla<T>* nav = lista.inicio;
        for (int i = 0; nav->proximo != NULL && i < posicao; i++) {
            nav = nav->proximo;
        }
        if (nav != NULL) {
            return nav->Dado;
        }
        else {
            stringstream buffer;
            buffer << "problema ao remover na posicao: ";
            buffer << posicao;
            buffer << " - posicao invalida > quantidade";
            string mensagem = buffer.str();
            throw mensagem;
        }
    }
}

template <typename T>
bool verificar_item_existe(TListaEncadeadaDupla<T>& lista, T novoDado) {
    for (TElementoEncadeadaDupla<T>* nav = lista.inicio; nav->proximo != NULL;
        nav = nav->proximo) {

        if (nav->Dado == novoDado) {
            return true;
        }
        return false;
    }
}

template <typename T>
int descobrir_item(TListaEncadeadaDupla<T>& lista, T novoDado) {
    if (verificar_item_existe(lista, novoDado)) {
        int i = 0;
        for (TElementoEncadeadaDupla<T>* nav = lista.inicio; nav->proximo != NULL; nav = nav->proximo) {
            if (nav->Dado == novoDado)
                return i;
            i++;
        }
    }
    else {
        return -1;
    }
}

template <typename T>
void depurar_lista(TListaEncadeadaDupla<T>& lista) {
    if (lista.inicio == NULL) {
        cout << "Lista vazia" << endl;
    }
    else {
        for (TElementoEncadeadaDupla<T>* nav = lista.inicio; nav != NULL; nav = nav->proximo) {
            cout << nav->Dado << " - " << nav << " - proximo: " << nav->proximo << endl;
        }
    }
}

template <typename T>
int tam_lista_enc_dupla(TListaEncadeadaDupla<T>& lista) {
    int tam = 0;
    for (TElementoEncadeadaDupla<T>* nav = lista.inicio; nav != NULL; nav = nav->proximo) {
        tam++;
    }
    return tam;
}

template <typename T>
void ordenar_lista(TListaEncadeadaDupla<T>& lista) {
    for (int i = 1; i < tam_lista_enc_dupla(lista); i++) {
        T valor = obter_item(lista, i);
        int j = i - 1;

        while (j >= 0 && obter_item(lista, j) > valor) {
            obter_item(lista, j + 1) = obter_item(lista, j);
            j = j - 1;
        }
        obter_item(lista, j + 1) = valor;
    }
}

#endif