#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tMatriz = vector<vector<bool>>;

bool dentroMatriz(int i, int j, int F, int C) {
	return i >= 0 && i < F && j >= 0 && j < C;
}

int dfs(tMatriz const& m, tMatriz & marked, int i, int j) {

	int F = m.size(), C = m[0].size(), num = 0;

	marked[i][j] = true;

	if (dentroMatriz(i - 1, j, F, C) && m[i - 1][j] && !marked[i - 1][j])
		num += dfs(m, marked, i - 1, j) + 1;
	if (dentroMatriz(i, j - 1, F, C) && m[i][j - 1] && !marked[i][j - 1])
		num += dfs(m, marked, i, j - 1) + 1;
	if (dentroMatriz(i + 1, j, F, C) && m[i + 1][j] && !marked[i + 1][j])
		num += dfs(m, marked, i + 1, j) + 1;
	if (dentroMatriz(i, j + 1, F, C) && m[i][j + 1] && !marked[i][j + 1])
		num += dfs(m, marked, i, j + 1) + 1;

	return num;
}

bool resuelveCaso() {

	int F, C;
	cin >> F >> C;

	if (!std::cin) // fin de la entrada
		return false;

	tMatriz m(F, vector<bool>(C)), marked(F, vector<bool>(C, false));
	char aux;

	cin.ignore();

	for (int i = 0; i < F; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> aux;
			m[i][j] = aux == '#';
		}
		cin.ignore();
	}

	int maxi = 0, tamMancha, numManchas = 0;

	for (int i = 0; i < F; ++i)
		for (int j = 0; j < C; ++j)
			if (m[i][j] && !marked[i][j]) {
				tamMancha = dfs(m, marked, i, j) + 1;
				maxi = max(maxi, tamMancha);
				if (tamMancha > 0)
					++numManchas;
			}
			
	cout << numManchas << ' ' << maxi << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}