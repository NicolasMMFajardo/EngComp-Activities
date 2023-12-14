#pragma once
#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>

#define TAM_NOME 5
#define ADD_PONTUACAO 2000

using namespace std;

struct TJogador {
    int pontuacao;
    string nome;
};

ostream& operator<<(std::ostream& saida, TJogador j) {
    saida << "Jogador {" << j.nome << "}, pontuação {" << j.pontuacao << "}";
    return saida;
}

bool operator==(TJogador J1, TJogador J2) {
    if (J1.nome == J2.nome && J1.pontuacao == J2.pontuacao) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<(TJogador J1, TJogador J2) {
    if (J1.pontuacao < J2.pontuacao) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>(TJogador J1, TJogador J2) {
    if (J1.pontuacao > J2.pontuacao) {
        return true;
    }
    else {
        return false;
    }
}

TJogador operator+= (TJogador J1, int num) {
    J1.pontuacao += num;
    return J1;
}

string gerar_nome() {
    string nome_gerado = "";
    char c;
    int r;

    for (int i = 0; i < TAM_NOME; i++) {
        r = rand() % 26;
        c = 'a' + r;
        nome_gerado += c;
    }

    return nome_gerado;
}

int gerar_pontuacao() {
    return (rand() % ADD_PONTUACAO);
}

void add_pontuacao(TJogador& player) {
    player.pontuacao += gerar_pontuacao();
}

#endif