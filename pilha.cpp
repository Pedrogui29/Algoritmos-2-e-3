#include<iostream>
#include<list>

using namespace std;

int main()
{

	list<int> pilha; // ponteiro para a fila
	int p; // var aux para leitura dos dados
	int z;

	// Ler dados e inserir na fila

	cin >> z;
	pilha.push_front(z);
	cin >> z;
	pilha.push_front(z);
	cin >> z;
	pilha.push_front(z);
	cin >> z;
	pilha.push_front(z);

	// Remover os dados da fila e ir mostrando
	while(!pilha.empty())
	{
		p = *pilha.begin();
		cout << p << " ";
		pilha.pop_front();
	}
	return 0;
}
