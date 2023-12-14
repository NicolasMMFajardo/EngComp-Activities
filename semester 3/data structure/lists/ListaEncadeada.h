#ifndef LISTAEncadeada_H
#define LISTAEncadeada_H
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
struct TElementoEncadeada {
    T Dado;
    TElementoEncadeada* proximo;
};

template <typename T>
struct TListaEncadeada {
    TElementoEncadeada<T>* inicio;
};

template <typename T>
ostream& operator<<(ostream& os, TListaEncadeada<T> lista) {
    if (lista.inicio == NULL) {
        os << "Lista vazia" << endl;
    }
    else {
        TElementoEncadeada<T>* nav = lista.inicio;
        for (int i = 0; nav != NULL; i++) {
            os << "Lista[" << i << "]: " << nav->Dado << endl;
            nav = nav->proximo;
        }
    }
    return os;
}

template <typename T>
void inicializar_lista(TListaEncadeada<T>& lista) {
    lista.inicio = NULL;
}

template <typename T>
void inserir_inicio(TListaEncadeada<T>& lista, T novoDado) {
    TElementoEncadeada<T>* novo = new TElementoEncadeada<T>;
    novo->Dado = novoDado;
    novo->proximo = lista.inicio;
    lista.inicio = novo;
}

template <typename T>
void inserir_posicao(TListaEncadeada<T>& lista, T novoDado, int posicao) {
    if (posicao < 0) {
        throw "Invalid Index < 0";
    }

    if (posicao == 0) {
        inserir_inicio(lista, novoDado);
    }
    else {
        TElementoEncadeada<T>* nav = lista.inicio;
        for (int i = 0; nav->proximo != NULL && i < posicao - 1; i++) {
            nav = nav->proximo;
        }
        if (nav != NULL) {
            TElementoEncadeada<T>* novo = new TElementoEncadeada<T>;
            novo->Dado = novoDado;
            if (nav->proximo != NULL) {
                novo->proximo = nav->proximo;
                nav->proximo = novo;
            }
            else {
                inserir_fim(lista, novoDado);
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
}

template <typename T>
void inserir_fim(TListaEncadeada<T>& lista, T novoDado) {
    if (lista.inicio == NULL) {
        inserir_inicio(lista, novoDado);
    }
    else {
        TElementoEncadeada<T>* novo = new TElementoEncadeada<T>;
        novo->Dado = novoDado;
        TElementoEncadeada<T>* nav = lista.inicio;
        while (nav->proximo != NULL) {
            nav = nav->proximo;
        }
        nav->proximo = novo;
        novo->proximo = NULL;
    }
}

template <typename T>
T remover_inicio(TListaEncadeada<T>& lista) {
    if (lista.inicio != NULL) {
        T copiaDado = lista.inicio->Dado;
        TElementoEncadeada<T>* apagar = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete apagar;
        return copiaDado;
    }
}

template <typename T>
T remover_posicao(TListaEncadeada<T>& lista, int posicao) {
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
        TElementoEncadeada<T>* nav = lista.inicio;
        for (int i = 0; nav->proximo != NULL && i < posicao - 1; i++) {
            nav = nav->proximo;
        }
        if (nav != NULL) {
            TElementoEncadeada<T>* apagar = nav->proximo;
            T copiaDado = apagar->Dado;
            if (apagar != NULL) {
                nav->proximo = apagar->proximo;
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
T remover_fim(TListaEncadeada<T>& lista) {
    if (lista.inicio != NULL) {
        if (lista.inicio->proximo == NULL) {
            remover_inicio(lista);
        }
        else {
            TElementoEncadeada<T>* nav = lista.inicio;
            while (nav->proximo->proximo != NULL) {
                nav = nav->proximo;
            }
            T copiaDado = nav->Dado;
            TElementoEncadeada<T>* apagar = nav->proximo;
            nav->proximo = NULL;
            delete apagar;
            return copiaDado;
        }
    }
}

template <typename T>
T& obter_item(TListaEncadeada<T>& lista, int posicao) {
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
        TElementoEncadeada<T>* nav = lista.inicio;
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
bool verificar_item_existe(TListaEncadeada<T>& lista, T novoDado) {
    for (TElementoEncadeada<T>* nav = lista.inicio; nav->proximo != NULL; nav = nav->proximo) {
        if (nav->Dado == novoDado)
            return true;
    }
    return false;
}

template <typename T>
int descobrir_item(TListaEncadeada<T>& lista, T novoDado) {
    if (verificar_item_existe(lista, novoDado)) {
        int i = 0;
        for (TElementoEncadeada<T>* nav = lista.inicio; nav->proximo != NULL; nav = nav->proximo) {
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
void depurar_lista(TListaEncadeada<T>& lista) {
    if (lista.inicio == NULL) {
        cout << "Lista vazia" << endl;
    }
    else {
        for (TElementoEncadeada<T>* nav = lista.inicio; nav != NULL; nav = nav->proximo) {
            cout << nav->Dado << " - " << nav << " - proximo: " << nav->proximo << endl;
        }
    }
}

template <typename T>
int tam_lista_enc(TListaEncadeada<T>& lista) {
    int tam = 0;
    for (TElementoEncadeada<T>* nav = lista.inicio; nav != NULL; nav = nav->proximo) {
        tam++;
    }
    return tam;
}

template <typename T>
void ordenar_lista(TListaEncadeada<T>& lista) {
    for (int i = 1; i < tam_lista_enc(lista); i++) {
        T valor = obter_item(lista, i);
        int j = i - 1;

        while (j >= 0 && obter_item(lista, j) < valor) {
            obter_item(lista, j + 1) = obter_item(lista, j);
            j = j - 1;
        }
        obter_item(lista, j + 1) = valor;
    }
}

#endif