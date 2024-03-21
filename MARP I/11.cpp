#include <iostream>
#include <vector>
#include "Grafo.h"

using namespace std;

void DFS(Grafo const& G, int v, vector<bool> & marked) {
	marked[v] = true;
	for (int w : G.ady(v))
		if (!marked[w])
			DFS(G, w, marked);
}

bool esArbol(Grafo const& G) {

	vector<bool> marked(G.V(), false);

	DFS(G, 0, marked);

	for (int i = 0; i < G.V(); ++i)
		if (!marked[i])
			return false;
	
	return G.V() == G.A() + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	// leer grafo
	Grafo G(cin);

	if (!std::cin) // fin de la entrada
		return false;

	if (esArbol(G))
		cout << "SI\n";
	else
		cout << "NO\n";

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}