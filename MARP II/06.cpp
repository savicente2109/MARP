#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

using tMatriz = vector<vector<int>>;

struct tesoro {
	int val;
	int prof;
};

bool resuelveCaso() {

	int T, N;
	cin >> T >> N;

	if (!std::cin) // fin de la entrada
		return false;

	vector<tesoro> v(N + 1);

	for (int i = 1; i < N + 1; ++i)
		cin >> v[i].prof >> v[i].val;

	tMatriz m(N + 1, vector<int>(T + 1));
	int t;

	for (int i = 1; i < N + 1; ++i) {
		t = v[i].prof * 3;
		for (int j = 1; j < T + 1; ++j)
			if (t > j)
				m[i][j] = m[i - 1][j];
			else
				m[i][j] = max(m[i - 1][j - t] + v[i].val, m[i - 1][j]);
	}
	
	int j = T;
	stack<tesoro> pila;

	for (int i = N; i > 0; --i) {
		if (m[i][j] != m[i - 1][j]) { // El tesoro se coge
			pila.push(v[i]);
			j -= v[i].prof * 3;
		}
	}

	cout << m[N][T] << '\n' << pila.size() << '\n';

	while (!pila.empty()) {
		tesoro top = pila.top();
		pila.pop();
		cout << top.prof << ' ' << top.val << '\n';
	}

	cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}