#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tMatriz = vector<vector<int>>;

bool resuelveCaso(tMatriz const & c) {
	
	int N;
	cin >> N;

	if (!std::cin) // fin de la entrada
		return false;

	int suma = 0;

	for (int j = 1; j <= N; ++j) {
		suma += (c[N][j] % 46337);
		suma = suma % 46337;
	}

	cout << suma << '\n';
	
	return true;
}

int main() {

	int N = 1001;
	vector<int> v(N + 1), comb(N + 1, 1);
	tMatriz c(N + 1, vector<int>(N + 1, 1));

	int suma = 0;

	for (int i = 1; i <= N; ++i) {
		for (int k = 1; k < i; ++k) {
			suma += (c[i - 1][k] % 46337);
			suma = suma % 46337;
		}
		v[i - 1] = suma;
		suma = 0;
		for (int j = i - 1; j > 0; --j) {
			comb[j] += (comb[j - 1] % 46337);
			c[i][j] = ((comb[j] % 46337) * v[i - j]) % 46337;
		}
	}

	while (resuelveCaso(c));
	return 0;
}