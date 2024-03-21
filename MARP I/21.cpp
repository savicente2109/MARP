#include <iostream>
#include <vector>
#include <stack>
#include "Digrafo.h"

using namespace std;

bool DFS(Digrafo const& d, int v, stack<int>& pila, vector<bool>& marked, vector<bool>& apilado) {
	marked[v] = true;
	apilado[v] = true;
	bool ciclo = false;
	for (int w : d.ady(v)) {
		if (!marked[w])
			ciclo = DFS(d, w, pila, marked, apilado) || ciclo;
		else if (apilado[w])
			ciclo = true;
	}

	apilado[v] = false;

	pila.push(v);

	return ciclo;
}

bool resuelveCaso() {

	int L;
	cin >> L;

	if (!std::cin) // fin de la entrada
		return false;

	Digrafo g(L + 1);

	char inst;
	int N;
	cin.ignore();

	for (int i = 0; i < L; ++i) {
		cin >> inst;
		switch (inst) {
		case 'A':
			g.ponArista(i, i + 1);
			break;
		case 'J': 
			cin >> N;
			g.ponArista(i, N - 1);
			break;
		case 'C':
			cin >> N;
			g.ponArista(i, N - 1);
			g.ponArista(i, i + 1);
		}
		cin.ignore();
	}

	vector<bool> marked(L + 1);
	vector<bool> apilado(L + 1);
	stack<int> pila;

	bool ciclo = DFS(g, 0, pila, marked, apilado);

	if (!marked[L])
		cout << "NUNCA\n";
	else if (ciclo)
		cout << "A VECES\n";
	else
		cout << "SIEMPRE\n";

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}