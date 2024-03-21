#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool resuelveCaso() {

	int n;
	cin >> n;

	if (n == 0)
		return false;

	priority_queue<pair<pair<int, int>, string>> pq;
	string nombre;
	int gravedad;
	char evento;

	for (int i = 0; i < n; ++i) {
		cin.ignore();
		cin >> evento;
		if (evento == 'I') {
			cin >> nombre >> gravedad;
			pq.push({ {gravedad, n - i}, nombre });
		}
		else {
			auto a = pq.top();
			cout << a.second << '\n';
			pq.pop();
		}
	}

	cout << "---\n";

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}