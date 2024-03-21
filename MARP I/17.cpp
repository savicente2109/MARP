#include <iostream>
#include <vector>
#include <queue>
#include "Digrafo.h"

using namespace std;

int bfs(Digrafo const& g, int origen, int destino) {

	queue<int> q;
	vector<bool> marked(g.V(), false);
	vector<int> dist(g.V());

	marked[origen] = true;
	dist[origen] = 0;
	q.push(origen);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (v == destino)
			return dist[v]; // Siempre se llega, aunque sea sumando de uno en uno

		for (int w : g.ady(v)) {
			if (!marked[w]) {
				dist[w] = dist[v] + 1;
				marked[w] = true;
				q.push(w);
			}
		}
	}
}

bool resuelveCaso(Digrafo const& g) {

	int origen, destino, N = 10000;

	cin >> origen >> destino;

	if (!std::cin) // fin de la entrada
		return false;

	cout << bfs(g, origen, destino) << '\n';

	return true;
}

Digrafo crearGrafo() {

	int N = 10000;

	Digrafo g(N);

	// +1
	for (int i = 0; i < N - 1; ++i)
		g.ponArista(i, i + 1);
	g.ponArista(N - 1, 0);

	// *2
	for (int i = 0; i < N; ++i) {
		int doble = (2 * i) % N;
		if (doble != i)
			g.ponArista(i, doble);
	}

	// /3
	for (int i = 1; i < N; ++i) // no interesa unir el 0 con el 0 si queremos caminos mínimos
		g.ponArista(i, i / 3);

	return g;
}

int main() {
	Digrafo g = crearGrafo();
	while (resuelveCaso(g));
	return 0;
}