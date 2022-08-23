#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int encontrar(list<float> lista, int x)
{
	int achou;
	list<float>::iterator p;
	for(p = lista.begin(); p != lista.end(); p++)
	{
		if(x == *p)
		{
			achou = true;
		}
		else if(x != *p)
		{
			achou = false;
		}
	}
	return achou;
}

int main()
{
	list<float> lista;
	list<float>::iterator p;
	int x;
	int pesquisa;

	cin >> x;
	while(x != 0)
	{
		lista.push_front(x);
		cin >> x;

	}

	cin >> pesquisa;

	if (encontrar(lista) == true)
	{
		cout << "Encontrado" << endl;
	}
	else
	{
		cout << "Nao encontrado" << endl;
	}





	return 0;
}
