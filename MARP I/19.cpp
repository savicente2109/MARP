#include <iostream>
#include <vector>
#include "Digrafo.h"

using namespace std;

pair <bool, int> sumidero(Digrafo const& d) {

	Digrafo inv = d.inverso();
	int N = d.V();

	for (int i = 0; i < N; ++i)
		if (d.ady(i).size() == 0 && inv.ady(i).size() == N - 1)
			return { true, i };

	return { false, -1 };
}

bool resuelveCaso() {
	
	Digrafo d(cin);

	if (!std::cin) // fin de la entrada
		return false;

	auto [tiene, sumid] = sumidero(d);

	if (tiene)
		cout << "SI " << sumid << '\n';
	else
		cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}