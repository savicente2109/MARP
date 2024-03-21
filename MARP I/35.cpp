#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
	
	int N;
	cin >> N;

	if (N == 0)
		return false;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; ++i)
		cin >> v[i].second >> v[i].first;

	sort(v.begin(), v.end());

	int ultimo = v[0].first, tuneles = 1;

	for (int i = 1; i < N; ++i)
		if (v[i].second >= ultimo) {
			ultimo = v[i].first;
			++tuneles;
		}

	cout << tuneles << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}