#include <iostream>
#include <vector>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

void dijkstra(DigrafoValorado<int> const& dg, int S, vector<int> & dist, IndexPQ<int> & pq) {
	dist[S] = 0;
	pq.push(S, 0);
	while (!pq.empty()) {
		int v = pq.top().elem;
		pq.pop();
		for (auto a : dg.ady(v)) {
			int v1 = a.desde(), v2 = a.hasta();
			if (dist[v2] > dist[v1] + a.valor()) {
				dist[v2] = dist[v1] + a.valor();
				pq.update(v2, dist[v2]);
			}
		}
	}
}

bool resuelveCaso() {
	
	int N, S, T, P;

	cin >> N >> S >> T >> P;

	if (!std::cin) // fin de la entrada
		return false;

	DigrafoValorado<int> dv(N);
	int A, B, tiempo;

	for (int i = 0; i < P; ++i) {
		cin >> A >> B >> tiempo;
		dv.ponArista(AristaDirigida<int>(B - 1, A - 1, tiempo)); // creamos directamente el inverso
	}

	IndexPQ<int> pq(dv.V());
	vector<int> dist(dv.V(), 1e9);

	dijkstra(dv, S - 1, dist, pq);

	int num = 0;
	for (int i = 0; i < N; ++i) {
		if (i != S - 1 && dist[i] <= T)
			++num;
	}

	cout << num << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}