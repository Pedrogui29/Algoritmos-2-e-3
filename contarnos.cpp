#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista)
{
	int no = 0;
	list<int>::iterator p;
	for(p = lista.begin(); p != lista.end(); p++)
		no++;

	return no;
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

	res = contar(lista) ;
	cout << res;



	return 0;
}
