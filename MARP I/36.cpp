#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct intervalo {
	int c;
	int f;
};

bool operator< (const intervalo& i1, const intervalo& i2) {
	return i1.c < i2.c || i1.c == i2.c && i1.f > i2.f;
}

bool resuelveCaso() {

	int C, F, N;
	cin >> C >> F >> N;

	if (C == 0 && F == 0 && N == 0)
		return false;

	vector<intervalo> v(N);
	int c, f;

	for (int i = 0; i < N; ++i) {
		cin >> c >> f;
		if (f > C && c < F)
			v[i] = { c, f };
	}

	sort(v.begin(), v.end());

	int fin = C, n = v.size(), fin_act = C, trabajos = 0;
	bool puede = n > 0;

	for (int i = 0; i < n - 1 && puede; ++i) {
		if (v[i].c <= fin_act) {
			fin = max(fin, v[i].f);
		}
		else if (v[i].c <= fin) {
			fin_act = fin;
			fin = max(fin, v[i].f);
			++trabajos;
		}
		else
			puede = false;
	}

	if (fin_act < F && puede) {
		if (v[n - 1].c <= fin_act) {
			fin = max(fin, v[n - 1].f);
			if (fin >= F)
				++trabajos;
			else
				puede = false;
		}
		else {
			if (fin >= F)
				++trabajos;
			else if (v[n - 1].c <= fin && v[n - 1].f >= F)
				trabajos += 2;
			else
				puede = false;
		}
	}

	if (puede)
		cout << trabajos << '\n';
	else
		cout << "Imposible\n";


	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}