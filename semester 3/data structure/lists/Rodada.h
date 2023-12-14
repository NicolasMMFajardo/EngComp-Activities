#ifndef RODADA_H
#define RODADA_H

#include "ListaEstatica.h"
#include "ListaEncadeada.h"
#include "ListaEncadeadaDupla.h"
#include "Jogador.h"

#define NUM_JOGADORES 100
#define NUM_RODADAS 10

template <typename T, int CAPACIDADE>
void preencher_lista(TListaEstatica<T, CAPACIDADE>& lista) {
    for (int i = 0; i < CAPACIDADE; i++) {
        TJogador player = { gerar_pontuacao(), gerar_nome() };
        inserir_inicio(lista, player);
    }
}

template <typename T>
void preencher_lista(TListaEncadeada<T>& lista) {
    int numJogadores;
    cout << "Entre com a quantidade de jogadores\n";
    cin >> numJogadores;
    system("clear");
    for (int i = 0; i < numJogadores; i++) {
        TJogador player = { gerar_pontuacao(), gerar_nome() };
        inserir_inicio(lista, player);
    }
}

template <typename T, int CAPACIDADE>
void atualizar_jogadores(TListaEstatica<T, CAPACIDADE>& lista) {
    for (int i = 0; i > lista.quantidade; i++) {
        add_pontuacao(lista.vetor[i].Dado);
    }
}

template <typename T>
void atualizar_jogadores(TListaEncadeada<T>& lista) {
    for (TElementoEncadeada<T>* nav = lista.inicio;
        nav != NULL; nav = nav->proximo) {
        add_pontuacao(nav->Dado);
    }
}

template <typename T>
void jogar_rodada(T& lista) {
    preencher_lista(lista);
    for (int i = 0; i < NUM_RODADAS; i++) {
        ordenar_lista(lista);
        cout << "--- RODADA " << i + 1 << " ---\n\n";
        cout << lista << endl;
        atualizar_jogadores(lista);
    }
}

template <typename T, int CAPACIDADE>
void jogar_rodada(TListaEstatica<T, CAPACIDADE>& lista) {
    preencher_lista(lista);
    for (int i = 0; i < NUM_RODADAS; i++) {
        ordenar_lista(lista);
        cout << "--- RODADA " << i + 1 << " ---\n\n";
        cout << lista << endl;
        for (int j = 0; j < lista.quantidade; j++) {
            add_pontuacao(lista.vetor[j].Dado);
        }
    }
}

#endif