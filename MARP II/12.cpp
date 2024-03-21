#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool resuelveCaso() {
	int N;
	cin >> N;

	if (N == 0)
		return false;

	int D = 24 * 60;

	vector<int> ini(N + 1), d(N + 1), v(D + 1);
	vector<pair<int, int>> p(N + 1);

	int aux;
	char aux2;
	for (int i = 1; i <= N; ++i) {
		cin >> aux >> aux2 >> p[i].first >> p[i].second;
		p[i].first += 60 * aux;
	}

	sort(p.begin(), p.end());

	for (int i = 1; i <= N; ++i)
		for (int j = D; j > 0; --j)
			if (p[i].first + p[i].second <= j)
				if (p[i].first - 10 <= 0)
					v[j] = max(v[j], p[i].second);
				else
					v[j] = max(v[j], v[p[i].first - 10] + p[i].second);

	cout << v[D] << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}