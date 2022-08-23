#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int soma(list<int> lista)
{
	int soma = 0;
	list<int>::iterator p;
	for(p = lista.begin(); p != lista.end(); p++)
	{
		soma += *p;
	}
    return soma;
}


int main()
{
	list<int> lista;
	list<int>::iterator p;
	int res;
	int x;

	cin >> x;
	while(x != 0)
	{
		lista.push_front(x);
		cin >> x;

	}

	res = soma(lista) ;
	cout << res;



	return 0;
}
