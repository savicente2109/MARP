#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using tMatriz = vector<vector<int>>;

string construir_sol(tMatriz const& m, string const& palabra, int i, int j) {
	if (i > j)
		return {};
	if (i == j)
		return { palabra[i] };
	// if (m[i][j] == m[i + 1][j - 1])
	if (palabra[i] == palabra[j])
		return palabra[i] + construir_sol(m, palabra, i + 1, j - 1) + palabra[j];
	if (m[i][j] == m[i][j - 1] + 1)
		return palabra[j] + construir_sol(m, palabra, i, j - 1) + palabra[j];
	return palabra[i] + construir_sol(m, palabra, i + 1, j) + palabra[i];
}

bool resuelveCaso() {

	string palabra;
	cin >> palabra;

	if (!std::cin) // fin de la entrada
		return false;

	int N = palabra.size();

	if (N == 0) {
		cout << 0 << " \n";
		return true;
	}

	cin.ignore();

	tMatriz m(N, vector<int>(N, 0)); // La diagonal princpal y la inmediatamente inferior deben contener ceros

	// Recorremos la matriz por diagonales a partir de la que de encima de la principal

	for (int d = 1; d < N; ++d)
		for (int i = 0; i < N - d; ++i) {
			int j = i + d;
			if (palabra[i] == palabra[j])
				m[i][j] = m[i + 1][j - 1];
			else
				m[i][j] = min(m[i + 1][j], m[i][j - 1]) + 1;
		}

	cout << m[0][N - 1] << ' ' << construir_sol(m, palabra, 0, N - 1) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}