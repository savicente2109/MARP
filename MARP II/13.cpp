#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

bool resuelveCaso() {
	
	int N;
	cin >> N;

	if (!std::cin) // fin de la entrada
		return false;

	vector<int> m(N + 1), c(N + 1);
	int C;

	for (int i = 1; i <= N; ++i)
		cin >> m[i];

	for (int i = 1; i <= N; ++i)
		cin >> c[i];

	cin >> C;

	vector<int> v(C + 1, INF);
	v[0] = 0;

	for (int i = 1; i <= N; ++i)
		for (int j = C; j > 0; --j) {
			int k = min(j / m[i], c[i]);
			for (int l = 1; l <= k; ++l)
				v[j] = min(v[j], v[j - l * m[i]] + l);
		}

	if (v[C] == INF)
		cout << "NO\n";
	else
		cout << "SI " << v[C] << "\n";
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}