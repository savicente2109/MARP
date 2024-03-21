#include <iostream>
#include <vector>
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"

using namespace std;

int kruskal(GrafoValorado<int> const& g) {
	int coste = 0, numVertices = 0;
	PriorityQueue<Arista<int>> pq(g.aristas());
	ConjuntosDisjuntos cd(g.V());

	while (!pq.empty() && numVertices < g.V() - 1) {
		auto a = pq.top();
		pq.pop();

		int v = a.uno(), w = a.otro(v);
		if (!cd.unidos(v, w)) {
			cd.unir(v, w);
			coste += a.valor();
			++numVertices;
		}
	}

	if (cd.num_cjtos() > 1)
		return -1;
	else
		return coste;
}

bool resuelveCaso() {

	int I, P;
	cin >> I >> P;

	if (!std::cin) // fin de la entrada
		return false;

	GrafoValorado<int> g(I);
	
	int i1, i2, coste;

	for (int i = 0; i < P; ++i) {
		cin >> i1 >> i2 >> coste;
		g.ponArista(Arista<int>(i1 - 1, i2 - 1, coste));
	}

	if (g.A() < g.V() - 1)
		cout << "No hay puentes suficientes\n";

	else {
		int k = kruskal(g);
		if (k == -1)
			cout << "No hay puentes suficientes\n";
		else
			cout << k << '\n';
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}