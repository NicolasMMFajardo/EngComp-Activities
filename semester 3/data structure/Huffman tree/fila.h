#ifndef FILA_H
#define FILA_H

#include "no.h"
#include <sstream>

struct TElementoF {
    No dado;
    TElementoF* proximo;
};

struct TFila {
    TElementoF* primeiro;
    TElementoF* ultimo;
};

ostream& operator<<(ostream& os, TFila& f) {
    if (f.primeiro == NULL) {
        os << "fila vazia" << endl;
    }
    else {
        TElementoF* nav = f.primeiro;
        for (int i = 0; nav != NULL; i++) {
            os << "fila[" << i << "]: " << nav->dado << endl;
            nav = nav->proximo;
        }
    }
    return os;
}

void ordenarFila(TFila& f);

void inicializarFila(TFila& f) { f.primeiro = NULL; }

void queue(TFila& f, No novoDado) {
    TElementoF* novo = new TElementoF;
    novo->dado = novoDado;
    novo->proximo = NULL;

    if (f.primeiro == NULL) {
        f.primeiro = f.ultimo = novo;
    }
    else {
        f.ultimo->proximo = novo;
        f.ultimo = novo;
    }
    ordenarFila(f);
}

No deQueue(TFila& f) {
    if (f.primeiro != NULL) {
        No copiaDado = f.primeiro->dado;
        TElementoF* apagar = f.primeiro;
        if (f.primeiro == f.ultimo) {
            f.ultimo = NULL;
        }
        f.primeiro = f.primeiro->proximo;
        delete apagar;
        return copiaDado;
    }
    throw "Empty Queue";
}

int tamFila(TFila& f) {
    int tam = 0;
    for (TElementoF* nav = f.primeiro; nav != NULL; nav = nav->proximo) {
        tam++;
    }
    return tam;
}

No& obterItem(TFila& f, int posicao) {
    if (f.primeiro == NULL)
        throw "Queue underflow";

    if (posicao < 0)
        throw "Invalid Index < 0";

    if (posicao == 0) {
        return f.primeiro->dado;
    }
    else {
        TElementoF* nav = f.primeiro;
        for (int i = 0; nav->proximo != NULL && i < posicao; i++) {
            nav = nav->proximo;
        }
        if (nav != NULL) {
            return nav->dado;
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

void ordenarFila(TFila& f) {
    for (int i = 1; i < tamFila(f); i++) {
        No valor = obterItem(f, i);
        int j = i - 1;

        while (j >= 0 && obterItem(f, j) > valor) {
            obterItem(f, j + 1) = obterItem(f, j);
            j--;
        }
        obterItem(f, j + 1) = valor;
    }
}

#endif
