#include <iostream>
#include <time.h>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    int acao, r, contador = 10, acertos;
    char l1, l2, l3, l4, l5, l6, tentativa, lc1, lc2, lc3, lc4, lc5, lc6;
    bool fim;

    do {
        system("cls");
        cout << "Bem Vindo ao jogo, selecione a ação desejada.\n\n > Jogar (digite 1)\n > Sobre (digite 2)\n > Fim (digite 3)\n\n"; //menu
        cin >> acao;

        srand(time(NULL));
        r = rand() % 10 + 1;

        l1 = '_', l2 = '_', l3 = '_', l4 = '_', l5 = '_', l6 = '_';

        switch (r) {
        case 1:
            lc1 = 'a', lc2 = 'l', lc3 = 'a', lc4 = 'd', lc5 = 'i', lc6 = 'n'; //palavra é aladin
            break;
        case 2:
            lc1 = 'a', lc2 = 'v', lc3 = 'a', lc4 = 't', lc5 = 'a', lc6 = 'r'; //palavra é avatar
            break;
        case 3:
            lc1 = 'b', lc2 = 'a', lc3 = 'r', lc4 = 'b', lc5 = 'i', lc6 = 'e'; //palavra é batman
            break;
        case 4:
            lc1 = 'b', lc2 = 'a', lc3 = 'r', lc4 = 'n', lc5 = 'e', lc6 = 'y'; //palavra é barney
            break;
        case 5:
            lc1 = 'b', lc2 = 'a', lc3 = 't', lc4 = 'm', lc5 = 'a', lc6 = 'n'; //palavra é batman
            break;
        case 6:
            lc1 = 'm', lc2 = 'a', lc3 = 'g', lc4 = 'a', lc5 = 'l', lc6 = 'i'; //palavra é magali
            break;
        case 7:
            lc1 = 'm', lc2 = 'o', lc3 = 'n', lc4 = 'i', lc5 = 'c', lc6 = 'a'; //palavra é monica
            break;
        case 8:
            lc1 = 'n', lc2 = 'a', lc3 = 'r', lc4 = 'u', lc5 = 't', lc6 = 'o'; //palavra é naruto
            break;
        case 9:
            lc1 = 't', lc2 = 'a', lc3 = 'r', lc4 = 'z', lc5 = 'a', lc6 = 'n'; //palavra é tarzan
            break;
        case 10:
            lc1 = 'p', lc2 = 'a', lc3 = 't', lc4 = 'e', lc5 = 't', lc6 = 'a'; //palavra é pateta
            break;
        }

        switch (acao) { //leva pra ação desejada

        case 1: //roda o jogo
            system("cls");

            for (contador = 10, acertos = 0; contador > 0 && acertos != 6; contador--) { //repetição para novo jogo
                system("cls");

                cout << " __________\n||         |\n||\n||\n||\n||\n||\n||  " << l1 << " " << l2 << " " << l3 << " " << l4 << " " << l5 << " " << l6 << "\n\nTema: Personagens\nAcertos: " << acertos << "\nEntre com uma letra, você ainda tem " << contador << " tentativas.\n\n";
                cin >> tentativa;
                if (tentativa == lc1 && l1 == '_') {
                    l1 = lc1;
                    acertos++;
                }
                if (tentativa == lc2 && l2 == '_') {
                    l2 = lc2;
                    acertos++;
                }
                if (tentativa == lc3 && l3 == '_') {
                    l3 = lc3;
                    acertos++;
                }
                if (tentativa == lc4 && l4 == '_') {
                    l4 = lc4;
                    acertos++;
                }
                if (tentativa == lc5 && l5 == '_') {
                    l5 = lc5;
                    acertos++;
                }
                if (tentativa == lc6 && l6 == '_') {
                    l6 = lc6;
                    acertos++;
                }
            }
            system("cls");
            if (acertos == 6) { //caso seus acertos foram de 6, você ganha
                cout << "            Você Ganhou!\n\n";
                cout << "             ___________" << endl;
                cout << "            '._==_==_=_.'" << endl;
                cout << "            .-\:       /-." << endl;
                cout << "           | (|:.     |) |" << endl;
                cout << "            '-|:. 1   |-'" << endl;
                cout << "              \::.    /" << endl;
                cout << "               '::. .'" << endl;
                cout << "                 ) (" << endl;
                cout << "               _.' '._" << endl;
                cout << "            `'''''''''''`" << endl;
            }
            else { //caso contrario, você perde
                cout << "          Você Perdeu!\n\n";
                cout << "         _,.-------.,_" << endl;
                cout << "     ,;~'             '~;," << endl;
                cout << "   ,;                     ;," << endl;
                cout << "  ;                         ;" << endl;
                cout << " ,'                         '," << endl;
                cout << ",;                           ;," << endl;
                cout << "; ;      .           .      ; ;" << endl;
                cout << "| ;   ______       ______   ; |" << endl;
                cout << "|  `/~'     ~' . '~     '~\.' |" << endl;
                cout << "|  ~  ,-~~~^~, | ,~^~~~-,  ~  |" << endl;
                cout << " |   |        }:{        |   |" << endl;
                cout << " |   l       / | \       !   |" << endl;
                cout << " .~  (__,.--' .^. '--.,__)  ~." << endl;
                cout << " |     ---;' / | \ `;---     |" << endl;
                cout << "  \__.      \./^\./      .__/" << endl;
                cout << "   V| \                 / |V" << endl;
                cout << "    | |T~\___!___!___/~T| |" << endl;
                cout << "    | |`IIII_I_I_I_IIII'| |" << endl;
                cout << "    |  \,III I I I III,/  |" << endl;
                cout << "     \   `~~~~~~~~~~'    /" << endl;
                cout << "       \   .       .   /" << endl;
                cout << "         \.    ^    ./" << endl;
                cout << "           ^~~~^~~~^" << endl;
            }
            system("pause");
            fim = false;
            break;
        case 2: //mostra sobre o jogo e mais
            system("cls");
            cout << "Sobre o jogo:\n\nO jogo da forca é um jogo em que o jogador tem que acertar qual é a palavra proposta, tendo como dica o número de letras e o tema ligado à palavra.\nVocê terá 10 chances de acertar as 6 letras necessarias para ganhar o jogo. Use somente letras minúsculas.\n\n> Desenvolvedores: Julia Doré, Nicolas Fajardo, Paulo Afonso e Thiago Corrêa.\n\n> Algorítmos e Programação I, Professor Rafael Ballottin Martins.\n\n> Outubro,2021.\n\n";
            system("pause");
            fim = false;
            break;
        case 3: //finaliza o jogo
            system("cls");
            cout << "Obrigado por jogar nosso jogo!\n";
            fim = true;
            break;
        default:
            system("cls");
            fim = false;
        }
    } while (fim == false);

    return 0;
}
