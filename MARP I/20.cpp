#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int> const& v, int k) {
	int n = v.size();
	queue<int> q;
	vector<int> dist(n);
	vector<bool> visit(n);
	dist[0] = 0;
	visit[0] = true;
	q.push(0);
	while (!q.empty()) {
		int casilla = q.front();
		q.pop();

		if (casilla == n - 1)
			return dist[casilla];

		for (int i = 1; i <= k; ++i) {
			int sig = casilla + i;
			if (sig < n && !visit[sig]) {
				dist[sig] = dist[casilla] + 1;
				visit[sig] = true;
				if (v[sig] != -1 && !visit[v[sig]]) {
					dist[v[sig]] = dist[casilla] + 1;
					visit[v[sig]] = true;
					q.push(v[sig]);
				}
				else
					q.push(sig);
			}
		}
	}
}

bool resuelveCaso() {
	
	int N, K, S, E;
	cin >> N >> K >> S >> E;

	if (N == 0 && K == 0 && S == 0 && E == 0)
		return false;

	vector<int> tablero(N * N, -1);
	int aux1, aux2;

	for (int i = 0; i < S + E; ++i) {
		cin >> aux1 >> aux2;
		tablero[aux1 - 1] = aux2 - 1;
	}

	cout << bfs(tablero, K) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}