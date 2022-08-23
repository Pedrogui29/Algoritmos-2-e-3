#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<float> lista, int x)
{
	list<float>::iterator p;
	int achou = 0;

	for(p = lista.begin(); p != lista.end(); p++)
	{
		if(x == *p)
			achou = 1;
	}

	if(achou == 0)
	{
		return false;
	}
	else if(achou == 1)
	{
		return true;
	}
}


int main()
{
	list<float> lista;//ponteiro para a lista
	int resultado;
	int numero;
	int pesquisa;

	cin >> numero;
	while(numero != 0)
	{
		lista.push_front(numero);
		cin >> numero;

	}

	cin >> pesquisa;



	resultado = encontrar(lista, pesquisa);

	if(resultado == true)
	{
		cout << "Encontrado" << endl;
	}
	else if(resultado == false)
	{
		cout << "Nao encontrado" << endl;
	}

	return 0;
}
