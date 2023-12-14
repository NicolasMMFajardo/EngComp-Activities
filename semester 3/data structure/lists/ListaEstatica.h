#ifndef LISTAEstatica_H
#define LISTAEstatica_H
#include <iostream>

using namespace std;

template <typename T>
struct TEelemento {
    T Dado;
};

template <typename T, int CAPACIDADE>
struct TListaEstatica {
    TEelemento<T> vetor[CAPACIDADE];
    int quantidade;
};

template <typename T, int CAPACIDADE>
ostream& operator<<(ostream& os, TListaEstatica<T, CAPACIDADE> lista) {
    if (lista.quantidade == 0) {
        os << "Lista vazia" << endl;
    }
    else {
        for (int i = 0; i < lista.quantidade; i++) {
            os << "Lista[" << i << "]: " << lista.vetor[i].Dado << endl;
        }
    }
    return os;
}

template <typename T, int CAPACIDADE>
void inicializar_lista(TListaEstatica<T, CAPACIDADE>& lista) {
    lista.quantidade = 0;
}

template <typename T, int CAPACIDADE>
void inserir_inicio(TListaEstatica<T, CAPACIDADE>& lista, T dado) {

    if (lista.quantidade >= CAPACIDADE) {
        throw "Lista cheia!";
    }

    for (int i = lista.quantidade; i > 0; i--) {
        lista.vetor[i].Dado = lista.vetor[i - 1].Dado;
    }
    lista.quantidade++;
}

template <typename T, int CAPACIDADE>
void inserir_posicao(TListaEstatica<T, CAPACIDADE>& lista, int posicao, T novo_dado) {

    if (lista.quantidade == CAPACIDADE) {
        throw "List overflow";
    }
    else {
        for (int i = lista.quantidade; i >= posicao; i--) {
            lista.vetor[i + 1].Dado = lista.vetor[i].Dado;
        }
    }
    lista.vetor[posicao].Dado = novo_dado;
    lista.quantidade++;
}

template <typename T, int CAPACIDADE>
void inserir_fim(TListaEstatica<T, CAPACIDADE>& lista, T dado) {

    if (lista.quantidade < 0) {
        throw "List underflow";
    }
    lista.quantidade++;
}

template <typename T, int CAPACIDADE>
void remover_inicio(TListaEstatica<T, CAPACIDADE>& lista) {

    if (lista.quantidade == 0) {
        throw "List underflow";
    }

    for (int i = 0; i < lista.quantidade - 1; i++) {
        lista.vetor[i].Dado = lista.vetor[i + 1].Dado;
    }

    lista.vetor[lista.quantidade - 1].Dado = lista.vetor[0].Dado;
    lista.quantidade--;
}

template <typename T, int CAPACIDADE>
void remover_posicao(TListaEstatica<T, CAPACIDADE>& lista, int posicao) {

    if (lista.quantidade < 0) {
        throw "List underflow";
    }
    for (int i = posicao; (i < lista.quantidade - 1); i++) {
        lista.vetor[i].Dado = lista.vetor[i + 1].Dado;
    }
    lista.quantidade--;
}

template <typename T, int CAPACIDADE>
void remover_fim(TListaEstatica<T, CAPACIDADE>& lista) {

    if (lista.quantidade > 0) {
        lista.quantidade--;
    }
    else {
        throw "list underlfow";
    }
}

template <typename T, int CAPACIDADE>
T& obter_item(TListaEstatica<T, CAPACIDADE>& lista, int posicao) {

    if (posicao < 0 || posicao >= lista.quantidade) {
        throw "Invalid index";
    }
    else {
        return lista.vetor[posicao].Dado;
    }
}

template <typename T, int CAPACIDADE>
int descobrir_indice(TListaEstatica<T, CAPACIDADE>& lista, T novo_dado) {

    if (lista.quantidade < 0) {
        throw "List underflow";
    }
    for (int i = 0; i < lista.quantidade; i++) {
        if (lista.vetor[i].Dado == novo_dado) {
            return i;
        }
    }
    return -1;
}

template <typename T, int CAPACIDADE>
bool contem_item(TListaEstatica<T, CAPACIDADE>& lista, T novo_dado) {

    if (lista.quantidade < 0) {
        throw "List underflow";
    }
    for (int i = 0; i < lista.quantidade; i++) {
        if (lista.vetor[i].Dado == novo_dado) {
            return true;
        }
        else {
            return false;
        }
    }
}

template <typename T, int CAPACIDADE>
void imprimir_lista(TListaEstatica<T, CAPACIDADE> lista) {
    if (lista.quantidade == 0) {
        cout << "Lista vazia" << endl;
    }
    else {
        for (int i = 0; i < lista.quantidade; i++) {
            cout << "Lista[" << i << "]: " << lista.vetor[i].Dado << endl;
        }
    }
}

template <typename T, int CAPACIDADE>
void ordenar_lista(TListaEstatica<T, CAPACIDADE>& lista) {
    int i, j;
    for (i = 0; i < lista.quantidade - 1; i++)
        for (j = 0; j < lista.quantidade - i - 1; j++)
            if (lista.vetor[j].Dado < lista.vetor[j + 1].Dado)
                swap(lista.vetor[j].Dado, lista.vetor[j + 1].Dado);
}

#endif