#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 1000000000;

bool resuelveCaso() {
	
	int N, L;
	cin >> N >> L;

	if (!std::cin) // fin de la entrada
		return false;

	vector<int> l(N), c(N);

	for (int i = 0; i < N; ++i)
		cin >> l[i] >> c[i];

	vector<long long> mat(L + 1, 0);
	mat[0] = 1;

	for (int i = 1; i < N + 1; ++i)
		for (int j = L; j > 0; --j)
			if (l[i - 1] <= j)
				mat[j] += mat[j - l[i - 1]];

	if (mat[L] == 0) {
		cout << "NO\n";
		return true;
	}
		
	vector<int> ing(L + 1, INF), eco(L + 1, INF);
	ing[0] = 0;
	eco[0] = 0;

	for (int i = 1; i <= N; ++i)
		for (int j = L; j > 0; --j)
			if (l[i - 1] <= j) {
				ing[j] = min(ing[j], ing[j - l[i - 1]] + 1);
				eco[j] = min(eco[j], eco[j - l[i - 1]] + c[i - 1]);
			}

	cout << "SI " << mat[L] << ' ' << ing[L] << ' ' << eco[L] << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}