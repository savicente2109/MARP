#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000;

vector<int> calc_sol(vector<int> const& v, int V, vector<int> const& dardos) {
	size_t n = v.size() - 1;
	vector<int> cuantos(n + 1, 0);
	int i = n; int j = V;
	while (j > 0) {
		if (v[i] <= j && dardos[j] == dardos[j - v[i]] + 1) {
			++cuantos[i];
			j = j - v[i];
		}
		else
			--i;
	}
	return cuantos;
}

bool resuelveCaso() {

	int V, S;
	cin >> V >> S;

	if (!std::cin) // fin de la entrada
		return false;

	vector<int> v(S + 1);

	for (int i = 1; i <= S; ++i) {
		cin >> v[i];
	}

	int n = v.size() - 1;

	vector<int> dardos(V + 1, INF);
	dardos[0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = v[i]; j <= V; ++j) {
			dardos[j] = min(dardos[j], dardos[j - v[i]] + 1);
		}
	}

	if (dardos[V] == INF)
		cout << "Imposible\n";

	else {
		vector<int> sol = calc_sol(v, V, dardos);
		cout << dardos[V] << ":";

		for (int i = n; i >= 1; --i) {
			while (sol[i] > 0) {
				cout << " " << v[i];
				--sol[i];
			}
		}
		cout << '\n';
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}