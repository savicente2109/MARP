#include <iostream>
#include <vector>
#include "GrafoValorado.h"

using namespace std;

bool modDFS(GrafoValorado<int> const& g, int v, int dest, vector<bool> & marked, int anchura) {

	if (v == dest)
		return true;

	bool llega = false;

	marked[v] = true;

	for (auto a : g.ady(v)) {
		auto w = a.otro(v);
		if (!marked[w] && anchura <= a.valor())
			llega = llega || modDFS(g, w, dest, marked, anchura);
	}

	return llega;
}

bool resuelveCaso() {

	int V, E;
	cin >> V >> E;

	if (!std::cin) // fin de la entrada
		return false;

	GrafoValorado<int> g(V);
	int a, b, anchMax;

	for (int i = 0; i < E; ++i) {
		cin >> a >> b >> anchMax;
		g.ponArista(Arista<int>(a - 1, b - 1, anchMax));
	}

	int K, origen, destino, anchura;
	
	
	cin >> K;

	for (int i = 0; i < K; ++i) {
		cin >> origen >> destino >> anchura;
		vector<bool> marked(V, false);
		if (modDFS(g, origen - 1, destino - 1, marked, anchura))
			cout << "SI\n";
		else
			cout << "NO\n";
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}