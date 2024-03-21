#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool resuelveCaso() {

	int N, K;
	cin >> N;

	if (!std::cin) // fin de la entrada
		return false;

	int mini = 1e9, aux, posicion = 1;
	vector<stack<int>> v(N);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	bool encontrado = false;
	pair<int, int> top;

	for (int i = 0; i < N; ++i) {
		cin >> K;
		for (int j = 0; j < K; ++j) {
			cin >> aux;
			if (aux < mini)
				mini = aux;
			v[i].push(aux);
		}
	}
	
	for (int i = 0; i < N; ++i) {
		pq.push({ v[i].top(), i });
		v[i].pop();
	}

	while (!encontrado) {
		top = pq.top();
		if (top.first == mini)
			encontrado = true;
		else {
			pq.pop();
			if (!v[top.second].empty()) {
				pq.push({ v[top.second].top(), top.second });
				v[top.second].pop();
			}
			++posicion;
		}
	}
	
	cout << posicion << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}