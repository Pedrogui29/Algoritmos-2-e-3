#include<iostream>
#include<list>

using namespace std;

int main()
{

	list<int> fila; // ponteiro para a fila
	int p; // var aux para leitura dos dados
	int z;

	// Ler dados e inserir na fila

	cin >> z;
	fila.push_back(z);
	cin >> z;
	fila.push_back(z);
	cin >> z;
	fila.push_back(z);
	cin >> z;
	fila.push_back(z);

	// Remover os dados da fila e ir mostrando
	while(!fila.empty())
	{
		p = *fila.begin();
		cout << p << " ";
		fila.pop_front();
	}
	return 0;
}
