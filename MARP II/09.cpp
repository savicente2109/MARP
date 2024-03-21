#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

const int INF = 1000000000;
using tMatriz = vector<vector<int>>;

void Floyd(tMatriz& ady) {
	int N = ady.size();

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				int sep = ady[i][k] + ady[k][j];
				if (sep < ady[i][j]) {
					ady[i][j] = sep;
				}
			}
}

bool resuelveCaso() {
	
	int P, R;
	cin >> P >> R;

	if (!std::cin) // fin de la entrada
		return false;

	if (P == 1) {
		cout << 0 << "\n";
		return true;
	}

	unordered_map<string, int> m;
	tMatriz ady(P, vector<int>(P, INF));
	string aux, aux2;

	for (int i = 0; i < R; ++i) {
		cin >> aux;
		if (m.find(aux) == m.end())
			m.insert({ aux, m.size()});
		cin >> aux2;
		if (m.find(aux2) == m.end())
			m.insert({ aux2, m.size()});
		ady[m[aux]][m[aux2]] = 1;
		ady[m[aux2]][m[aux]] = 1;
	}

	for (int i = 0; i < P; ++i)
		ady[i][i] = 0;

	Floyd(ady);

	int grado = 1;

	for (int i = 0; i < P; ++i)
		for (int j = i + 1; j < P; ++j)
			if (ady[i][j] > grado)
				grado = ady[i][j];

	if (grado == INF)
		cout << "DESCONECTADA\n";
	else
		cout << grado << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}