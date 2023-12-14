#ifndef FILA_H
#define FILA_H
#include <iostream>

using namespace std;

template <typename T>
struct container {
    T Dado;
    container<T>* prox;
};

template <typename T>
struct Fila {
    container<T>* inicio;
    container<T>* fim;
};

template <typename T>
ostream& operator<<(ostream& os, Fila<T> f) {
    if (f.inicio == NULL) {
        os << "Fila vazia" << endl;
    }
    else {
        container<T>* nav = f.inicio;
        for (int i = 0; nav != NULL; i++) {
            os << "Fila[" << i << "]: " << nav->Dado << endl;
            nav = nav->prox;
        }
    }
    return os;
}

template <typename T>
void inicializarFila(Fila<T>& f) {
    f.inicio = NULL;
    f.fim = NULL;
}

template <typename T>
void queue(Fila<T>& f, T novoDado) {
    container<T>* novo = new container<T>;
    novo->Dado = novoDado;
    if (f.inicio == NULL) {
        novo->prox = f.inicio;
        f.inicio = novo;
    }
    else {
        f.fim->prox = novo;
        novo->prox = NULL;
    }
    f.fim = novo;
};

template <typename T>
T dequeue(Fila<T>& f) {
    if (f.inicio != NULL) {
        T copiaDado = f.inicio->Dado;
        container<T>* apagar = f.inicio;
        if (f.inicio == f.fim) {
            f.fim = NULL;
        }
        f.inicio = f.inicio->prox;
        delete apagar;
        return copiaDado;
    }
}

template <typename T>
float tamFila(Fila<T>& f) {
    float tam = 0;
    for (container<T>* nav = f.inicio; nav != NULL; nav = nav->prox) {
        tam++;
    }
    return tam;
}

#endif