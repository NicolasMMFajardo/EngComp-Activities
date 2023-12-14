#include <time.h>
#include "Rodada.h"

void menu() {
    cout << "--- MENU ---\nEscolha qual lista você gostaria de ver:\n1 - Rank dos TOP 10 jogadores\n2 - Rank geral com todos os jogadores\n";
}

int main() {
    srand(time(NULL));

    int escolha_rank;
    menu();
    cin >> escolha_rank;
    system("clear");

    switch (escolha_rank) {
    case 1: {
        TListaEstatica<TJogador, NUM_JOGADORES> RankFixo;
        inicializar_lista(RankFixo);
        jogar_rodada(RankFixo);
    }break;
    case 2: {
        TListaEncadeada<TJogador> RankGeral;
        inicializar_lista(RankGeral);
        jogar_rodada(RankGeral);
    }break;
    default: {
        cout << "lista inválida";
    }
    }
}