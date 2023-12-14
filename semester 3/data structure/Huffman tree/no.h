#ifndef NO_H
#define NO_H

#include <iostream>

using namespace std;

struct No {
	char c;
	int freq;
	No* esq, * dir;
};

bool operator<(No n1, No n2) {
	return n1.freq < n2.freq;
}

bool operator>(No n1, No n2) {
	return n1.freq > n2.freq;
}

ostream& operator<<(ostream& os, No& no) {

	os << "char: " << no.c
		<< " freq: " << no.freq
		<< " ptr esq: " << no.esq
		<< " ptr dir: " << no.dir << endl;

	return os;
}

No* gerarNo(char c, int freq, No* esq, No* dir) {

	No* no = new No;
	no->c = c;
	no->freq = freq;
	no->esq = esq;
	no->dir = dir;
	return no;
}

#endif