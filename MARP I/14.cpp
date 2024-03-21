#include <iostream>
#include "ConjuntosDisjuntos.h"

using namespace std;

bool resuelveCaso() {

	int N, M;
	cin >> N >> M;

	if (!std::cin) // fin de la entrada
		return false;

	ConjuntosDisjuntos cd(N);
	int n, rep, aux;

	for (int i = 0; i < M; ++i) {
		cin >> n;
		if (n > 0) cin >> rep;
		for (int j = 1; j < n; ++j) { // entra si n es al menos 2
			cin >> aux;
			cd.unir(rep - 1, aux - 1);
		}
	}
	
	cout << cd.cardinal(0); // siempre existe
	for (int i = 1; i < N; ++i)
		cout << ' ' << cd.cardinal(i);
	cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}