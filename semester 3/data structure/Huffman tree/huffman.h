#ifndef HUFFMAN_H
#define HUFFMAN_H

//#include "hash.h"
#include "fila.h"
#include <unordered_map>

struct THuffman {
    No* raiz;
};

ostream& operator<<(ostream& os, THuffman& h) {

    if (h.raiz == NULL) {
        os << "arvore vazia" << endl;
    }
    else {
        os << endl << h.raiz->c << h.raiz->freq;
    }
    return os;
}

void inicializar(THuffman& arvore) { arvore.raiz = NULL; }

void tabelaChar(TFila& f, string frase) {

    unordered_map<char, int> freq;
    for (char ch : frase) {
        freq[ch]++;
    }
    for (auto par : freq) {
        queue(f, *gerarNo(par.first, par.second, NULL, NULL));
    }
}

void gerarArvoreCod(THuffman& arvore, TFila& f) {

    No* noesq = new No();
    No* nodir = new No();

    while (f.primeiro != f.ultimo) {
        noesq = gerarNo(f.primeiro->dado.c, f.primeiro->dado.freq,
            f.primeiro->dado.esq, f.primeiro->dado.dir);
        deQueue(f);
        nodir = gerarNo(f.primeiro->dado.c, f.primeiro->dado.freq,
            f.primeiro->dado.esq, f.primeiro->dado.dir);
        deQueue(f);

        queue(f, *gerarNo('\0', noesq->freq + nodir->freq, noesq, nodir));
    }
    arvore.raiz = &f.primeiro->dado;
    f.primeiro = NULL;
}

void codificar(No* raiz, string str,
    unordered_map<char, string>& codificacaoHuffman) {

    if (raiz == NULL)
        return;

    if (raiz->esq == NULL && raiz->dir == NULL) {
        codificacaoHuffman[raiz->c] = str;
    }

    codificar(raiz->esq, str + "0", codificacaoHuffman);
    codificar(raiz->dir, str + "1", codificacaoHuffman);
}

void decodificar(No* raiz, int& indice, string fraseCodificada) {

    if (raiz == NULL) {
        return;
    }

    if (raiz->esq == NULL && raiz->dir == NULL) {
        cout << raiz->c;
        return;
    }

    indice++;

    if (fraseCodificada[indice] == '0')
        decodificar(raiz->esq, indice, fraseCodificada);
    else
        decodificar(raiz->dir, indice, fraseCodificada);
}

void geralHuffman(string frase) {

    // gera uma fila de nó mostrando cada char e sua frequencia
    TFila f;
    inicializarFila(f);
    tabelaChar(f, frase);

    // junta pares de nós até virar uma arvore
    THuffman arvore;
    inicializar(arvore);
    gerarArvoreCod(arvore, f);

    // gera a codificação de cada char
    unordered_map<char, string> codificacaoHuffman;
    codificar(arvore.raiz, "", codificacaoHuffman);

    // mostra os caracteres e suas codificações
    cout << "A codificação de cada letra fica:\n\n";
    for (auto pair : codificacaoHuffman) {
        cout << "Char: " << pair.first << " - codigo: " << pair.second << endl;
    }

    cout << "\nA frase original era: \n" << frase << endl;

    // gera a frase codificada utilizando a tabela e a frase
    string fraseCodificada = "";
    for (char ch : frase) {
        fraseCodificada += codificacaoHuffman[ch];
    }
    cout << "\nA frase codificada fica: \n" << fraseCodificada << endl;

    //----DECODIFICAÇÃO----

    // gera a arvore utilizando a tabela da codificação e a frase

    int indice = -1;

    cout << "\nA frase decodificada fica:\n";

    while (indice < (int)fraseCodificada.size() - 2) {
        decodificar(arvore.raiz, indice, fraseCodificada);
    }
    cout << endl << endl;
}

#endif



