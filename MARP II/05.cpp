#include <iostream>
#include <vector>
#include <algorithm>
#include "EnterosInf.h"

using namespace std;

const int INF = 1000000000;

bool resuelveCaso() {
	
	int N, pmax, pmin;
	cin >> N >> pmax >> pmin;

	if (!std::cin) // fin de la entrada
		return false;

	vector<int> p(N), c(N);

	for (int i = 0; i < N; ++i)
		cin >> p[i];

	for (int i = 0; i < N; ++i)
		cin >> c[i];

	vector<EntInf> v(pmax + 1, INF);
	v[0] = 0;

	for (int i = 1; i < N + 1; ++i)
		for (int j = 1; j <= pmax; ++j)
			if (p[i - 1] <= j)
				v[j] = min(v[j], v[j - p[i - 1]] + c[i - 1]);

	EntInf costeMin = INF;
	int pot;

	for (int j = pmin; j <= pmax; ++j) {
		if (v[j] < costeMin) {
			costeMin = v[j];
			pot = j;
		}
	}

	if (costeMin == INF)
		cout << "IMPOSIBLE\n";
	else
		cout << costeMin << ' ' << pot << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}