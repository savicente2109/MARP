#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

bool resuelveCaso() {
	
	int C, n;
	cin >> C >> n;

	if (!std::cin) // fin de la entrada
		return false;

	vector<int> m(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> m[i];

	vector<int> monedas(C + 1, INF), formas(C + 1, 0);
	monedas[0] = 0;
	formas[0] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= C; ++j)
			if (m[i] <= j)
				if (monedas[j] > monedas[j - m[i]] + 1) {
					monedas[j] = monedas[j - m[i]] + 1;
					formas[j] = formas[j - m[i]];
				}
				else if (monedas[j] == monedas[j - m[i]] + 1)
					formas[j] += formas[j - m[i]];

	cout << formas[C] << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}