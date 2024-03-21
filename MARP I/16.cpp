#include <iostream>
#include <vector>
#include <algorithm>
#include "ConjuntosDisjuntos.h"

using namespace std;

bool resuelveCaso() {
	
	int N, C;
	cin >> N >> C;

	if (!std::cin) // fin de la entrada
		return false;

	ConjuntosDisjuntos cd(N);
	int a, b;

	for (int i = 0; i < C; ++i) {
		cin >> a >> b;
		cd.unir(a - 1, b - 1);
	}

	int S, punto, precio, aux;
	cin >> S;
	vector<int> precioMin(N, 1e9);

	for (int i = 0; i < S; ++i) {
		cin >> punto >> precio;
		aux = cd.buscar(punto - 1);
		precioMin[aux] = min(precioMin[aux], precio);
	}

	int K, comprador, precioMini;
	cin >> K;

	for (int i = 0; i < K; ++i) {
		cin >> comprador;
		precioMini = precioMin[cd.buscar(comprador - 1)];
		if (precioMini == 1e9)
			cout << "MENUDO MARRON\n";
		else
			cout << precioMini << '\n';
	}

	cout << "---\n";

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}