#include "huffman.h"

//LINK RELATORIO
//https://univali-my.sharepoint.com/:w:/g/personal/fernando_trentin_edu_univali_br/EWqoBXeb-BBIraord1WThPIBlLFRvclOcHegZEVzJvRgjg?e=ngwRDN
int main() {

	string frase = "fernando vai se fuder seu merda do caralho voce cagou tudo e agora nao sei como arrumar essa droga fumei tres quilo de cocoina ontem e injetei 40g de maconha quando tomei 50ml de porra, mas o melhor foi que quem deve nao merece e quem merece tem aquilo que deve goleada do gremio pra cima do palmeiras vai gremioooooo ihuuuuuu gremio caralho ai sim";
	cout << "----- FRASE 1 -----\n\n";
	geralHuffman(frase);

	string frase2 = "vai gremio uhuuuuuuuuuuuuuuuu";
	cout << "----- FRASE 2 -----\n\n";
	geralHuffman(frase2);

	// cout << "Entre com a frase para ser codificada.\n";
	// getline(cin, frase);
}