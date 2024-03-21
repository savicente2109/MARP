#include <iostream>
#include <vector>
#include <stack>
#include "Digrafo.h"

using namespace std;

void DFS(Digrafo const& d, int v, stack<int> & pila, vector<bool> & marked, vector<bool> & apilado, bool & ciclo) {
	marked[v] = true;
	apilado[v] = true;
	for (int w : d.ady(v)) {
		if (ciclo)
			return;
		if (!marked[w])
			DFS(d, w, pila, marked, apilado, ciclo);
		else if (apilado[w])
			ciclo = true;
	}

	apilado[v] = false;

	pila.push(v);
}

void topoSort(Digrafo const& d) {
	
	stack<int> pila;
	vector<bool> marked(d.V());
	vector<bool> apilado(d.V());
	bool ciclo = false;

	for (int v = 0; v < d.V(); ++v)
		if (!marked[v]) DFS(d, v, pila, marked, apilado, ciclo);

	if (!ciclo) {
		cout << pila.top() + 1;
		pila.pop();
		while (!pila.empty()) {
			cout << ' ' << pila.top() + 1;
			pila.pop();
		}
		cout << '\n';
	}
	else
		cout << "Imposible\n";
}

bool resuelveCaso() {

	int N, M;
	cin >> N >> M;

	if (!std::cin) // fin de la entrada
		return false;

	Digrafo d(N);
	int v, w;

	for (int i = 0; i < M; ++i) {
		cin >> v >> w;
		d.ponArista(v - 1, w - 1);
	}

	topoSort(d);

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}