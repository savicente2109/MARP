#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool resuelveCaso() {

	int n;
	cin >> n;

	if (n == 0)
		return false;

	vector<int> rivales(n), broncos(n);

	for (int i = 0; i < n; ++i)
		cin >> rivales[i];

	for (int i = 0; i < n; ++i)
		cin >> broncos[i];

	sort(rivales.begin(), rivales.end());
	sort(broncos.begin(), broncos.end(), greater<int>());

	bool victorias = true;
	int puntos = 0;

	for (int i = 0; i < n && victorias; ++i)
		if (broncos[i] > rivales[i])
			puntos += broncos[i] - rivales[i];
		else
			victorias = false;
	
	cout << puntos << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}