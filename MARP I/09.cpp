#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool resuelveCaso() {
	
	int N, A, B;
	cin >> N >> A >> B;

	if (!std::cin) // fin de la entrada
		return false;

	priority_queue<int> pilas_gr, pilas_peq;
	int aux;

	for (int i = 0; i < A; ++i) {
		cin >> aux;
		pilas_gr.push(aux);
	}

	for (int i = 0; i < B; ++i) {
		cin >> aux;
		pilas_peq.push(aux);
	}

	int g, p, horas = 0;

	while (!pilas_gr.empty() && !pilas_peq.empty()) {
		vector <int> reutilizables_gr, reutilizables_peq;
		for (int i = 0; i < N && !pilas_gr.empty() && !pilas_peq.empty(); ++i) {
			g = pilas_gr.top();
			pilas_gr.pop();
			p = pilas_peq.top();
			pilas_peq.pop();
			if (g > p) {
				reutilizables_gr.push_back(g - p);
				horas += p;
			}
			else if (g < p) {
				reutilizables_peq.push_back(p - g);
				horas += g;
			}
			else
				horas += g;
		}
		for (int i = 0; i < reutilizables_gr.size(); ++i)
			pilas_gr.push(reutilizables_gr[i]);
		for (int i = 0; i < reutilizables_peq.size(); ++i)
			pilas_peq.push(reutilizables_peq[i]);
		reutilizables_gr.clear();
		reutilizables_peq.clear();

		cout << horas << ' ';
		horas = 0;
	}

	cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}