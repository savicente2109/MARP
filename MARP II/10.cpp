#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

using tMatriz = vector<vector<int>>;

bool resuelveCaso() {

	string p1, p2;

	cin >> p1 >> p2;

	if (!std::cin) // fin de la entrada
		return false;

	cin.ignore();
	int N = p1.size(), M = p2.size();

	tMatriz m(N + 1, vector<int>(M + 1));

	for (int i = 1; i < N + 1; ++i)
		for (int j = 1; j < M + 1; ++j)
			if (p1[i - 1] == p2[j - 1])
				m[i][j] = m[i - 1][j - 1] + 1;
			else
				m[i][j] = max(m[i - 1][j], m[i][j - 1]);

	stack<char> pila;
	int i = N, j = M;

	while (i > 0 && j > 0) {
		if (p1[i - 1] == p2[j - 1]) {
			pila.push(p1[i - 1]);
			--i;
			--j;
		}
		else if (m[i][j] == m[i - 1][j])
			--i;
		else
			--j;
	}

	while (!pila.empty()) {
		cout << pila.top();
		pila.pop();
	}

	cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}