#include <iostream>
#include <vector>
#include <string>
using namespace std;
using tMatriz = vector<vector<bool>>;

bool resuelveCaso() {
	
	string p;
	cin >> p;

	if (!std::cin) // fin de la entrada
		return false;

	int N = p.size();

	tMatriz a(N, vector<bool>(N, false)), b(N, vector<bool>(N, false)), c(N, vector<bool>(N, false));

	for (int i = 0; i < N; ++i) {
		a[i][i] = p[i] == 'a';
		b[i][i] = p[i] == 'b';
		c[i][i] = p[i] == 'c';
	}

	for (int i = 0; i < N - 1; ++i) {
		switch (p[i]) {
		case 'a':
			switch (p[i + 1]) {
			case 'a': b[i][i + 1] = true; break;
			case 'b': b[i][i + 1] = true; break;
			case 'c': a[i][i + 1] = true; break;
			}
			break;
		case 'b':
			switch (p[i + 1]) {
			case 'a': c[i][i + 1] = true; break;
			case 'b': b[i][i + 1] = true; break;
			case 'c': a[i][i + 1] = true; break;
			}
			break;
		case 'c':
			switch (p[i + 1]) {
			case 'a': a[i][i + 1] = true; break;
			case 'b': c[i][i + 1] = true; break;
			case 'c': c[i][i + 1] = true; break;
			}
			break;
		}
	}

	for (int d = 2; d < N; ++d)
		for (int j = d; j < N; ++j) {
			int i = j - d;
			for (int k = i; k < j && !(a[i][j] && b[i][j] && c[i][j]); ++k) {
				a[i][j] = a[i][j] || a[i][k] && c[k + 1][j] || c[i][k] && a[k + 1][j] || b[i][k] && c[k + 1][j];
				b[i][j] = b[i][j] || a[i][k] && a[k + 1][j] || a[i][k] && b[k + 1][j] || b[i][k] && b[k + 1][j];
				c[i][j] = c[i][j] || b[i][k] && a[k + 1][j] || c[i][k] && b[k + 1][j] || c[i][k] && c[k + 1][j];
			}
		}

	if (a[0][N - 1])
		cout << "SI\n";
	else
		cout << "NO\n";
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}