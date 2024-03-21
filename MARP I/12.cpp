#include <iostream>
#include <algorithm>
#include "ConjuntosDisjuntos.h"

using namespace std;

int grupoMasGrande(ConjuntosDisjuntos const& cd, int N) {

	int maxi = 0;

	for (int i = 0; i < N; ++i) {
		maxi = max(maxi, cd.cardinal(i));
	}

	return maxi;
}

void resuelveCaso() {
	int N, M;
	cin >> N >> M;
	ConjuntosDisjuntos cd(N);
	
	int amigo1, amigo2;
	for (int i = 0; i < M; ++i) {
		cin >> amigo1 >> amigo2;
		cd.unir(amigo1 - 1, amigo2 - 1);
	}

	cout << grupoMasGrande(cd, N) << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}