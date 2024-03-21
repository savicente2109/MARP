#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct tarea {
	int ini;
	int fin;
	int periodo = 0;
};

bool operator> (const tarea& t1, const tarea& t2) {
	return t1.ini > t2.ini;
}

bool resuelveCaso() {

	int N, M, T;
	cin >> N >> M >> T;
	
	if (!std::cin) // fin de la entrada
		return false;

	//priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	priority_queue <tarea, vector<tarea>, greater<tarea>> pq;

	int ini, fin, periodo;

	for (int i = 0; i < N; ++i) {
		cin >> ini >> fin;
		if (ini < T)
			pq.push({ ini, min(fin, T) });
	}

	for (int i = 0; i < M; ++i) {
		cin >> ini >> fin >> periodo;
		if (ini < T) {
			pq.push({ ini, min(fin, T), periodo});
		}
	}

	bool conflicto = false;
	int fin_ultima;
	tarea siguiente;
	tarea top;

	if (!pq.empty()) {
		top = pq.top();
		fin_ultima = top.fin;
		pq.pop();
		if (top.periodo > 0 && top.ini + top.periodo < T)
			pq.push({ top.ini + top.periodo, min(top.fin + top.periodo, T), top.periodo });
	}

	while (!pq.empty() && !conflicto) {
		siguiente = pq.top();
		conflicto = siguiente.ini < fin_ultima;
		fin_ultima = siguiente.fin;
		pq.pop();
		if (siguiente.periodo > 0 && siguiente.ini + siguiente.periodo < T)
			pq.push({ siguiente.ini + siguiente.periodo, min(siguiente.fin + siguiente.periodo, T), siguiente.periodo });
	}

	if (conflicto)
		cout << "SI\n";
	else
		cout << "NO\n";
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}