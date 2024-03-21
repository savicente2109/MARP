#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long int huffman(priority_queue<long long int, vector<long long int>, greater<long long int>> & pq, int N) {

	long long int esfuerzo = 0;

	for (int i = 0; i < N - 1; ++i) {
		long long int menor = pq.top();
		pq.pop();
		long long int segundo_menor = pq.top();
		pq.pop();
		esfuerzo += menor + segundo_menor;
		pq.push(menor + segundo_menor);
	}

	return esfuerzo;
}

bool resuelveCaso() {

	int N;
	cin >> N;

	if (N == 0)
		return false;

	priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
	long long int aux;

	for (int i = 0; i < N; ++i) {
		cin >> aux;
		pq.push(aux);
	}

	cout << huffman(pq, N) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}