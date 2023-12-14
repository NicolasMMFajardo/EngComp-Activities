#include "Secretaria.h"

int main() {
    srand(time(NULL));

    Fila<Pessoa> SecretariaIES;
    inicializarFila(SecretariaIES);

    cout << "-- QUESTÃO 1 --\n\n";
    simular(0, 5, 1);

    cout << "-- QUESTÃO 2 --\n\n";
    simular(0);

    cout << "-- QUESTÃO 3 --\n\n";
    simular();
}

template <typename tipo>
void bbsort(int vet[], tipo n) {
    tipo temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vet[j] < vet[j + 1]) {
                swap(vet[j], vet[j + 1]);
            }
        }
    }
}