#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool resuelveCaso() {

	int p, n;

	cin >> p >> n;

	if (!std::cin) // fin de la entrada
		return false;

	priority_queue<pair<int, pair<int, int>>> pq;
	int aux;
	pair<int, pair<int, int>> top;

	for (int i = 0; i < n; ++i) {
		cin >> aux;
		pq.push({ aux, {aux, 1} });
	}

	for (int i = 0; i < p - n; ++i) {
		top = pq.top();
		++top.second.second;
		if (top.second.first % top.second.second == 0)
			top.first = top.second.first / top.second.second;
		else
			top.first = top.second.first / top.second.second + 1;
		pq.pop();
		pq.push(top);
	}

	cout << pq.top().first << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}