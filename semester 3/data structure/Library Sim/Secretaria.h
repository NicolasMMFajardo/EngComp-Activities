#ifndef SECRETARIA_H
#define SECRETARIA_H

#include "Fila.h"
#include "Pessoa.h"
#include <iostream>
#include <time.h>

#define MIN_DIA 480

using namespace std;

void secretaria(Fila<Pessoa>& f, int dias, int pChegam, int pAtendidas,
    int atendentes = 1, int pEsperando = 0) {
    for (int i = 0; i < dias; i++) {

        for (int j = 0; j < pEsperando; j++) {
            queue(f, gerarPessoa());
        }

        for (int j = 0; j < MIN_DIA; j++) {
            for (int k = 0; k < pChegam; k++) {
                queue(f, gerarPessoa());
            }
            for (int k = 0; k < (pAtendidas * atendentes); k++) {
                if (f.inicio != NULL)
                    dequeue(f);
            }
        }
    }
}

void simular(float pEsperando = (rand() % 2400 + 1), float pChegam = (rand() % 10 + 1),
    float pAtendidas = (rand() % 5 + 1)) {

    Fila<Pessoa> f;
    inicializarFila(f);

    cout << "Chegam " << pChegam << " pessoas por minuto para serem atendidas.\n";
    cout << "Uma atendente atende " << pAtendidas << " por minuto.\n";
    cout << "Todos os dias há " << pEsperando << " pessoas esperando antes da secretaria abrir.\n\n";

    int chegamPorDia = MIN_DIA * pChegam;
    int atendimentosPorDia = MIN_DIA * pAtendidas;

    secretaria(f, 5, pChegam, pAtendidas, 1, pEsperando);

    if (chegamPorDia + pEsperando / atendimentosPorDia > 1) {

        if (pEsperando != 0) {

            float atendentesNecessarios = (tamFila(f) + 30 * pEsperando + 30 * chegamPorDia) / (30 * atendimentosPorDia);

            cout << "Serão necessarios " << atendentesNecessarios << " atendentes para resolver todos os atrasos.\n\n";

            secretaria(f, 30, pChegam, pAtendidas, atendentesNecessarios + 1, pEsperando);

            cout << "Após o periodo de 30 dias restam " << tamFila(f) << " pessoas na fila.\n\n";

        }
        else {

            float atendentesNecessarios = (tamFila(f) + 3 * chegamPorDia) / (3 * atendimentosPorDia);

            cout << "Serão necessarios " << atendentesNecessarios << " antendentes para resolver todos os atrasos.\n\n";

            secretaria(f, 3, pChegam, pAtendidas, atendentesNecessarios + 1);

            cout << "Após o periodo de 3 dias restam " << tamFila(f) << " pessoas na fila.\n\n";

        }
    }
    else {

        cout << "Saída maior ou igual a entrada, não será necessario alteração.\n\n";

    }
}

#endif