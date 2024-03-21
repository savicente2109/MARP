#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct nodo {
	vector<int> sol;
	int k;
	int calidad;
	int calidad_opt;
	vector<bool> asignado;
};

bool operator< (nodo const& n1, nodo const& n2) {
	return n1.calidad_opt < n2.calidad_opt;
}

bool operator> (nodo const& n1, nodo const& n2) {
	return n1.calidad_opt > n2.calidad_opt;
}

bool operator== (nodo const& n1, nodo const& n2) {
	return n1.calidad_opt == n2.calidad_opt;
}
/*
int pes(nodo const& n, vector<int> const& a_carros, vector<int> const& a_cam, vector<vector<int>> const& c) {
	int N = n.sol.size(), pesimista = n.calidad;
	for (int i = n.k + 1; i < N; ++i) {
		if (!n.asignado[i] && a_carros[i] <= a_cam[i])
			pesimista += c[i][i];
	}
	return pesimista;
}
*/
void resuelveCaso() {
	int n, m;
	cin >> n >> m;

	vector<int> a_carros(n + 1), a_cam(m + 1), opt(n + 1);
	vector<vector<int>> c(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
		cin >> a_carros[i];
	for (int i = 1; i <= m; ++i)
		cin >> a_cam[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> c[i][j];

	if (n == 0) {
		cout << 0 << '\n';
		return;
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 1; j <= m; ++j)
			if (a_carros[i + 1] <= a_cam[j])
				opt[i] = max(opt[i], c[i + 1][j]);
		opt[i] += opt[i + 1];
	}

	nodo x, y;
	priority_queue<nodo> pq;
	y.k = 0;
	y.sol.resize(n + 1);
	y.asignado.resize(m + 1);
	y.calidad = 0;
	y.calidad_opt = opt[0];
	pq.push(y);
	//int calidad_mejor = pes(y, a_carros, a_cam, c);
	int calidad_mejor = y.calidad;

	while (!pq.empty() && pq.top().calidad_opt >= calidad_mejor) {
		y = pq.top();
		pq.pop();
		x.k = y.k + 1;
		x.sol = y.sol;
		x.asignado = y.asignado;

		x.sol[x.k] = 0;
		x.calidad = y.calidad;
		x.calidad_opt = x.calidad + opt[x.k];
		if (x.calidad_opt >= calidad_mejor) {
			if (x.k == n) {
				calidad_mejor = x.calidad;
			}
			else {
				pq.push(x);
				//calidad_mejor = max(calidad_mejor, pes(x, a_carros, a_cam, c));
				calidad_mejor = max(calidad_mejor, x.calidad);
			}
		}

		for (int t = 1; t <= m; ++t) {
			if (!x.asignado[t]) {
				x.sol[x.k] = t;
				x.asignado[t] = true;
				x.calidad = y.calidad;
				if (a_carros[x.k] <= a_cam[t])
					x.calidad += c[x.k][t];
				x.calidad_opt = x.calidad + opt[x.k];
				if (x.calidad_opt >= calidad_mejor) {
					if (x.k == n) {
						calidad_mejor = x.calidad;
					}
					else {
						pq.push(x);

						//calidad_mejor = max(calidad_mejor, pes(x, a_carros, a_cam, c));
						calidad_mejor = max(calidad_mejor, x.calidad);
					}
				}
				x.asignado[t] = false;
			}
		}
	}

	cout << calidad_mejor << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}