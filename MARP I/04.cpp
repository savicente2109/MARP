#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ii = pair<int, int>;
using iii = pair<ii, int>;

bool resuelveCaso() {
	
	int N, K;

	cin >> N;

	if (N == 0)
		return false;

	priority_queue<iii, vector<iii>, greater<iii>> pq;
	int id, periodo;
	iii top;

	for (int i = 0; i < N; ++i) {
		cin >> id >> periodo;
		pq.push({ {periodo, id}, periodo });
	}

	cin >> K;

	for (int i = 0; i < K; ++i) {
		top = pq.top();
		cout << top.first.second << '\n';
		pq.pop();
		pq.push({ {top.first.first + top.second, top.first.second }, top.second });
	}
	
	cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}