#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void resuelveCaso() {
	
	int N, V;
	cin >> N >> V;

	vector<int> pilas(N);

	for (int i = 0; i < N; ++i)
		cin >> pilas[i];

	sort(pilas.begin(), pilas.end());

	int i = 0, j = N - 1, coches = 0;

	while (i < j) {
		if (pilas[i] + pilas[j] >= V) {
			--j;
			++coches;
		}
		++i;
	}

	cout << coches << '\n';

}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}