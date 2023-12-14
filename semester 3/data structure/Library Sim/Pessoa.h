#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

using namespace std;

struct Pessoa {
    string nome;
    int codigo;
};

ostream& operator<<(std::ostream& saida, Pessoa p) {
    saida << "Pessoa {" << p.nome << "}, Código {" << p.codigo << "}";
    return saida;
}

string gerarNome() {
    string nome_gerado = "";
    char c;
    int r;
    for (int i = 0; i < 5; i++) {
        r = rand() % 26;
        c = 'a' + r;
        nome_gerado += c;
    }
    return nome_gerado;
}

Pessoa gerarPessoa() {
    Pessoa p = { gerarNome(), rand() % 10000 };
    return p;
}

#endif