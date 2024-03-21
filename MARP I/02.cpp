#include <iostream>
#include <vector>
#include "TreeSet_AVL.h"

using namespace std;

bool resuelveCaso() {

	int N;
	cin >> N;

	if (N == 0)
		return false;

	Set<int> s;
	int elem, M, k;

	for (int i = 0; i < N; ++i) {
		cin >> elem;
		s.insert(elem);
	}

	cin >> M;

	for (int i = 0; i < M; ++i) {
		cin >> k;
		try {
			cout << s.kesimo(k) << '\n';
		}
		catch (out_of_range) {
			cout << "??\n";
		}
	}

	cout << "---\n";
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}