#include <iostream>
#include <vector>
using namespace std;

using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;

bool resuelveCaso() {
	
	int N, M;
	cin >> N >> M;

	if (!std::cin) // fin de la entrada
		return false;

	vvb c(N, vector<bool>(M, true));
	vvi m(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		cin.ignore();
		for (int j = 0; j < M; ++j) {
			
			if (cin.get() == 'P')
				c[i][j] = false;
		}
	}

	if (c[0][0])
		m[0][0] = 1;
	else
		m[0][0] = 0;

	for (int i = 1; i < N; ++i)
		if (c[i][0])
			m[i][0] = m[i - 1][0];
		else
			m[i][0] = 0;

	for (int j = 1; j < M; ++j)
		if (c[0][j])
			m[0][j] = m[0][j  - 1];
		else
			m[0][j] = 0;

	for (int i = 1; i < N; ++i)
		for (int j = 1; j < M; ++j)
			if (c[i][j])
				m[i][j] = m[i - 1][j] + m[i][j - 1];
			else
				m[i][j] = 0;

	cout << m[N - 1][M - 1] << '\n';
		
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}