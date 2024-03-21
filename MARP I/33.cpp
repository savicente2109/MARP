#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ii = pair<int, int>;

bool resuelveCaso() {
	
	int N;
	cin >> N;

	if (N == 0)
		return false;

	int horas, min, duracion, inicio;
	char aux;

	vector<ii> peliculas;

	for (int i = 0; i < N; ++i) {
		cin >> horas >> aux >> min >> duracion;
		inicio = horas * 60 + min;
		peliculas.push_back({ inicio + duracion, inicio });
	}

	sort(peliculas.begin(), peliculas.end());

	int final = peliculas[0].first, maraton = 1;

	for (int i = 1; i < N; ++i)
		if (peliculas[i].second >= final + 10) {
			final = peliculas[i].first;
			++maraton;
		}

	cout << maraton << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}