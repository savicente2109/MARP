#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool resuelveCaso() {
	
	int P, N;
	cin >> P >> N;

	if (!std::cin) // fin de la entrada
		return false;

	vector<int> v(N);

	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int i = 0, j = N - 1, viajes = 0;

	while (i <= j) {
		if (v[i] + v[j] <= P)
			++i;
		--j;
		++viajes;
	}

	cout << viajes << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}