#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool resuelveCaso() {

	int N, M;

	cin >> N >> M;

	if (!std::cin) // fin de la entrada
		return false;

	vector<int> jugadores(N), camisetas(M);

	for (int i = 0; i < N; ++i)
		cin >> jugadores[i];

	for (int i = 0; i < M; ++i)
		cin >> camisetas[i];

	sort(jugadores.begin(), jugadores.end());
	sort(camisetas.begin(), camisetas.end());

	int i = 0, j = 0, cont = 0;
	while (i < N && j < M) {
		if (jugadores[i] == camisetas[j] || jugadores[i] == camisetas[j] - 1) {
			++cont;
			++i;
			++j;
		}
		else if (jugadores[i] > camisetas[j])
			++j;
		else
			++i;
	}

	cout << N - cont << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}