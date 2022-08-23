#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> estoque;//ponteiro p/ estoque
	list<int>::iterator p;//interador que varre o estoque
	list<int> venda;//ponteiro p/ venda
	list<int>::iterator v;//interador que varre a venda
	int x;//lista do elemento
	int y;//elemento p/ inserir
	int n;//quantidade de operações
	int i;//contador

	cin >> n;

	//Colocando elementos na lista
	for(i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 1)
		{
			cin >> y;
			estoque.push_back(y);//fila
		}
		else if( x == 2)
		{
			y = *estoque.begin();
			venda.push_front(y);//pilha
			estoque.pop_front();
		}

	}

	//Mostrando os elementos
	cout << "Estoque: ";
	for(p = estoque.begin(); p != estoque.end(); p++)
	{
		cout << *p << " ";
	}
	cout << endl;

	cout << "Venda: ";
	for(v = venda.begin(); v != venda.end(); v++)
	{
		cout << *v << " ";
	}
	cout << endl;

	return 0;
}


