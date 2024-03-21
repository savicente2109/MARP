#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool resuelveCaso() {

	int N;
	cin >> N;

	if (!std::cin) // fin de la entrada
		return false;

	vector<int> enemigos(N), equipos(N);

	for (int i = 0; i < N; ++i)
		cin >> enemigos[i];

	for (int i = 0; i < N; ++i)
		cin >> equipos[i];

	sort(enemigos.begin(), enemigos.end());
	sort(equipos.begin(), equipos.end());

	int i = 0, j = 0, garantizados  = 0;

	while (i < N && j < N) {
		if (enemigos[i] <= equipos[j]) {
			++garantizados;
			++i;
		}
		++j;
	}

	cout << garantizados << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}