#include <iostream>
#include <vector>
#include <queue>
#include "Grafo.h"

using namespace std;

int bfs(Grafo const& g, int origen, int TTL) {
	queue<int> q;
	vector<bool> marked(g.V(), false);
	vector<int> dist(g.V());
	int cont = 1;

	marked[origen] = true;
	dist[origen] = 0;
	q.push(origen);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (dist[v] > TTL)
			return cont;

		for (int w : g.ady(v)) {
			if (!marked[w]) {
				dist[w] = dist[v] + 1;
				marked[w] = true;
				q.push(w);

				if (dist[w] <= TTL)
					++cont;
			}
		}
	}

	return cont;
}

bool resuelveCaso() {

	int N, C, K, origen, TTL;

	cin >> N >> C;
	
	if (!std::cin) // fin de la entrada
		return false;

	Grafo g(N);
	int A, B;

	for (int i = 0; i < C; ++i) {
		cin >> A >> B;
		g.ponArista(A - 1, B - 1);
	}

	cin >> K;

	for (int i = 0; i < K; ++i) {
		cin >> origen >> TTL;
		cout << N - bfs(g, origen - 1, TTL) << '\n';
	}

	cout << "---\n";
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}