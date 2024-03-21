#include <iostream>
#include <vector>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

void dijkstra(DigrafoValorado<int> const& dg, int S, vector<int>& dist, IndexPQ<int>& pq) {
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

	int N, M;
	cin >> N;

	if (N == 0)
		return false;

	vector<int> tiemposCarga(N);

	for (int i = 0; i < N; ++i)
		cin >> tiemposCarga[i];

	cin >> M;

	DigrafoValorado<int> dv(N);
	int pag1, pag2, tiempo;

	for (int i = 0; i < M; ++i) {
		cin >> pag1 >> pag2 >> tiempo;
		dv.ponArista(AristaDirigida<int>(pag1 - 1, pag2 - 1, tiemposCarga[pag1 - 1] + tiempo));
	}

	IndexPQ<int> pq(dv.V());
	vector<int> dist(dv.V(), 1e9);

	dijkstra(dv, 0, dist, pq);

	if (dist[N - 1] == 1e9)
		cout << "IMPOSIBLE\n";
	else
		cout << dist[N - 1] + tiemposCarga[N - 1] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}