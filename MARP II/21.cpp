#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct nodo {
	vector<int> sol;
	int k;
	int tiempo;
	int tiempo_opt;
	vector<bool> asignado;
};

bool operator< (nodo const& n1, nodo const& n2) {
	return n1.tiempo_opt < n2.tiempo_opt;
}

bool operator> (nodo const& n1, nodo const& n2) {
	return n1.tiempo_opt > n2.tiempo_opt;
}

bool operator== (nodo const& n1, nodo const& n2) {
	return n1.tiempo_opt == n2.tiempo_opt;
}

int rp(vector<vector<int>> const& T) {
	int N = T.size() - 1, tiempo_mejor = 1e9;
	nodo x, y;
	priority_queue<nodo, vector<nodo>, greater<nodo>> pq;
	vector<int> opt(N + 1), pes(N + 1), rap(N + 1), len(N + 1);
	for (int i = 1; i <= N; ++i) {
		rap[i] = T[i][1];
		len[i] = T[i][1];
		for (int j = 2; j <= N; ++j) {
			rap[i] = min(rap[i], T[i][j]);
			len[i] = max(len[i], T[i][j]);
		}
	}
	opt[N] = 0; pes[N] = 0;
	for (int i = N - 1; i >= 0; --i) {
		opt[i] = opt[i + 1] + rap[i + 1];
		pes[i] = pes[i + 1] + len[i + 1];
	}

	y.k = 0;
	y.asignado.resize(N + 1);
	y.sol.resize(N + 1);
	y.tiempo = 0;
	y.tiempo_opt = opt[0];
	pq.push(y);
	tiempo_mejor = pes[0];

	while (!pq.empty() && pq.top().tiempo_opt <= tiempo_mejor) {
		y = pq.top(); pq.pop();
		x.k = y.k + 1;
		x.sol = y.sol;
		x.asignado = y.asignado;
		for (int t = 1; t <= N; ++t) {
			if (!x.asignado[t]) {
				x.sol[x.k] = t;
				x.asignado[t] = true;
				x.tiempo = y.tiempo + T[x.k][t];
				x.tiempo_opt = x.tiempo + opt[x.k];
				if (x.tiempo_opt <= tiempo_mejor) {
					if (x.k == N) {
						tiempo_mejor = x.tiempo;
					}
					else {
						pq.push(x);
						tiempo_mejor = min(tiempo_mejor, x.tiempo + pes[x.k]);
					}
				}
				x.asignado[t] = false;
			}
		}
	}

	return tiempo_mejor;
}

bool resuelveCaso() {

	int N;
	cin >> N;

	if (N == 0)
		return false;

	vector<vector<int>> T(N + 1, vector<int> (N + 1));

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> T[i][j];

	cout << rp(T) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}