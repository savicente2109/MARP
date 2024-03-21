#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool resuelveCaso() {

	int N;

	cin >> N;

	if (!std::cin) // fin de la entrada
		return false;

	priority_queue<int> menores;
	priority_queue<int, vector<int>, greater<int>> mayores;
	int mediano = -1, aux;

	for (int i = 0; i < N; ++i) {
		cin >> aux;
		if (aux == 0)
			if (mediano == -1)
				cout << "ECSA ";
			else {
				cout << mediano << ' ';
				if (mayores.size() == menores.size()) {
					if (mayores.empty())
						mediano = -1;
					else {
						mediano = menores.top();
						menores.pop();
					}
				}
				else {
					mediano = mayores.top();
					mayores.pop();
				}
			}
		else if (mediano == -1)
			mediano = aux;
		else if (aux < mediano)
			if (mayores.size() == menores.size()) {
				mayores.push(mediano);
				if (menores.empty() || aux > menores.top())
					mediano = aux;
				else {
					mediano = menores.top();
					menores.pop();
					menores.push(aux);
				}
			}
			else
				menores.push(aux);
		else
			if (mayores.size() == menores.size())
				mayores.push(aux);
			else {
				menores.push(mediano);
				if (mayores.empty() || aux < mayores.top())
					mediano = aux;
				else {
					mediano = mayores.top();
					mayores.pop();
					mayores.push(aux);
				}
			}
	}
	
	cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}