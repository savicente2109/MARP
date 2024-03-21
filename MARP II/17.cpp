#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
	
	int N, K;
	cin >> N >> K;

	if (!std::cin) // fin de la entrada
		return false;

	vector<int> p(N + 1), b(N + 1);

	for (int i = 1; i <= N; ++i)
		cin >> p[i];
	
	for (int i = 1; i <= N; ++i)
		cin >> b[i];

	for (int i = 2; i <= N; ++i)
		b[i] = max(b[i - 1], b[upper_bound(p.begin(), p.end(), p[i] - K) - p.begin() - 1] + b[i]);

	cout << b[N] << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}