#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tMatriz = vector<vector<int>>;

bool resuelveCaso() {

	int N;
	cin >> N;

	if (!std::cin) // fin de la entrada
		return false;

	tMatriz m(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> m[i][j];

	for (int i = 1; i < N - 1; ++i) {
		m[i][0] += max(m[i - 1][0], m[i - 1][1]); // Sabemos que N es por lo menos 3
		for (int j = 1; j < N - 1; ++j)
			m[i][j] += max(max(m[i - 1][j - 1], m[i - 1][j]), m[i - 1][j + 1]);
		m[i][N - 1] += max(m[i - 1][N - 2], m[i - 1][N - 1]); // Sabemos que N es por lo menos 3
	}

	int maxi = 0, col, aux;
	
	aux = m[N - 1][0] + max(m[N - 2][0], m[N - 2][1]);
	if (aux > maxi) {
		maxi = aux;
		col = 1;
	}
	for (int j = 1; j < N - 1; ++j) {
		aux = m[N - 1][j] + max(max(m[N - 2][j - 1], m[N - 2][j]), m[N - 2][j + 1]);
		if (aux > maxi) {
			maxi = aux;
			col = j + 1;
		}
	}
	aux = m[N - 1][N - 1] + max(m[N - 2][N - 2], m[N - 2][N - 1]);
	if (aux > maxi) {
		maxi = aux;
		col = N;
	}

	cout << maxi << ' ' << col << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}