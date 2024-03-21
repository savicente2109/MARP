#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using tMatriz = vector<vector<int>>;

bool resuelveCaso() {
	
	string palabra;
	cin >> palabra;

	if (!std::cin) // fin de la entrada
		return false;
	
	vector<char> p(1);

	p[0] = palabra[0];
	int n = palabra.size();

	for (int i = 1; i < palabra.size(); ++i) {
		if (palabra[i] != palabra[i - 1])
			p.push_back(palabra[i]);
	}

	n = p.size();

	tMatriz m(n, vector<int>(n, 1));

	for (int d = 1; d < n; ++d)
		for (int j = d; j < n; ++j) {
			int i = j - d;
			if (p[i] == p[j])
				m[i][j] += m[i + 1][j - 1];
			else
				m[i][j] += min(m[i + 1][j], m[i][j - 1]);
		}
	
	cout << m[0][n - 1] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}