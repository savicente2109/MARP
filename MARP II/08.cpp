#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tMatriz = vector<vector<int>>;

bool resuelveCaso() {
	
	int N;
	cin >> N;

	if (N == 0)
		return false;

	vector<int> v(N);

	for (int i = 0; i < N; ++i)
		cin >> v[i];

	tMatriz m(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
		m[i][i] = v[i];

	for (int i = 0; i < N - 1; ++i)
		m[i][i + 1] = max(v[i], v[i + 1]);

	for (int d = 2; d < N; ++d)
		for (int i = 0; i < N - d; ++i) {
			int j = i + d;
			int op1, op2;
			
			if (v[j] > v[i + 1])
				op1 = m[i + 1][j - 1];
			else
				op1 = m[i + 2][j];

			if (v[i] > v[j - 1])
				op2 = m[i + 1][j - 1];
			else
				op2 = m[i][j - 2];

			m[i][j] = max(v[i] + op1, op2 + v[j]);
		}

	cout << m[0][N - 1] << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}