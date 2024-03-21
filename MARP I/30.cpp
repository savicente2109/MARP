#include <iostream>
#include <vector>

using namespace std;

bool resuelveCaso() {
	
	int N, L;

	cin >> N >> L;

	if (!std::cin) // fin de la entrada
		return false;

	int num = 1, agujero, extremo;

	cin >> agujero; // Siempre hay al menos uno
	extremo = agujero + L;

	for (int i = 1; i < N; ++i) {
		cin >> agujero;
		if (agujero > extremo) {
			extremo = agujero + L;
			++num;
		}
	}

	cout << num << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}