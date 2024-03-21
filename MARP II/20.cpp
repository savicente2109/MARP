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

	tMatriz c(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
			cin >> c[i][j];

	for (int d = 2; d < N; ++d)
		for (int j = d; j < N; ++j) {
			int i = j - d;
			for (int m = i + 1; m < j; ++m)
				c[i][j] = min(c[i][j], c[i][m] + c[m][j]);
		}

	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j)
			cout << c[i][j] << ' ';
		cout << '\n';
	}
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}