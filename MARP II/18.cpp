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

	vector<int> f(N);

	for (int i = 0; i < N; ++i)
		cin >> f[i];

	tMatriz m(N, vector<int>(N, 1));

	for (int i = 0; i < N - 1; ++i)
		if (f[i] != f[i + 1] || f[i] == 0)
			m[i][i + 1] = 0;

	for (int d = 3; d < N; d += 2)
		for (int j = d; j < N; ++j) {
			int i = j - d;
			if (f[i] == f[j] && f[i] != 0)
				m[i][j] += m[i + 1][j - 1];
			else if (f[i] == f[i + 1] && f[i] != 0)
				m[i][j] += m[i + 2][j];
			else if (f[j - 1] == f[j] && f[j] != 0)
				m[i][j] += m[i][j - 2];
			else
				m[i][j] = max(max(m[i + 1][j - 1], m[i + 2][j]), m[i][j - 2]);
		}

	cout << m[0][N - 1] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}