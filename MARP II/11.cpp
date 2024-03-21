#include <iostream>
#include <vector>

using namespace std;

using tMatriz = vector<vector<int>>;

bool resuelveCaso() {

	int L, N;
	cin >> L >> N;

	if (L == 0 && N == 0)
		return false;

	N += 2;

	vector<int> c(N);

	c[0] = 0;

	for (int i = 1; i < N - 1; ++i)
		cin >> c[i];

	c[N - 1] = L;

	tMatriz m(N, vector<int>(N));

	for (int j = 2; j < N; ++j)
		m[j - 2][j] = c[j] - c[j - 2];

	for (int d = 3; d < N; ++d)
		for (int j = d; j < N; ++j) {
			int	i = j - d;
			int aux = 1000000000;
			for (int k = i + 1; k < j; ++k)
				if (m[i][k] + m[k][j] < aux)
					aux = m[i][k] + m[k][j];
			m[i][j] = aux + c[j] - c[i];
		}

	cout << 2 * m[0][N - 1] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}